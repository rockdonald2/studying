#include <QApplication>
#include "rockwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RockWidget rw;
    rw.show();

    return a.exec();
}
