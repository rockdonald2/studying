#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->cheetosLabel->move(100, 30);

    //add an image to the second label
    QPixmap cheetosPixmap("://download.jpg");
    ui->imageLabel->setPixmap(cheetosPixmap.scaled(250, 250));
    ui->imageLabel->move(0, 70);
    ui->imageLabel->setMinimumSize(500, 500);
}

Widget::~Widget()
{
    delete ui;
}
