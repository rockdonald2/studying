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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *cheetosLabel;
    QLabel *imageLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        cheetosLabel = new QLabel(Widget);
        cheetosLabel->setObjectName(QString::fromUtf8("cheetosLabel"));
        cheetosLabel->setGeometry(QRect(80, 100, 171, 81));
        QFont font;
        font.setPointSize(16);
        cheetosLabel->setFont(font);
        cheetosLabel->setAlignment(Qt::AlignCenter);
        imageLabel = new QLabel(Widget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(140, 220, 131, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        cheetosLabel->setText(QApplication::translate("Widget", "Cheetos", nullptr));
        imageLabel->setText(QApplication::translate("Widget", "imagelabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
