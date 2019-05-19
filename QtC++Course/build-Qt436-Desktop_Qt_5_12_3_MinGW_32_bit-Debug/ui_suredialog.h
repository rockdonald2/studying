/********************************************************************************
** Form generated from reading UI file 'suredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUREDIALOG_H
#define UI_SUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SureDialog)
    {
        if (SureDialog->objectName().isEmpty())
            SureDialog->setObjectName(QString::fromUtf8("SureDialog"));
        SureDialog->resize(400, 183);
        verticalLayout = new QVBoxLayout(SureDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SureDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(379, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SureDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SureDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SureDialog);

        QMetaObject::connectSlotsByName(SureDialog);
    } // setupUi

    void retranslateUi(QDialog *SureDialog)
    {
        SureDialog->setWindowTitle(QApplication::translate("SureDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SureDialog", "Are you sure?", nullptr));
        okButton->setText(QApplication::translate("SureDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("SureDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SureDialog: public Ui_SureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUREDIALOG_H
