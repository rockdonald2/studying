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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *disabledButton;
    QPushButton *activeButton;
    QLabel *myLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        disabledButton = new QPushButton(Widget);
        disabledButton->setObjectName(QString::fromUtf8("disabledButton"));
        disabledButton->setEnabled(false);

        verticalLayout->addWidget(disabledButton);

        activeButton = new QPushButton(Widget);
        activeButton->setObjectName(QString::fromUtf8("activeButton"));

        verticalLayout->addWidget(activeButton);

        myLabel = new QLabel(Widget);
        myLabel->setObjectName(QString::fromUtf8("myLabel"));
        QFont font;
        font.setPointSize(16);
        myLabel->setFont(font);

        verticalLayout->addWidget(myLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        disabledButton->setText(QApplication::translate("Widget", "Disabled", nullptr));
        activeButton->setText(QApplication::translate("Widget", "Active", nullptr));
        myLabel->setText(QApplication::translate("Widget", "My Label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
