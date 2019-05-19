#include "widget.h"
#include "ui_widget.h"
#include <QComboBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Mercur");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Pluto, is not a real planet, LMFAO");

    //make the combox box editable
    ui->comboBox->setEditable(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureButton_clicked()
{
    qDebug() << ui->comboBox->currentText();
    qDebug() << QString::number(ui->comboBox->currentIndex());
}

void Widget::on_setButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}

void Widget::on_getButton_clicked()
{
    qDebug() << QString::number(ui->comboBox->count());

    for (int i = 0; i < ui->comboBox->count(); ++i)
    {
        qDebug() << QString::number(i) << " : " << ui->comboBox->itemText(i);
    }
}
