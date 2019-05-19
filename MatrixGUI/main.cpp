#include "matrixWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    matrixWidget w;
    w.show();

    return a.exec();
}
