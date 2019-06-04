/********************************************************************************
** Form generated from reading UI file 'matrixWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXWIDGET_H
#define UI_MATRIXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matrixWidget
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QGridLayout *gridLayout_6;
    QLineEdit *numC4;
    QLineEdit *numC2;
    QLineEdit *numC9;
    QLineEdit *numC3;
    QLineEdit *numC8;
    QLineEdit *numC5;
    QLineEdit *numC6;
    QLineEdit *numC1;
    QLineEdit *numC7;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *nValue;
    QPushButton *numMultButton;
    QPushButton *subtButton;
    QPushButton *multButton;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_3;
    QLineEdit *numA1;
    QLineEdit *numA8;
    QLineEdit *numA6;
    QLineEdit *numA4;
    QLineEdit *numA3;
    QLineEdit *numA5;
    QLineEdit *numA9;
    QLineEdit *numA2;
    QLineEdit *numA7;
    QGridLayout *gridLayout;
    QLineEdit *numB1;
    QLineEdit *numB2;
    QLineEdit *numB3;
    QLineEdit *numB4;
    QLineEdit *numB5;
    QLineEdit *numB6;
    QLineEdit *numB7;
    QLineEdit *numB8;
    QLineEdit *numB9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;

    void setupUi(QWidget *matrixWidget)
    {
        if (matrixWidget->objectName().isEmpty())
            matrixWidget->setObjectName(QString::fromUtf8("matrixWidget"));
        matrixWidget->resize(362, 431);
        gridLayout_2 = new QGridLayout(matrixWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_14 = new QLabel(matrixWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(52);
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_14);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        numC4 = new QLineEdit(matrixWidget);
        numC4->setObjectName(QString::fromUtf8("numC4"));

        gridLayout_6->addWidget(numC4, 1, 0, 1, 1);

        numC2 = new QLineEdit(matrixWidget);
        numC2->setObjectName(QString::fromUtf8("numC2"));

        gridLayout_6->addWidget(numC2, 0, 1, 1, 1);

        numC9 = new QLineEdit(matrixWidget);
        numC9->setObjectName(QString::fromUtf8("numC9"));

        gridLayout_6->addWidget(numC9, 3, 2, 1, 1);

        numC3 = new QLineEdit(matrixWidget);
        numC3->setObjectName(QString::fromUtf8("numC3"));

        gridLayout_6->addWidget(numC3, 0, 2, 1, 1);

        numC8 = new QLineEdit(matrixWidget);
        numC8->setObjectName(QString::fromUtf8("numC8"));

        gridLayout_6->addWidget(numC8, 3, 1, 1, 1);

        numC5 = new QLineEdit(matrixWidget);
        numC5->setObjectName(QString::fromUtf8("numC5"));

        gridLayout_6->addWidget(numC5, 1, 1, 1, 1);

        numC6 = new QLineEdit(matrixWidget);
        numC6->setObjectName(QString::fromUtf8("numC6"));

        gridLayout_6->addWidget(numC6, 1, 2, 1, 1);

        numC1 = new QLineEdit(matrixWidget);
        numC1->setObjectName(QString::fromUtf8("numC1"));

        gridLayout_6->addWidget(numC1, 0, 0, 1, 1);

        numC7 = new QLineEdit(matrixWidget);
        numC7->setObjectName(QString::fromUtf8("numC7"));

        gridLayout_6->addWidget(numC7, 3, 0, 1, 1);


        horizontalLayout_10->addLayout(gridLayout_6);


        horizontalLayout_11->addLayout(horizontalLayout_10);

        label_13 = new QLabel(matrixWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_13);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        gridLayout_2->addLayout(horizontalLayout_11, 3, 0, 1, 7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        plusButton = new QPushButton(matrixWidget);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));

        horizontalLayout_3->addWidget(plusButton);

        minusButton = new QPushButton(matrixWidget);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));

        horizontalLayout_3->addWidget(minusButton);


        verticalLayout->addLayout(horizontalLayout_3);

        addButton = new QPushButton(matrixWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(addButton);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        nValue = new QLineEdit(matrixWidget);
        nValue->setObjectName(QString::fromUtf8("nValue"));

        horizontalLayout_4->addWidget(nValue);

        numMultButton = new QPushButton(matrixWidget);
        numMultButton->setObjectName(QString::fromUtf8("numMultButton"));

        horizontalLayout_4->addWidget(numMultButton);


        verticalLayout->addLayout(horizontalLayout_4);

        subtButton = new QPushButton(matrixWidget);
        subtButton->setObjectName(QString::fromUtf8("subtButton"));
        sizePolicy1.setHeightForWidth(subtButton->sizePolicy().hasHeightForWidth());
        subtButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(subtButton);

        multButton = new QPushButton(matrixWidget);
        multButton->setObjectName(QString::fromUtf8("multButton"));
        sizePolicy1.setHeightForWidth(multButton->sizePolicy().hasHeightForWidth());
        multButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(multButton);


        horizontalLayout_7->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_7, 2, 0, 1, 7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        numA1 = new QLineEdit(matrixWidget);
        numA1->setObjectName(QString::fromUtf8("numA1"));

        gridLayout_3->addWidget(numA1, 0, 0, 1, 1);

        numA8 = new QLineEdit(matrixWidget);
        numA8->setObjectName(QString::fromUtf8("numA8"));

        gridLayout_3->addWidget(numA8, 3, 1, 1, 1);

        numA6 = new QLineEdit(matrixWidget);
        numA6->setObjectName(QString::fromUtf8("numA6"));

        gridLayout_3->addWidget(numA6, 2, 2, 1, 1);

        numA4 = new QLineEdit(matrixWidget);
        numA4->setObjectName(QString::fromUtf8("numA4"));

        gridLayout_3->addWidget(numA4, 2, 0, 1, 1);

        numA3 = new QLineEdit(matrixWidget);
        numA3->setObjectName(QString::fromUtf8("numA3"));

        gridLayout_3->addWidget(numA3, 0, 2, 1, 1);

        numA5 = new QLineEdit(matrixWidget);
        numA5->setObjectName(QString::fromUtf8("numA5"));

        gridLayout_3->addWidget(numA5, 2, 1, 1, 1);

        numA9 = new QLineEdit(matrixWidget);
        numA9->setObjectName(QString::fromUtf8("numA9"));

        gridLayout_3->addWidget(numA9, 3, 2, 1, 1);

        numA2 = new QLineEdit(matrixWidget);
        numA2->setObjectName(QString::fromUtf8("numA2"));

        gridLayout_3->addWidget(numA2, 0, 1, 1, 1);

        numA7 = new QLineEdit(matrixWidget);
        numA7->setObjectName(QString::fromUtf8("numA7"));

        gridLayout_3->addWidget(numA7, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        numB1 = new QLineEdit(matrixWidget);
        numB1->setObjectName(QString::fromUtf8("numB1"));

        gridLayout->addWidget(numB1, 0, 0, 1, 1);

        numB2 = new QLineEdit(matrixWidget);
        numB2->setObjectName(QString::fromUtf8("numB2"));

        gridLayout->addWidget(numB2, 0, 1, 1, 1);

        numB3 = new QLineEdit(matrixWidget);
        numB3->setObjectName(QString::fromUtf8("numB3"));

        gridLayout->addWidget(numB3, 0, 2, 1, 1);

        numB4 = new QLineEdit(matrixWidget);
        numB4->setObjectName(QString::fromUtf8("numB4"));

        gridLayout->addWidget(numB4, 1, 0, 1, 1);

        numB5 = new QLineEdit(matrixWidget);
        numB5->setObjectName(QString::fromUtf8("numB5"));

        gridLayout->addWidget(numB5, 1, 1, 1, 1);

        numB6 = new QLineEdit(matrixWidget);
        numB6->setObjectName(QString::fromUtf8("numB6"));

        gridLayout->addWidget(numB6, 1, 2, 1, 1);

        numB7 = new QLineEdit(matrixWidget);
        numB7->setObjectName(QString::fromUtf8("numB7"));

        gridLayout->addWidget(numB7, 2, 0, 1, 1);

        numB8 = new QLineEdit(matrixWidget);
        numB8->setObjectName(QString::fromUtf8("numB8"));

        gridLayout->addWidget(numB8, 2, 1, 1, 1);

        numB9 = new QLineEdit(matrixWidget);
        numB9->setObjectName(QString::fromUtf8("numB9"));

        gridLayout->addWidget(numB9, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 5, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(matrixWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(matrixWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 2, 1, 4);

        label_4 = new QLabel(matrixWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 3, 1, 1);

        label_5 = new QLabel(matrixWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 1, 4, 1, 1);

        label_6 = new QLabel(matrixWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 1, 6, 1, 1);

        label_3 = new QLabel(matrixWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setWordWrap(false);

        gridLayout_2->addWidget(label_3, 1, 1, 1, 1);


        retranslateUi(matrixWidget);

        QMetaObject::connectSlotsByName(matrixWidget);
    } // setupUi

    void retranslateUi(QWidget *matrixWidget)
    {
        matrixWidget->setWindowTitle(QApplication::translate("matrixWidget", "matrixWidget", nullptr));
        label_14->setText(QApplication::translate("matrixWidget", "(", nullptr));
        numC4->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC2->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC9->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC3->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC8->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC5->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC6->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC1->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        numC7->setPlaceholderText(QApplication::translate("matrixWidget", "0", nullptr));
        label_13->setText(QApplication::translate("matrixWidget", ")", nullptr));
        plusButton->setText(QApplication::translate("matrixWidget", "+", nullptr));
        minusButton->setText(QApplication::translate("matrixWidget", "-", nullptr));
        addButton->setText(QApplication::translate("matrixWidget", "A + B", nullptr));
        nValue->setPlaceholderText(QApplication::translate("matrixWidget", "n", nullptr));
        numMultButton->setText(QApplication::translate("matrixWidget", "n * A", nullptr));
        subtButton->setText(QApplication::translate("matrixWidget", "A - B", nullptr));
        multButton->setText(QApplication::translate("matrixWidget", "A * B", nullptr));
        numA1->setPlaceholderText(QApplication::translate("matrixWidget", "1", nullptr));
        numA8->setPlaceholderText(QApplication::translate("matrixWidget", "8", nullptr));
        numA6->setPlaceholderText(QApplication::translate("matrixWidget", "6", nullptr));
        numA4->setPlaceholderText(QApplication::translate("matrixWidget", "4", nullptr));
        numA3->setPlaceholderText(QApplication::translate("matrixWidget", "3", nullptr));
        numA5->setPlaceholderText(QApplication::translate("matrixWidget", "5", nullptr));
        numA9->setPlaceholderText(QApplication::translate("matrixWidget", "9", nullptr));
        numA2->setPlaceholderText(QApplication::translate("matrixWidget", "2", nullptr));
        numA7->setPlaceholderText(QApplication::translate("matrixWidget", "7", nullptr));
        numB1->setPlaceholderText(QApplication::translate("matrixWidget", "1", nullptr));
        numB2->setPlaceholderText(QApplication::translate("matrixWidget", "2", nullptr));
        numB3->setPlaceholderText(QApplication::translate("matrixWidget", "3", nullptr));
        numB4->setPlaceholderText(QApplication::translate("matrixWidget", "4", nullptr));
        numB5->setPlaceholderText(QApplication::translate("matrixWidget", "5", nullptr));
        numB6->setPlaceholderText(QApplication::translate("matrixWidget", "6", nullptr));
        numB7->setPlaceholderText(QApplication::translate("matrixWidget", "7", nullptr));
        numB8->setPlaceholderText(QApplication::translate("matrixWidget", "8", nullptr));
        numB9->setPlaceholderText(QApplication::translate("matrixWidget", "9", nullptr));
        label->setText(QApplication::translate("matrixWidget", "Matrix A", nullptr));
        label_2->setText(QApplication::translate("matrixWidget", "Matrix B", nullptr));
        label_4->setText(QApplication::translate("matrixWidget", ")", nullptr));
        label_5->setText(QApplication::translate("matrixWidget", "(", nullptr));
        label_6->setText(QApplication::translate("matrixWidget", ")", nullptr));
        label_3->setText(QApplication::translate("matrixWidget", "(", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matrixWidget: public Ui_matrixWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXWIDGET_H
