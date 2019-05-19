#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    parentIndex = model->setRootPath("E:/Libs");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int rowCount = model->rowCount(parentIndex);
    int colCount = model->columnCount(parentIndex);
    qDebug() << rowCount << colCount;

    QModelIndex index;
    QString data;
    for (int i = 0; i < rowCount; ++i)
    {
        index = model->index(i, 0, parentIndex);
        data = model->data(index, Qt::DisplayRole).toString();
        qDebug() << "Data item [" << QString::number(i) << "] " << data;
    }
}
