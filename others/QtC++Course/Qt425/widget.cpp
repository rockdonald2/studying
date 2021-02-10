#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked()
{
    ui->listWidget->addItem("newItem");
}

void Widget::on_deleteButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selectedButton_clicked()
{
    //get the list of selected items
    QList<QListWidgetItem*> selectedList = ui->listWidget->selectedItems();

    for (int i = 0; i < selectedList.size(); ++i)
        qDebug() << selectedList[i]->text() << ui->listWidget->row(selectedList[i]);
}
