/********************************************************************************
** Form generated from reading UI file 'productregister.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTREGISTER_H
#define UI_PRODUCTREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductRegister
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QTextEdit *textEdit;
    QLabel *label_5;
    QDateEdit *dateEdit_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_10;
    QLabel *label_3;
    QPushButton *devBtn;
    QComboBox *comboBox;
    QLineEdit *lineEdit_11;
    QLabel *label_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ProductRegister)
    {
        if (ProductRegister->objectName().isEmpty())
            ProductRegister->setObjectName(QString::fromUtf8("ProductRegister"));
        ProductRegister->resize(394, 438);
        ProductRegister->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(228, 229, 244); /* Light gray background */\n"
"    border: 1px solid #a9a9a9; /* Darker gray border for a 3D effect */\n"
"    border-radius: 6px; /* Rounded corners */\n"
"    padding: 5px 10px; /* Padding for a button-like appearance */\n"
"    color: black; /* Text color */\n"
"    \n"
"    /* Subtle gradient for a shiny effect */\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 #f0f0f0, stop:1 #d3d3d3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #e6e6e6; /* Change to a lighter shade on hover */\n"
"    border-color: #b0b0b0; /* Change border color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #bfbfbf; /* Darker gray when pressed */\n"
"    border-color: #808080; /* Slightly darker border when pressed */\n"
"}\n"
"\n"
"\n"
"QWidget {font: 12pt \"Segoe UI\";}"));
        verticalLayout = new QVBoxLayout(ProductRegister);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(ProductRegister);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 1, 1, 1);

        dateEdit = new QDateEdit(ProductRegister);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 9, 0, 1, 1);

        textEdit = new QTextEdit(ProductRegister);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 11, 0, 1, 1);

        label_5 = new QLabel(ProductRegister);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 9, 1, 1, 1);

        dateEdit_2 = new QDateEdit(ProductRegister);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        gridLayout->addWidget(dateEdit_2, 8, 0, 1, 1);

        label_2 = new QLabel(ProductRegister);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(ProductRegister);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);

        lineEdit_10 = new QLineEdit(ProductRegister);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 5, 0, 1, 1);

        label_3 = new QLabel(ProductRegister);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);

        devBtn = new QPushButton(ProductRegister);
        devBtn->setObjectName(QString::fromUtf8("devBtn"));

        gridLayout->addWidget(devBtn, 0, 1, 1, 1);

        comboBox = new QComboBox(ProductRegister);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);

        lineEdit_11 = new QLineEdit(ProductRegister);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 6, 0, 1, 1);

        label_4 = new QLabel(ProductRegister);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 1, 1, 1);

        label_7 = new QLabel(ProductRegister);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 11, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(ProductRegister);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(pushButton_2);

        lineEdit_8 = new QLineEdit(ProductRegister);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_2->addWidget(lineEdit_8);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ProductRegister);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, textEdit);
        QWidget::setTabOrder(textEdit, pushButton);

        retranslateUi(ProductRegister);

        QMetaObject::connectSlotsByName(ProductRegister);
    } // setupUi

    void retranslateUi(QWidget *ProductRegister)
    {
        ProductRegister->setWindowTitle(QCoreApplication::translate("ProductRegister", "\331\205\330\255\330\265\331\210\331\204\330\247\330\252", nullptr));
        label_6->setText(QCoreApplication::translate("ProductRegister", "\330\252\330\247\330\261\333\214\330\256 \330\256\330\261\333\214\330\257 :", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("ProductRegister", "yyyy/M/d", nullptr));
        label_5->setText(QCoreApplication::translate("ProductRegister", "\330\247\331\206\331\202\330\266\330\247\333\214 \332\257\330\247\330\261\330\247\331\206\330\252\333\214 :", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("ProductRegister", "yyyy/M/d", nullptr));
        label_2->setText(QCoreApplication::translate("ProductRegister", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        label->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        label_3->setText(QCoreApplication::translate("ProductRegister", "\331\201\330\247\332\251\330\252\331\210\330\261 :", nullptr));
        devBtn->setText(QCoreApplication::translate("ProductRegister", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252 \330\257\330\263\330\252\332\257\330\247\331\207", nullptr));
        label_4->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 anydesk :", nullptr));
        label_7->setText(QCoreApplication::translate("ProductRegister", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ProductRegister", "...", nullptr));
        pushButton->setText(QCoreApplication::translate("ProductRegister", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductRegister: public Ui_ProductRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTREGISTER_H
