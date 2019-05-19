#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*//string notation
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));*/

    /*//functor notation
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);*/

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](){
        ui->progressBar->setValue(ui->horizontalSlider->value());
    });
}

Widget::~Widget()
{
    delete ui;
}
