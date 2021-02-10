#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //components for the first name
    QLabel* firstNameLabel = new QLabel("First name", this);
    firstNameLabel->setMinimumSize(70, 50);
    firstNameLabel->move(10, 10);

    QLineEdit* firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200, 50);
    firstNameLineEdit->move(100, 10);

    //components for the last name
    QLabel* lastNameLabel = new QLabel("Last name", this);
    lastNameLabel->setMinimumSize(70, 50);
    lastNameLabel->move(10, 80);

    QLineEdit* lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200, 50);
    lastNameLineEdit->move(100, 80);

    //components for the city
    QLabel* cityLabel = new QLabel("City", this);
    cityLabel->setMinimumSize(70, 50);
    cityLabel->move(10, 150);

    QLineEdit* cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200, 50);
    cityLineEdit->move(100, 150);

    firstNameLineEdit->setPlaceholderText("Write your first name");
    lastNameLineEdit->setPlaceholderText("Write your last name");
    cityLineEdit->setPlaceholderText("Write your city");

    QPushButton* button = new QPushButton("Submit", this);
    QFont font("Times", 12);
    button->setFont(font);
    button->move(100, 225);
    connect(button, &QPushButton::clicked, [=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << firstName << " " << lastName << " " << city;
        }
    });

    //respond to signals

    //cursor position changed
    connect(firstNameLineEdit, &QLineEdit::cursorPositionChanged, [=]() {
        qDebug() << "The current cursor position is: " << firstNameLineEdit->cursorPosition();
    });

    //editing finished
    connect(firstNameLineEdit, &QLineEdit::editingFinished, [=]() {
        qDebug() << "Editing finished";
    });

    //return pressed
    connect(firstNameLineEdit, &QLineEdit::returnPressed, [=](){
        qDebug() << "Return key pressed";
    });
}

Widget::~Widget()
{

}

QSize Widget::sizeHint() const
{
    return QSize(1024, 768);
}
