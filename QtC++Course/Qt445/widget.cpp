#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel;

    //capture root item
    QStandardItem* rootItem = model->invisibleRootItem();

    //defining a couple of items;
    QStandardItem* africaItem = new QStandardItem("Africa");
    QStandardItem* rwandaItem = new QStandardItem("Rwanda");
    QStandardItem* kigaliItem= new QStandardItem("Kigali");
    QStandardItem* ugandaItem = new QStandardItem("Uganda");
    QStandardItem* chinaItem = new QStandardItem("China");
    QStandardItem* beijingItem = new QStandardItem("Beijing");

    //define the tree structure
    rootItem->appendRow(africaItem);
    africaItem->appendRow(rwandaItem);
    africaItem->appendRow(ugandaItem);
    rwandaItem->appendRow(kigaliItem);
    rootItem->appendRow(chinaItem);
    chinaItem->appendRow(beijingItem);

    //set the tree structure
    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    QItemSelectionModel* selectionModel = ui->treeView->selectionModel();
    connect (selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
             this, SLOT(selectionChangedSlot(QItemSelection, QItemSelection)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectionChangedSlot(const QItemSelection &oldSelection, const QItemSelection &newSelection)
{
    qDebug() << "Clicked on something in the tree";

    QModelIndex currentIndex = ui->treeView->selectionModel()->currentIndex();
    QString data = model->data(currentIndex, Qt::DisplayRole).toString();

    //find the hierarchy of the selected item
    int hierarchy = 1;
    QModelIndex seekRoot = currentIndex;

    while (seekRoot != QModelIndex())
    {
        seekRoot = seekRoot.parent();
        hierarchy++;
    }

    QString dataToShow = QString("%1, level %2").arg(data).arg(QString::number(hierarchy));
    setWindowTitle(dataToShow);
}
