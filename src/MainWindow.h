#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include "ui_DateSortWidget.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QString>

class QWidget;
class DateSortProcess;

class MainWindow : public QMainWindow, private Ui::DateSortWidget
{
	Q_OBJECT

	private slots:
		void exec();
		void openSearchDialog();
		void resetUi();

	public slots:
		void printProgressMessage(const QString &msg);
		void printErrorMessage(const QString &msg);

	private:
		QMessageBox* warnMsg;
		QMessageBox* infoMsg;
		QWidget* centralWidget;
		DateSortProcess* process;

		bool checkForm();
		static time_t getLastModified(QString& file);
		static bool setLastModified(QString& file, long timestamp);

	public:
		MainWindow(const QString &title);
};

#endif
