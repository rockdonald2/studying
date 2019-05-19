#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setText("Click me");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, [=](){
        //hard way
        /*QMessageBox message;
        message.setMinimumSize(300, 200);
        message.setWindowTitle("Message title");
        message.setText("Something happened, dunno");
        message.setInformativeText("Do you wanna do something about it?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int ret = message.exec();
           */

        //easy way, Critical message
        /*int ret = QMessageBox::critical(this, "Message title", "Something happened",
                                        QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);*/

        int ret = QMessageBox::information(this, "Message title", "Something happened",
                                                QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);
        if (ret == QMessageBox::Ok)
        {
            qDebug() << "user clicked on Ok";
        }
        if (ret == QMessageBox::Cancel)
        {
            qDebug() << "user clicked on Cancel";
        }
    });
}

Widget::~Widget()
{

}

QSize Widget::sizeHint() const
{
    return QSize(1024, 768);
}
