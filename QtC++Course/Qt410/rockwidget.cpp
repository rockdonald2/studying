#include "rockwidget.h"
#include <QLabel>
#include <QFont>
#include <QPalette>
#include <QPushButton>
#include <QMessageBox>

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("RockWidget");

    //add label
    QLabel* label = new QLabel("This is my label", this);

    //add a styled, slightly moved label
    QLabel* label1 = new QLabel(this);
    label1->setText("My colored label");
    label1->move(50, 50);
    QFont font("Times", 20, QFont::Bold);
    QPalette color;
    color.setColor(QPalette::Window, Qt::yellow);
    color.setColor(QPalette::WindowText, Qt::green);
    label1->setFont(font);
    label1->setPalette(color);
    label1->setAutoFillBackground(true);

    //add a button and connect to slot
    QPushButton* button = new QPushButton(this);
    button->setText("Click me");
    button->setFont(font);
    button->move(100, 250);

    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500, 500);
}
