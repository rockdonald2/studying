#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> stringList;

    stringList << " I am " << " lovin " << " Qt";
    // [ " I am ", " lovin ", " Qt" ]
    stringList.append(" a ");
    stringList.append(" monkey rezervoir $");

    //get data from the list
    qDebug() << stringList[0];
    qDebug() << stringList[1];
    qDebug() << stringList[2];
    qDebug() << stringList[3];
    qDebug() << stringList[4];

    qDebug() << stringList.size();

    for (unsigned int i = 0; i < static_cast<unsigned int>(stringList.size()); ++i)
        qDebug() << stringList[static_cast<int>(i)];


    return a.exec();
}
