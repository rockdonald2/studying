/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonOne;
    QPushButton *buttonTwo;
    QPushButton *buttonThree;
    QPushButton *buttonFour;
    QPushButton *buttonFive;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(897, 138);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 22, 771, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonOne = new QPushButton(widget);
        buttonOne->setObjectName(QString::fromUtf8("buttonOne"));

        horizontalLayout->addWidget(buttonOne);

        buttonTwo = new QPushButton(widget);
        buttonTwo->setObjectName(QString::fromUtf8("buttonTwo"));

        horizontalLayout->addWidget(buttonTwo);

        buttonThree = new QPushButton(widget);
        buttonThree->setObjectName(QString::fromUtf8("buttonThree"));

        horizontalLayout->addWidget(buttonThree);

        buttonFour = new QPushButton(widget);
        buttonFour->setObjectName(QString::fromUtf8("buttonFour"));

        horizontalLayout->addWidget(buttonFour);

        buttonFive = new QPushButton(widget);
        buttonFive->setObjectName(QString::fromUtf8("buttonFive"));

        horizontalLayout->addWidget(buttonFive);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        buttonOne->setText(QApplication::translate("Widget", "One", nullptr));
        buttonTwo->setText(QApplication::translate("Widget", "Two", nullptr));
        buttonThree->setText(QApplication::translate("Widget", "Three", nullptr));
        buttonFour->setText(QApplication::translate("Widget", "Four", nullptr));
        buttonFive->setText(QApplication::translate("Widget", "Five", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
