#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialize
    srand (static_cast<unsigned int>(time(nullptr)));

    //generate
    secretNumber = rand() % 10 + 1;
    qDebug() << "Secret number generated: " << QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "Guessnumber is: " << QString::number(guessNumber);

    if (guessNumber == secretNumber) {
         ui->messageLabel->setText("Congratulations, the number was: " + QString::number(secretNumber));

         //disable button
         ui->guessButton->setDisabled(true);
         ui->startOverButton->setDisabled(false);
    }
    else {
        if (secretNumber < guessNumber) {
            ui->messageLabel->setText("Number is lower than that.");
        }
        if (secretNumber > guessNumber) {
            ui->messageLabel->setText("Number is higher than that.");
        }
    }
}

void MainWindow::on_startOverButton_clicked()
{
    //enable the guess button
    ui->guessButton->setDisabled(false);

    //disable the start over button
    ui->startOverButton->setDisabled(true);

    //put the spinbox back to 1
    ui->spinBox->setValue(1);

    //regenerate the random number
    secretNumber = rand() % 10 + 1;

    //clear message label
    ui->messageLabel->setText("");
}
