#include "MainWindow.h"
#include "DateSortProcess.h"

#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(const QString &title)
{
	this->warnMsg = new QMessageBox(this);
	this->warnMsg->setIcon(QMessageBox::Warning);
	this->infoMsg = new QMessageBox(this);
	this->infoMsg->setIcon(QMessageBox::Information);

	this->centralWidget = new QWidget(this);
	this->setupUi(this->centralWidget);

	this->setWindowTitle(title);
	this->setWindowIcon(QIcon(":/calendar.png"));
	this->setCentralWidget(this->centralWidget);
	this->setFixedSize(600, 400);

	QObject::connect(this->browseButton, SIGNAL(clicked()), this, SLOT(openSearchDialog()));
	QObject::connect(this->sortButton, SIGNAL(clicked()), this, SLOT(exec()));
}

void MainWindow::printProgressMessage(const QString &msg)
{
	this->console->insertPlainText(msg);
}

void MainWindow::printErrorMessage(const QString &msg)
{
	this->console->insertHtml("<font color=\"#ff0000\">" + msg + "</font>");
}

void MainWindow::resetUi()
{
	delete this->process;

	this->infoMsg->setWindowTitle("Information");
	this->infoMsg->setText("Dateien wurden erfolgreich sortiert!");
	this->infoMsg->exec();

	this->sortButton->setEnabled(true);
}

bool MainWindow::checkForm()
{
	if (this->dirField->text().isEmpty() || !QDir(this->dirField->text()).exists())
	{
		this->warnMsg->setWindowTitle("Eingabefehler");
		this->warnMsg->setText("Es wurde kein gueltiges Verzeichnis angegeben!");
		this->warnMsg->exec();
		this->dirField->setFocus();

		return false;
	}

	return true;
}

void MainWindow::openSearchDialog()
{
	QString path = QFileDialog::getExistingDirectory(
		this,
		"Suche Verzeichnis ...",
		this->dirField->text(),
		QFileDialog::ShowDirsOnly
	);
	if (!path.isEmpty())
		this->dirField->setText(path);
}

void MainWindow::exec()
{
	if (checkForm())
	{
		QDir* dir = new QDir(this->dirField->text()); // will be deleted by process
		this->process = new DateSortProcess(this, dir);

		QObject::connect(this->process, SIGNAL(finished()), this, SLOT(resetUi()));
		QObject::connect(this->process, SIGNAL(progressMessage(const QString&)), this, SLOT(printProgressMessage(const QString&)));
		QObject::connect(this->process, SIGNAL(errorMessage(const QString&)), this, SLOT(printErrorMessage(const QString&)));

		this->sortButton->setEnabled(false);
		this->console->clear();

		this->process->start();
	}
}
