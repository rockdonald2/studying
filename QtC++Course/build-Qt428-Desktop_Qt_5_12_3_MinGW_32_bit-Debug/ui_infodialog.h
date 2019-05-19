/********************************************************************************
** Form generated from reading UI file 'infodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infoDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *positionLineEdit;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *windowsButton;
    QRadioButton *macButton;
    QRadioButton *linuxButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *infoDialog)
    {
        if (infoDialog->objectName().isEmpty())
            infoDialog->setObjectName(QString::fromUtf8("infoDialog"));
        infoDialog->resize(331, 314);
        verticalLayout_3 = new QVBoxLayout(infoDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(infoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(infoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        positionLineEdit = new QLineEdit(infoDialog);
        positionLineEdit->setObjectName(QString::fromUtf8("positionLineEdit"));

        verticalLayout_2->addWidget(positionLineEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(infoDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 70, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        windowsButton = new QRadioButton(widget);
        windowsButton->setObjectName(QString::fromUtf8("windowsButton"));

        verticalLayout->addWidget(windowsButton);

        macButton = new QRadioButton(widget);
        macButton->setObjectName(QString::fromUtf8("macButton"));

        verticalLayout->addWidget(macButton);

        linuxButton = new QRadioButton(widget);
        linuxButton->setObjectName(QString::fromUtf8("linuxButton"));

        verticalLayout->addWidget(linuxButton);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(infoDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);

        cancelButton = new QPushButton(infoDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(infoDialog);

        QMetaObject::connectSlotsByName(infoDialog);
    } // setupUi

    void retranslateUi(QDialog *infoDialog)
    {
        infoDialog->setWindowTitle(QApplication::translate("infoDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("infoDialog", "Your information", nullptr));
        label_2->setText(QApplication::translate("infoDialog", "Position :", nullptr));
        groupBox->setTitle(QApplication::translate("infoDialog", "Favorite OS", nullptr));
        windowsButton->setText(QApplication::translate("infoDialog", "Windows", nullptr));
        macButton->setText(QApplication::translate("infoDialog", "Mac", nullptr));
        linuxButton->setText(QApplication::translate("infoDialog", "Linux", nullptr));
        okButton->setText(QApplication::translate("infoDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("infoDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoDialog: public Ui_infoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
