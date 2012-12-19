#include <QApplication>
#include "sodamachine.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    SodaMachine w;
	w.show();
	return a.exec();
}
