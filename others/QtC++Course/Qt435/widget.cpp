#include "widget.h"
#include "ui_widget.h"
#include "customdialog.h"

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

void Widget::on_clickMeButton_clicked()
{
    CustomDialog* dialog = new CustomDialog(this);

    dialog->setStyleSheet("QPushButton{background-color: yellow; color: green}");
    dialog->setStyle(QWidget::style());

    dialog->exec();
}
