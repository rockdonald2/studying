#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>

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

void Widget::on_pushButton_clicked()
{
   /*QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);

    qDebug() << "Your selected dir is: " << dir;*/

    /*
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "Your selected file is: " << fileName;*/

    /*QStringList files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              "/home",
                              "Images (*.png *.xpm *.jpg);;Text files(*.txt)");
    qDebug() << "Your selected file are: " << files;*/

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                 "/home/jana/untitled.png",
                                 tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "Your saved file is: " << fileName;
}
