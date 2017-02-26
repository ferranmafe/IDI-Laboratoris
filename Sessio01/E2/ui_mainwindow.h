/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButton_2;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(283, 311);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 221, 281));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        radioButton_3 = new QRadioButton(widget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("\n"
"background-color: rgb(252, 0, 13);"));

        verticalLayout->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(35, 255, 46);"));

        verticalLayout->addWidget(label_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(45, 255, 223)"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(radioButton, SIGNAL(toggled(bool)), label, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(toggled(bool)), label_3, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_3, SIGNAL(toggled(bool)), label_2, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Vermell", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Verd", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Blau", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Vermell", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Verd", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Blau", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
