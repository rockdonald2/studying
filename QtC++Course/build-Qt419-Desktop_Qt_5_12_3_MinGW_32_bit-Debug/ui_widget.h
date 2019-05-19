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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        oneButton = new QPushButton(Widget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));
        oneButton->setGeometry(QRect(120, 60, 80, 21));
        twoButton = new QPushButton(Widget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));
        twoButton->setGeometry(QRect(120, 100, 80, 21));
        twoButton->setCursor(QCursor(Qt::SizeAllCursor));
        threeButton = new QPushButton(Widget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));
        threeButton->setGeometry(QRect(120, 140, 80, 21));
        fourButton = new QPushButton(Widget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));
        fourButton->setGeometry(QRect(120, 180, 80, 21));
        fiveButton = new QPushButton(Widget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));
        fiveButton->setGeometry(QRect(120, 210, 80, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        oneButton->setText(QApplication::translate("Widget", "One", nullptr));
        twoButton->setText(QApplication::translate("Widget", "Two", nullptr));
        threeButton->setText(QApplication::translate("Widget", "Three", nullptr));
        fourButton->setText(QApplication::translate("Widget", "Four", nullptr));
        fiveButton->setText(QApplication::translate("Widget", "Five", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
