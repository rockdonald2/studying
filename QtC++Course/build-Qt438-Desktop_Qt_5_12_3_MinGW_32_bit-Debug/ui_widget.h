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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *writeButton;
    QPushButton *readButton;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sourceLineEdit;
    QPushButton *selectFileButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *destinationLineEdit;
    QPushButton *copyButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        writeButton = new QPushButton(Widget);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));

        verticalLayout->addWidget(writeButton);

        readButton = new QPushButton(Widget);
        readButton->setObjectName(QString::fromUtf8("readButton"));

        verticalLayout->addWidget(readButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_3->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sourceLineEdit = new QLineEdit(Widget);
        sourceLineEdit->setObjectName(QString::fromUtf8("sourceLineEdit"));

        horizontalLayout->addWidget(sourceLineEdit);

        selectFileButton = new QPushButton(Widget);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));

        horizontalLayout->addWidget(selectFileButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        destinationLineEdit = new QLineEdit(Widget);
        destinationLineEdit->setObjectName(QString::fromUtf8("destinationLineEdit"));

        horizontalLayout_2->addWidget(destinationLineEdit);

        copyButton = new QPushButton(Widget);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        horizontalLayout_2->addWidget(copyButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        writeButton->setText(QApplication::translate("Widget", "Write", nullptr));
        readButton->setText(QApplication::translate("Widget", "Read", nullptr));
        selectFileButton->setText(QApplication::translate("Widget", "Select File", nullptr));
        copyButton->setText(QApplication::translate("Widget", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
