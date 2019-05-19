#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

#include <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //retrieve the palette for the label
    QPalette myLabelPalette = ui->myLabel->palette();
    ui->myLabel->setAutoFillBackground(true);

    //modify the palette
    myLabelPalette.setColor(QPalette::Window, Qt::blue);
    myLabelPalette.setColor(QPalette::WindowText, Qt::red);

    //reset the palette to the original label
    ui->myLabel->setPalette(myLabelPalette);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disabledButtonColorGroup = ui->disabledButton->palette().currentColorGroup();

    qDebug() << "Active button color group is: " << activeButtonColorGroup;
    qDebug() << "Disabled button color group is: " << disabledButtonColorGroup;
}
