#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //clicked signal
    QPushButton* button = new QPushButton("Button", this);
    QFont font("Times", 12);
    button->setMinimumSize(200, 100);
    button->setFont(font);
    connect(button, &QPushButton::clicked, [=]() {
        qDebug() << "Button clicked";
    });

    QPushButton* buttonPressed = new QPushButton("ButtonPressed", this);
    buttonPressed->setMinimumSize(200, 100);
    buttonPressed->setFont(font);
    buttonPressed->move(205, 0);
    connect(buttonPressed, &QPushButton::pressed, [=]() {
        qDebug() << "Button pressed";
    });
    connect(buttonPressed, &QPushButton::released, [=]() {
        qDebug() << "Button released";
    });

}

Widget::~Widget()
{

}
