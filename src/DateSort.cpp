#include <QApplication>
#include <QString>

#include <MainWindow.h>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainWindow win(QString("DateSort 1.0b1"));
	win.show();
	return app.exec();
}

