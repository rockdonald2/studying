#include "matrixWidget.h"
#include "ui_matrixWidget.h"

#include <QMessageBox>
#include <QDebug>

using namespace standardMatrix;

matrixWidget::matrixWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matrixWidget)
{
    ui->setupUi(this);

    // initial setup, C matrix is always Read-Only, because it displays just the result
    ui->numC1->setReadOnly(true);
    ui->numC2->setReadOnly(true);
    ui->numC3->setReadOnly(true);
    ui->numC4->setReadOnly(true);
    ui->numC5->setReadOnly(true);
    ui->numC6->setReadOnly(true);
    ui->numC7->setReadOnly(true);
    ui->numC8->setReadOnly(true);
    ui->numC9->setReadOnly(true);

    // default matrix is 3by3
    ui->plusButton->setDisabled(true);
}

matrixWidget::~matrixWidget()
{
    delete ui;
}

void matrixWidget::on_addButton_clicked()
{
    if (AMatrix3by3IsModified() && BMatrix3by3IsModified())
    {
        // checking whether it is 2by2 or 3by3, and set accordingly
        checkExtremistSlot();
        // get the data
        getData();

        // do the addition
        C = A + B;
        // print the result
        setData();

        return;
    }

    // check the 2by2 slots to be modified, and ensure the 3by3 slots not to be modified
    if (AMatrix2by2IsModified() && BMatrix2by2IsModified())
    {
        if (!anyExtremistSlotModified())
        {
            // checking whether it is 2by2 or 3by3, and set accordingly
            checkExtremistSlot();
            // get the data
            getData();

            // do the addition
            C = A + B;
            // print the result
            setData();


            return;
        }

        QMessageBox::information(this, "Message", "There are empty slots");
        return;
    }

    QMessageBox::information(this, "Message", "There are empty slots");
}

void matrixWidget::on_subtButton_clicked()
{
    /*// checking whether it is 2by2 or 3by3, and set accordingly
    checkExtremistSlot();
    // get the data
    getData();

    // additional security
    if (!AMatrix2by2IsModified() || !BMatrix2by2IsModified())
    {
        QMessageBox::information(this, "Message", "There are empty slots");
    }
    else {
        // do the addition
        C = A - B;
        // print the result
        setData();
    }*/

    if (AMatrix3by3IsModified() && BMatrix3by3IsModified())
    {
        // checking whether it is 2by2 or 3by3, and set accordingly
        checkExtremistSlot();
        // get the data
        getData();

        // do the addition
        C = A - B;
        // print the result
        setData();

        return;
    }

    if (AMatrix2by2IsModified() && BMatrix2by2IsModified())
    {
        if (!anyExtremistSlotModified())
        {
            // checking whether it is 2by2 or 3by3, and set accordingly
            checkExtremistSlot();
            // get the data
            getData();

            // do the addition
            C = A - B;
            // print the result
            setData();

            return;
        }

        QMessageBox::information(this, "Message", "There are empty slots");
        return;
    }

    QMessageBox::information(this, "Message", "There are empty slots");
}

void matrixWidget::on_multButton_clicked()
{
    if (AMatrix3by3IsModified() && BMatrix3by3IsModified())
    {
        // checking whether it is 2by2 or 3by3, and set accordingly
        checkExtremistSlot();
        // get the data
        getData();

        // do the multiplication
        C = A * B;
        // print the result
        setData();

        return;
    }

    if (AMatrix2by2IsModified() && BMatrix2by2IsModified())
    {
        if (!anyExtremistSlotModified())
        {
            // checking whether it is 2by2 or 3by3, and set accordingly
            checkExtremistSlot();
            // get the data
            getData();

            // do the multiplication
            C = A * B;
            // print the result
            setData();

            return;
        }

        QMessageBox::information(this, "Message", "There are empty slots");
        return;
    }

    QMessageBox::information(this, "Message", "There are empty slots");
}

void matrixWidget::on_numMultButton_clicked()
{
    if (AMatrix3by3IsModified())
    {
        // checking whether it is 2by2 or 3by3, and set accordingly
        checkExtremistSlot();
        // get the data
        getData();

        // do the multiplication
        C = A * ui->nValue->text().toInt();
        // print the result
        setData();

        return;
    }

    if (AMatrix2by2IsModified())
    {
        if (!anyExtremistSlotModified())
        {
            // checking whether it is 2by2 or 3by3, and set accordingly
            checkExtremistSlot();
            // get the data
            getData();

            // do the multiplication
            C = A * ui->nValue->text().toInt();
            // print the result
            setData();

            return;
        }

        QMessageBox::information(this, "Message", "There are empty slots");
        return;
    }

    QMessageBox::information(this, "Message", "There are empty slots");
}

