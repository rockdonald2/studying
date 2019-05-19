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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *dirLineEdit;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *chooseButton;
    QPushButton *createButton;
    QPushButton *existenceButton;
    QPushButton *dirOrFileButton;
    QPushButton *contentsButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(635, 450);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dirLineEdit = new QLineEdit(Widget);
        dirLineEdit->setObjectName(QString::fromUtf8("dirLineEdit"));

        verticalLayout->addWidget(dirLineEdit);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chooseButton = new QPushButton(Widget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));

        verticalLayout_2->addWidget(chooseButton);

        createButton = new QPushButton(Widget);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        verticalLayout_2->addWidget(createButton);

        existenceButton = new QPushButton(Widget);
        existenceButton->setObjectName(QString::fromUtf8("existenceButton"));

        verticalLayout_2->addWidget(existenceButton);

        dirOrFileButton = new QPushButton(Widget);
        dirOrFileButton->setObjectName(QString::fromUtf8("dirOrFileButton"));

        verticalLayout_2->addWidget(dirOrFileButton);

        contentsButton = new QPushButton(Widget);
        contentsButton->setObjectName(QString::fromUtf8("contentsButton"));

        verticalLayout_2->addWidget(contentsButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        chooseButton->setText(QApplication::translate("Widget", "Choose Dir", nullptr));
        createButton->setText(QApplication::translate("Widget", "Create Dir", nullptr));
        existenceButton->setText(QApplication::translate("Widget", "Dir Exists", nullptr));
        dirOrFileButton->setText(QApplication::translate("Widget", "Dir Or File", nullptr));
        contentsButton->setText(QApplication::translate("Widget", "Folder Contents", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
