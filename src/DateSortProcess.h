#ifndef _DATESORTPROCESS_
#define _DATESORTPROCESS_

#include <time.h>

#include <QThread>
#include <QStringList>

class QObject;
class QString;
class QWidget;
class QMessageBox;
class QDir;

class DateSortProcess : public QThread
{
	Q_OBJECT

	signals:
		void progressMessage(const QString &msg);
		void errorMessage(const QString &msg);

	private:
		QDir* dir;
		QStringList nameFilters;

		static time_t getLastModified(QString& file);
		static bool setLastModified(QString& file, time_t timestamp);

	public:
		DateSortProcess(QObject* parent, QDir* dir);
		~DateSortProcess();
		void run();
};

#endif
