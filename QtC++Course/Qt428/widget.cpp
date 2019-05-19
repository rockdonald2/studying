#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#include "infodialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_provideInfoButton_clicked()
{
    infoDialog* dialog = new infoDialog(this);

    int ret = dialog->exec();

    if (ret == QDialog::Accepted)
    {
        QString os = dialog->getFavoriteOS();
        QString position = dialog->getPosition();

        qDebug() << "Dialog accepted" << position << os;
    }

    if (ret == QDialog::Rejected)
    {
        qDebug() << "Dialog rejected";
    }
}
