#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout* layout = new QGridLayout();

    //first row
    layout->addWidget(ui->pushButton, 0,0);
    layout->addWidget(ui->pushButton_2, 0,1);
    layout->addWidget(ui->pushButton_3, 0,2);

    //second row
    layout->addWidget(ui->pushButton_4, 1,0);
    layout->addWidget(ui->pushButton_5, 1,1);
    layout->addWidget(ui->pushButton_6, 1,2);

    //third row
    layout->addWidget(ui->pushButton_7, 2,0);
    layout->addWidget(ui->pushButton_8, 2,1);
    layout->addWidget(ui->pushButton_9, 2,2);

    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
