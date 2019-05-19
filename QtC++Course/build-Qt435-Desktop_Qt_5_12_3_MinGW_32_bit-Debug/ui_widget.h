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
    QPushButton *clickMeButton;
    QLabel *uiTextLabel;
    QLabel *codeTextLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clickMeButton = new QPushButton(Widget);
        clickMeButton->setObjectName(QString::fromUtf8("clickMeButton"));

        verticalLayout->addWidget(clickMeButton);

        uiTextLabel = new QLabel(Widget);
        uiTextLabel->setObjectName(QString::fromUtf8("uiTextLabel"));
        QFont font;
        font.setPointSize(14);
        uiTextLabel->setFont(font);
        uiTextLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 85, 0);"));

        verticalLayout->addWidget(uiTextLabel);

        codeTextLabel = new QLabel(Widget);
        codeTextLabel->setObjectName(QString::fromUtf8("codeTextLabel"));
        codeTextLabel->setFont(font);

        verticalLayout->addWidget(codeTextLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        clickMeButton->setText(QApplication::translate("Widget", "Click me", nullptr));
        uiTextLabel->setText(QApplication::translate("Widget", "UiText", nullptr));
        codeTextLabel->setText(QApplication::translate("Widget", "CodeText", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
