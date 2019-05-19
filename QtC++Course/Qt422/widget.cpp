#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup* group = new QButtonGroup(this);

    group->addButton(ui->checkBox);
    group->addButton(ui->checkBox_2);
    group->addButton(ui->checkBox_3);

    group->setExclusive(true);

    QButtonGroup* group2 = new QButtonGroup(this);

    group2->addButton(ui->checkBox_4);
    group2->addButton(ui->checkBox_5);
    group2->addButton(ui->checkBox_6);

    group2->setExclusive(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_4_toggled(bool checked)
{
    if (checked)
        qDebug() << "Checkbox is toggled";
    else {
        qDebug() << "Checkbox is released";
    }
}

void Widget::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked())
    {
        qDebug() << "Grabbing input";
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked())
        ui->checkBox->setChecked(false);
    else {
        ui->checkBox->setChecked(true);
    }
}
