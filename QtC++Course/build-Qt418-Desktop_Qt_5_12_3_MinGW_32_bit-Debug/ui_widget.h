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
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(835, 199);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        oneButton = new QPushButton(Widget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));

        horizontalLayout->addWidget(oneButton);

        twoButton = new QPushButton(Widget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));

        horizontalLayout->addWidget(twoButton);

        threeButton = new QPushButton(Widget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));

        horizontalLayout->addWidget(threeButton);

        fourButton = new QPushButton(Widget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));

        horizontalLayout->addWidget(fourButton);

        fiveButton = new QPushButton(Widget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));

        horizontalLayout->addWidget(fiveButton);


        horizontalLayout_2->addLayout(horizontalLayout);


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