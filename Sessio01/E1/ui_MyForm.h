/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDial *dial;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QDial *dial_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(282, 318);
        verticalLayout_4 = new QVBoxLayout(MyForm);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        lcdNumber = new QLCDNumber(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dial = new QDial(MyForm);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMaximum(23);

        horizontalLayout->addWidget(dial);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        lcdNumber_2 = new QLCDNumber(MyForm);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        verticalLayout_2->addWidget(lcdNumber_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        dial_2 = new QDial(MyForm);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setMaximum(59);

        horizontalLayout_4->addWidget(dial_2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(MyForm);
        QObject::connect(dial, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Reloj Digital", 0));
        label->setText(QApplication::translate("MyForm", "Hours", 0));
        label_2->setText(QApplication::translate("MyForm", "Minutes", 0));
        pushButton->setText(QApplication::translate("MyForm", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
