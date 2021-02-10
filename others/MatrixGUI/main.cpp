#include "matrixWidget.h"
#include <QApplication>

#include <QFile>
#include <QStyle>
#include <QTextStream>

// simple function to read data from a file
QString readFromFile(QString filePath)
{
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    matrixWidget w;
    w.show();

    QString css = readFromFile(":/style/style.css");

    if (css.length() > 0)
        w.setStyleSheet(css);

    return a.exec();
}
