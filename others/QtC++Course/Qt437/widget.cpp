#include "widget.h"
#include "ui_widget.h"

#include <QColorDialog>
#include <QSettings>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    int numberOfColors(9);
    for (int i = 0; i < numberOfColors; ++i)
    {
        colorList.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[0] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton->setStyleSheet(css);
    }
}

void Widget::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[1] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_2->setStyleSheet(css);
    }
}

void Widget::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[2] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_3->setStyleSheet(css);
    }
}

void Widget::on_pushButton_4_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[3] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_4->setStyleSheet(css);
    }
}

void Widget::on_pushButton_5_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[4] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_5->setStyleSheet(css);
    }
}

void Widget::on_pushButton_6_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[5] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_6->setStyleSheet(css);
    }
}

void Widget::on_pushButton_7_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[6] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_7->setStyleSheet(css);
    }
}

void Widget::on_pushButton_8_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[7] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_8->setStyleSheet(css);
    }
}

void Widget::on_pushButton_9_clicked()
{
    QColor color = QColorDialog::getColor(colorList[0], this, "Choose color");
    if (color.isValid())
    {
        colorList[8] = color;

        QString css = QString("background-color: %1").arg(color.name());
        ui->pushButton_9->setStyleSheet(css);
    }
}

void Widget::on_loadColorsButton_clicked()
{
    setLoadedColor("pushButton", 0, ui->pushButton);
    setLoadedColor("pushButton_2", 1, ui->pushButton_2);
    setLoadedColor("pushButton_3", 2, ui->pushButton_3);
    setLoadedColor("pushButton_4", 3, ui->pushButton_4);
    setLoadedColor("pushButton_5", 4, ui->pushButton_5);
    setLoadedColor("pushButton_6", 5, ui->pushButton_6);
    setLoadedColor("pushButton_7", 6, ui->pushButton_7);
    setLoadedColor("pushButton_8", 7, ui->pushButton_8);
    setLoadedColor("pushButton_9", 8, ui->pushButton_9);
}

void Widget::on_saveColorButton_clicked()
{
    saveColor("pushButton", colorList[0]);
    saveColor("pushButton_2", colorList[1]);
    saveColor("pushButton_3", colorList[2]);
    saveColor("pushButton_4", colorList[3]);
    saveColor("pushButton_5", colorList[4]);
    saveColor("pushButton_6", colorList[5]);
    saveColor("pushButton_7", colorList[6]);
    saveColor("pushButton_8", colorList[7]);
    saveColor("pushButton_9", colorList[8]);
}

void Widget::saveColor(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("Blikoon", "Settings");
    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("Blikoon", "Settings");

    settings.beginGroup("ButtonColor");
    red = settings.value(key+"r", QVariant(0)).toInt();
    green = settings.value(key+"g", QVariant(0)).toInt();
    blue = settings.value(key+"b", QVariant(0)).toInt();
    settings.endGroup();

    return QColor(red, green, blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color = loadColor(key);
    colorList[index] = color;
    QString css = QString("background-color: %1").arg(color.name());
    button->setStyleSheet(css);
}
