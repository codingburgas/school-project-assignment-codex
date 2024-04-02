/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBoxLogin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutLogin;
    QVBoxLayout *verticalLayoutUserPass;
    QHBoxLayout *horizontalLayoutUsername;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayoutPassword;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLogin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBoxLogin = new QGroupBox(centralwidget);
        groupBoxLogin->setObjectName("groupBoxLogin");
        groupBoxLogin->setGeometry(QRect(70, 140, 291, 171));
        layoutWidget = new QWidget(groupBoxLogin);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 29, 271, 131));
        verticalLayoutLogin = new QVBoxLayout(layoutWidget);
        verticalLayoutLogin->setObjectName("verticalLayoutLogin");
        verticalLayoutLogin->setContentsMargins(0, 0, 0, 0);
        verticalLayoutUserPass = new QVBoxLayout();
        verticalLayoutUserPass->setObjectName("verticalLayoutUserPass");
        horizontalLayoutUsername = new QHBoxLayout();
        horizontalLayoutUsername->setObjectName("horizontalLayoutUsername");
        labelUsername = new QLabel(layoutWidget);
        labelUsername->setObjectName("labelUsername");

        horizontalLayoutUsername->addWidget(labelUsername);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName("lineEditUsername");

        horizontalLayoutUsername->addWidget(lineEditUsername);


        verticalLayoutUserPass->addLayout(horizontalLayoutUsername);

        horizontalLayoutPassword = new QHBoxLayout();
        horizontalLayoutPassword->setObjectName("horizontalLayoutPassword");
        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName("labelPassword");

        horizontalLayoutPassword->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEnabled(true);

        horizontalLayoutPassword->addWidget(lineEditPassword);


        verticalLayoutUserPass->addLayout(horizontalLayoutPassword);


        verticalLayoutLogin->addLayout(verticalLayoutUserPass);

        pushButtonLogin = new QPushButton(layoutWidget);
        pushButtonLogin->setObjectName("pushButtonLogin");

        verticalLayoutLogin->addWidget(pushButtonLogin);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 450, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBoxLogin->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        labelUsername->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
