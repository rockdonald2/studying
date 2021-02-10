#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QFile>

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

void Widget::on_chooseButton_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this, "Choose Directory");

    if (fileName.isEmpty())
    {
        return;
    }

    ui->dirLineEdit->setText(fileName);
}

void Widget::on_createButton_clicked()
{
    //create a dir if it doesn't exists already

    QString dirPath = ui->dirLineEdit->text();
    if (dirPath.isEmpty())
    {
        return;
    }

    QDir dir(dirPath);
    if (!dir.exists())
    {
        //create it
        if (dir.mkpath(dirPath))
        {
            QMessageBox::information(this, "Message", "Directory created");
        }
        else {
            QMessageBox::information(this, "Message", "Directory creation failed");
        }
    }
    else
    {
        QMessageBox::information(this, "Message", "Directory already exists");
    }
}

void Widget::on_existenceButton_clicked()
{
    QString dirPath = ui->dirLineEdit->text();

    if (dirPath.isEmpty())
    {
        return;
    }

    QDir dir(dirPath);

    if (dir.exists())
    {
        QMessageBox::information(this, "Message", "Directory exists");
    }
    else
    {
        QMessageBox::information(this, "Message", "Directory doesn't exists");
    }
}

void Widget::on_dirOrFileButton_clicked()
{
   QFileInfo fileInfo(ui->listWidget->currentItem()->text());
   if (fileInfo.isDir())
   {
       QMessageBox::information(this, "Message", "This is a DIR");
   }
   if (fileInfo.isFile())
   {
       QMessageBox::information(this, "Message", "This is a FILE");
   }
}

void Widget::on_contentsButton_clicked()
{
    ui->listWidget->clear();

    QString dirPath = ui->dirLineEdit->text();

    if (dirPath.isEmpty())
    {
        return;
    }

    QDir dir(dirPath);

    //get the list of files and directories on the location

    QList<QFileInfo> fileList(dir.entryInfoList());

    for (int i = 0; i < fileList.size(); ++i)
    {
        QString prefix; // file or directory

        if (fileList.at(i).isFile())
        {
            prefix = "FILE ";
        }
        if (fileList.at(i).isDir())
        {
            prefix = "DIR ";
        }
        ui->listWidget->addItem(prefix + fileList.at(i).absoluteFilePath());
    }
}