void matrixWidget::reset2by2()
{
    // clear matrices
    A.clear();
    B.clear();
    C.clear();

    //set matrix
    is2by2 = true;
    is3by3 = false;

    A.resize(4);
    B.resize(4);
    C.resize(4);

    A.setRows(2).setColumns(2);
    B.setRows(2).setColumns(2);
    C.setRows(2).setColumns(2);
}

void matrixWidget::reset3by3()
{
    // clear matrices
    A.clear();
    B.clear();
    C.clear();

    //set matrix
    is2by2 = false;
    is3by3 = true;

    A.resize(9);
    B.resize(9);
    C.resize(9);

    A.setRows(3).setColumns(3);
    B.setRows(3).setColumns(3);
    C.setRows(3).setColumns(3);
}

void matrixWidget::on_plusButton_clicked()
{
    ui->plusButton->setDisabled(true);
    ui->minusButton->setDisabled(false);

    ui->numA3->setHidden(false);
    ui->numA6->setHidden(false);
    ui->numA9->setHidden(false);
    ui->numA7->setHidden(false);
    ui->numA8->setHidden(false);

    ui->numA4->setPlaceholderText("4");
    ui->numA5->setPlaceholderText("5");

    ui->numB3->setHidden(false);
    ui->numB6->setHidden(false);
    ui->numB9->setHidden(false);
    ui->numB7->setHidden(false);
    ui->numB8->setHidden(false);

    ui->numB4->setPlaceholderText("4");
    ui->numB5->setPlaceholderText("5");

    ui->numC3->setHidden(false);
    ui->numC6->setHidden(false);
    ui->numC9->setHidden(false);
    ui->numC7->setHidden(false);
    ui->numC8->setHidden(false);

    //reset3by3();
}

void matrixWidget::on_minusButton_clicked()
{
    ui->plusButton->setDisabled(false);
    ui->minusButton->setDisabled(true);

    ui->numA3->setHidden(true);
    ui->numA3->clear();
    ui->numA6->setHidden(true);
    ui->numA6->clear();
    ui->numA9->setHidden(true);
    ui->numA9->clear();
    ui->numA7->setHidden(true);
    ui->numA7->clear();
    ui->numA8->setHidden(true);
    ui->numA8->clear();

    ui->numA4->setPlaceholderText("3");
    ui->numA5->setPlaceholderText("4");

    ui->numB3->setHidden(true);
    ui->numB3->clear();
    ui->numB6->setHidden(true);
    ui->numB6->clear();
    ui->numB9->setHidden(true);
    ui->numB9->clear();
    ui->numB7->setHidden(true);
    ui->numB7->clear();
    ui->numB8->setHidden(true);
    ui->numB8->clear();

    ui->numB4->setPlaceholderText("3");
    ui->numB5->setPlaceholderText("4");

    ui->numC3->setHidden(true);
    ui->numC6->setHidden(true);
    ui->numC9->setHidden(true);
    ui->numC7->setHidden(true);
    ui->numC8->setHidden(true);

    //reset2by2();
}

bool matrixWidget::extremistSlotEmpty()
{
    if (!(ui->numA3->isModified() && ui->numA6->isModified() && ui->numA9->isModified() && ui->numA8->isModified() &&
          ui->numA7->isModified()) || !(ui->numB3->isModified() && ui->numB6->isModified() && ui->numB9->isModified() &&
                                        ui->numB8->isModified() && ui->numB7->isModified()))
    {
        return true;
    }
    else {
        return false;
    }
}

void matrixWidget::checkExtremistSlot()
{
    if(extremistSlotEmpty()) // if the third element in the first row is empty then it is a 2by2 matrix
    {
        is2by2 = true;
        is3by3 = false;

        A.resize(4);
        B.resize(4);
        C.resize(4);

        A.setRows(2).setColumns(2);
        B.setRows(2).setColumns(2);
        C.setRows(2).setColumns(2);
    } // if 3by3 then do nothing, the default is just fine
    else {
        is2by2 = false;
        is3by3 = true;

        A.resize(9);
        B.resize(9);
        C.resize(9);

        A.setRows(3).setColumns(3);
        B.setRows(3).setColumns(3);
        C.setRows(3).setColumns(3);
    }
}

bool matrixWidget::AMatrix2by2IsModified()
{
    if (ui->numA1->isModified() && ui->numA2->isModified()
            && ui->numA4->isModified() && ui->numA5->isModified())
    {
       return true;
    }
    else {
        return false;
    }
}

bool matrixWidget::BMatrix2by2IsModified()
{
    if (ui->numB1->isModified() && ui->numB2->isModified()
            && ui->numB4->isModified() && ui->numB5->isModified())
    {
        return true;
    }
    else {
        return false;
    }
}

