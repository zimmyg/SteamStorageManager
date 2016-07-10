#include "ssm.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ssm w;
	w.show();
	return a.exec();
}
