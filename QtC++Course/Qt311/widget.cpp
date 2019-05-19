#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*//string notation
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeText()));*/

    /*//Functor Notation : regular slots
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::changeText);*/

    //Functor Notation : lambdas
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText("Lambda signal-slot stuff");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() << "User clicked on a button";
    ui->label->setText("You clicked on the button");
}
