#include "DateSortProcess.h"

#ifdef Q_WS_WIN
#include <Windows.h>
#include <ctime>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h>
#endif

#include <QDir>
#include <QThread>
#include <QString>
#include <QStringList>
#include <QByteArray>

#ifdef Q_WS_WIN
/**
 * From: http://support.microsoft.com/kb/167296/en
*/
void UnixTimeToFileTime(time_t t, LPFILETIME pft)
{
	LONGLONG ll; // Note that LONGLONG is a 64-bit value

	ll = Int32x32To64(t, 10000000) + 116444736000000000ull;
	pft->dwLowDateTime = (DWORD) ll;
	pft->dwHighDateTime = ll >> 32;
}

/**
 * From: http://www.openarchive.net/documentation/tech-doc/html/d3/da4/NtStat_8c.html#6d8380982d5504ac5972f74d233e3e5e
*/
void FileTimeToUnixTime(time_t *pt, FILETIME ft)
{
	LONGLONG ll;

	ll = (LONGLONG) ft.dwHighDateTime;
	ll <<= 32;
	ll +=  ft.dwLowDateTime;
	ll = (ll  - 116444736000000000ull);
	ll /= 10000000;
	*pt = (DWORD) ll;
}

HANDLE GetFileAttributeHandle(const char* lpFileName, bool readonly)
{
	return CreateFile(
		lpFileName,				// lpFileName
		readonly ? FILE_READ_ATTRIBUTES : FILE_WRITE_ATTRIBUTES,	// dwDesiredAccess
		0,						// dwShareMode
		NULL,					// lpSecurityAttributes
		OPEN_EXISTING,			// dwCreationDisposition,
		FILE_ATTRIBUTE_NORMAL,	// dwFlagsAndAttributes,
		NULL					// hTemplateFile
	);
}
#endif

DateSortProcess::DateSortProcess(QObject* parent, QDir* dir) : QThread(parent)
{
	this->dir = dir;

	this->nameFilters << "*.jpg" << "*.jpeg" << "*.png" << "*.tif" << "*.raw";
}

DateSortProcess::~DateSortProcess()
{
	delete this->dir;
}

/**
 * Synchronize date and alphabetical order of files.
*/
void DateSortProcess::run()
{
	if (this->dir->exists())
	{
		QStringList fileList = this->dir->entryList( // array with image files (JPG, PNG, TIF and RAW)
			this->nameFilters,
			QDir::Files | QDir::NoDotAndDotDot,
			QDir::Name
		);
		QString tmpFile;
		time_t now = time(NULL) - (60 * fileList.size()); // current timestamp in seconds - (file * 60 seconds)
		time_t oldTimestamp; // old timestamp of temporary file; needed for logging

		for (int i = 0; i < fileList.size(); i++) {
			tmpFile = this->dir->absolutePath() + QDir::separator() + fileList.at(i);
			oldTimestamp = getLastModified(tmpFile); // set old timestamp of temporary file

			// try to modify timestamp
			if (setLastModified(tmpFile, now))
				emit progressMessage(
					"File '" + fileList.at(i) + "': Changed timestamp from '" +
					QString::number(oldTimestamp) + "' to '" + QString::number(now) + "'.\n"
				);
			else
				emit errorMessage("File '" + fileList.at(i) + "': Couldn't change timestamp!</font><br />");

			now += 60; // add one minute to timestamp
		}
	}
}

time_t DateSortProcess::getLastModified(QString& file)
{
	#ifdef Q_WS_WIN
	HANDLE fh = GetFileAttributeHandle(file.toAscii().constData(), true);
	FILETIME lpLastWriteTime;
	time_t timestamp;

	if (fh == INVALID_HANDLE_VALUE)
		return 0; // cannot open file handle
	if (!GetFileTime(fh, NULL, NULL, &lpLastWriteTime))
	{
		CloseHandle(fh);
		return 0; // cannot fetch file time
	}
	FileTimeToUnixTime(&timestamp, lpLastWriteTime);
	CloseHandle(fh);

	return timestamp;

	#else
	struct stat attrib;	// create a file attribute structure
	stat(file.toAscii().constData(), &attrib); // get the attributes of the file
	return attrib.st_mtime;
	#endif
}

bool DateSortProcess::setLastModified(QString& file, time_t timestamp)
{
	#ifdef Q_WS_WIN
	HANDLE fh = GetFileAttributeHandle(file.toAscii().constData(), false);
	FILETIME lpLastWriteTime;
	const FILETIME* lpTime = (const FILETIME*) &lpLastWriteTime;

	if (fh == INVALID_HANDLE_VALUE)
		return false; // cannot open file handle
	UnixTimeToFileTime(timestamp, &lpLastWriteTime);
	if (!SetFileTime(fh, NULL, lpTime, lpTime))
	{
		CloseHandle(fh);
		return false; // cannot set file time
	}
	CloseHandle(fh);

	return true;

	#else
	struct utimbuf times;
	times.actime = times.modtime = timestamp;
	return utime(file.toAscii().constData(), &times) == 0;
	#endif
}
