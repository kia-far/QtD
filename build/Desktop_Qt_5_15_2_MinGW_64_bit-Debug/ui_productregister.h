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
    QLabel *label;
    QLabel *label_7;
    QLabel *label_4;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_13;
    QLabel *label_6;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QTextEdit *textEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_8;
    QLabel *label_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ProductRegister)
    {
        if (ProductRegister->objectName().isEmpty())
            ProductRegister->setObjectName(QString::fromUtf8("ProductRegister"));
        ProductRegister->resize(394, 438);
        verticalLayout = new QVBoxLayout(ProductRegister);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ProductRegister);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_7 = new QLabel(ProductRegister);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        label_4 = new QLabel(ProductRegister);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        lineEdit_11 = new QLineEdit(ProductRegister);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 3, 0, 1, 1);

        lineEdit_13 = new QLineEdit(ProductRegister);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 5, 0, 1, 1);

        label_6 = new QLabel(ProductRegister);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        lineEdit_12 = new QLineEdit(ProductRegister);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 4, 0, 1, 1);

        lineEdit_9 = new QLineEdit(ProductRegister);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 1, 0, 1, 1);

        lineEdit_10 = new QLineEdit(ProductRegister);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 2, 0, 1, 1);

        textEdit = new QTextEdit(ProductRegister);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 6, 0, 1, 1);

        label_3 = new QLabel(ProductRegister);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lineEdit_8 = new QLineEdit(ProductRegister);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 0, 0, 1, 1);

        label_5 = new QLabel(ProductRegister);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_2 = new QLabel(ProductRegister);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ProductRegister);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lineEdit_8, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, lineEdit_12);
        QWidget::setTabOrder(lineEdit_12, lineEdit_13);
        QWidget::setTabOrder(lineEdit_13, textEdit);
        QWidget::setTabOrder(textEdit, pushButton);

        retranslateUi(ProductRegister);

        QMetaObject::connectSlotsByName(ProductRegister);
    } // setupUi

    void retranslateUi(QWidget *ProductRegister)
    {
        ProductRegister->setWindowTitle(QCoreApplication::translate("ProductRegister", "Form", nullptr));
        label->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 \330\263\330\261\333\214\330\247\331\204 :", nullptr));
        label_7->setText(QCoreApplication::translate("ProductRegister", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 :", nullptr));
        label_4->setText(QCoreApplication::translate("ProductRegister", "\330\264\331\205\330\247\330\261\331\207 anydesk :", nullptr));
        label_6->setText(QCoreApplication::translate("ProductRegister", "\330\252\330\247\330\261\333\214\330\256 \330\256\330\261\333\214\330\257 :", nullptr));
        label_3->setText(QCoreApplication::translate("ProductRegister", "\331\201\330\247\332\251\330\252\331\210\330\261 :", nullptr));
        label_5->setText(QCoreApplication::translate("ProductRegister", "\330\247\331\206\331\202\330\266\330\247\333\214 \332\257\330\247\330\261\330\247\331\206\330\252\333\214 :", nullptr));
        label_2->setText(QCoreApplication::translate("ProductRegister", "\331\206\330\247\331\205 \330\257\330\263\330\252\332\257\330\247\331\207 :", nullptr));
        pushButton->setText(QCoreApplication::translate("ProductRegister", "\330\253\330\250\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductRegister: public Ui_ProductRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTREGISTER_H
