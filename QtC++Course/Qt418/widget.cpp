#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*//define layout, add things to the layout, and the set the layout
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(ui->oneButton);
    layout->addWidget(ui->twoButton);
    layout->addWidget(ui->threeButton);
    layout->addWidget(ui->fourButton);
    layout->addWidget(ui->fiveButton);

    setLayout(layout);*/
}

Widget::~Widget()
{
    delete ui;
}
