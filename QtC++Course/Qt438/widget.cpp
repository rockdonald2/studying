#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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

void Widget::on_writeButton_clicked()
{
    //save file to disk
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    if (fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void Widget::on_readButton_clicked()
{
   //read from file
    QString fileContent;

    QString fileName = QFileDialog::getOpenFileName(this, "Open File");

    if(fileName.isEmpty())
    {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();

    while(!line.isNull())
    {
        fileContent.append(line);
        line = in.readLine();
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileContent);
}

void Widget::on_selectFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose File");

    if (fileName.isEmpty())
    {
        return;
    }

    ui->sourceLineEdit->setText(fileName);
}

void Widget::on_copyButton_clicked()
{
    QString srcFileName = ui->sourceLineEdit->text();
    QString destFileName = ui->destinationLineEdit->text();

    if (srcFileName.isEmpty() || destFileName.isEmpty())
    {
        return;
    }

    QFile srcFile(srcFileName);
    if (srcFile.copy(destFileName))
    {
        QMessageBox::information(this, "Success", "Copy successful");
    }
    else {
        QMessageBox::information(this, "Failed", "Copy failed");
    }
}
