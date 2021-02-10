#include "widget.h"
#include "ui_widget.h"
#include <QFontDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_chooseFontButton_clicked()
{
    bool ok;
      QFont font = QFontDialog::getFont(
                      &ok, QFont("Helvetica [Cronyx]", 10), this);
      if (ok) {
          ui->label->setFont(font);
          // the user clicked OK and font is set to the font the user selected
      } else {
          // the user canceled the dialog; font is set to the initial
          // value, in this case Helvetica [Cronyx], 10
        QMessageBox::information(this, "Message", "User didn't choose a font");
      }
}

//background
void Widget::on_pushButton_clicked()
{
    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::Window);

    QColor chosenColor = QColorDialog::getColor(color, this, "Choose color");

    if(chosenColor.isValid()){
        palette.setColor(QPalette::Window, chosenColor);
        ui->label->setPalette(palette);
        qDebug() << "The passed in color is valid";
    }
    else {
        qDebug() << "The passed in color is invalid";
    }
}

//text
void Widget::on_pushButton_2_clicked()
{
    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::WindowText);

    QColor chosenColor = QColorDialog::getColor(color, this, "Choose color");

    if(chosenColor.isValid()){
        palette.setColor(QPalette::WindowText, chosenColor);
        ui->label->setPalette(palette);
        qDebug() << "The passed in color is valid";
    }
    else {
        qDebug() << "The passed in color is invalid";
    }
}