bool matrixWidget::AMatrix3by3IsModified()
{
    if (ui->numA1->isModified() && ui->numA2->isModified() && ui->numA3->isModified()
            && ui->numA4->isModified() && ui->numA5->isModified() && ui->numA6->isModified()
            && ui->numA7->isModified() && ui->numA8->isModified() && ui->numA9->isModified())
    {
        return true;
    }
    else {
        return false;
    }
}

bool matrixWidget::BMatrix3by3IsModified()
{
    if (ui->numB1->isModified() && ui->numB2->isModified() && ui->numB3->isModified()
            && ui->numB4->isModified() && ui->numB5->isModified() && ui->numB6->isModified()
            && ui->numB7->isModified() && ui->numB8->isModified() && ui->numB9->isModified())
    {
        return true;
    }
    else {
        return false;
    }
}

bool matrixWidget::anyExtremistSlotModified()
{
    if ((ui->numA3->isModified() || ui->numA6->isModified() || ui->numA9->isModified() || ui->numA8->isModified() ||
          ui->numA7->isModified()) || (ui->numB3->isModified() || ui->numB6->isModified() || ui->numB9->isModified() ||
                                        ui->numB8->isModified() || ui->numB7->isModified()))
    {
        return true;
    }
    else {
        return false;
    }
}

void matrixWidget::getData()
{
    if (is2by2 && AMatrix2by2IsModified())
    {
        A.assign(0, 0, ui->numA1->text().toInt());
        A.assign(0, 1, ui->numA2->text().toInt());
        A.assign(1, 0, ui->numA4->text().toInt());
        A.assign(1, 1, ui->numA5->text().toInt());

        if (BMatrix2by2IsModified())
        {
            B.assign(0, 0, ui->numB1->text().toInt());
            B.assign(0, 1, ui->numB2->text().toInt());
            B.assign(1, 0, ui->numB4->text().toInt());
            B.assign(1, 1, ui->numB5->text().toInt());
        }
    }
    else if (is3by3 && AMatrix3by3IsModified())
    {
        A.assign(0, 0, ui->numA1->text().toInt());
        A.assign(0, 1, ui->numA2->text().toInt());
        A.assign(0, 2, ui->numA3->text().toInt());
        A.assign(1, 0, ui->numA4->text().toInt());
        A.assign(1, 1, ui->numA5->text().toInt());
        A.assign(1, 2, ui->numA6->text().toInt());
        A.assign(2, 0, ui->numA7->text().toInt());
        A.assign(2, 1, ui->numA8->text().toInt());
        A.assign(2, 2, ui->numA9->text().toInt());

        if (BMatrix3by3IsModified())
        {
            B.assign(0, 0, ui->numB1->text().toInt());
            B.assign(0, 1, ui->numB2->text().toInt());
            B.assign(0, 2, ui->numB3->text().toInt());
            B.assign(1, 0, ui->numB4->text().toInt());
            B.assign(1, 1, ui->numB5->text().toInt());
            B.assign(1, 2, ui->numB6->text().toInt());
            B.assign(2, 0, ui->numB7->text().toInt());
            B.assign(2, 1, ui->numB8->text().toInt());
            B.assign(2, 2, ui->numB9->text().toInt());
        }
    }
    else {
        QMessageBox::information(this, "Message", "There are empty slots");
    }
}

void matrixWidget::setData()
{
    if (is2by2)
    {
        ui->numC1->setText(QString::fromStdString(C.toString(0, 0)));
        ui->numC2->setText(QString::fromStdString(C.toString(0, 1)));
        ui->numC4->setText(QString::fromStdString(C.toString(1, 0)));
        ui->numC5->setText(QString::fromStdString(C.toString(1, 1)));
    }
    else if (is3by3) {
        ui->numC1->setText(QString::fromStdString(C.toString(0, 0)));
        ui->numC2->setText(QString::fromStdString(C.toString(0, 1)));
        ui->numC3->setText(QString::fromStdString(C.toString(0, 2)));
        ui->numC4->setText(QString::fromStdString(C.toString(1, 0)));
        ui->numC5->setText(QString::fromStdString(C.toString(1, 1)));
        ui->numC6->setText(QString::fromStdString(C.toString(1, 2)));
        ui->numC7->setText(QString::fromStdString(C.toString(2, 0)));
        ui->numC8->setText(QString::fromStdString(C.toString(2, 1)));
        ui->numC9->setText(QString::fromStdString(C.toString(2, 2)));
    }
    else {
        QMessageBox::information(this, "Error", "An error occurred");
    }
}
