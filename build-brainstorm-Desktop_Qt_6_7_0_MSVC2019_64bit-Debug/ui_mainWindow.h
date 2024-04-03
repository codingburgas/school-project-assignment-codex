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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayoutDb;
    QPushButton *pushButtonDbDrivers;
    QPushButton *pushButtonTestDb;
    QGroupBox *groupBoxRegister;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *firstNameReg;
    QLabel *labelFirstNameReg;
    QLineEdit *lineEditFirstNameReg;
    QHBoxLayout *lastNameReg;
    QLabel *labelLastNameReg;
    QLineEdit *lineEditLastNameReg;
    QHBoxLayout *emailReg;
    QLabel *labelEmailReg;
    QLineEdit *lineEditEmailReg;
    QHBoxLayout *usernameReg;
    QLabel *labelUsernameReg;
    QLineEdit *lineEditUsernameReg;
    QHBoxLayout *passwordReg;
    QLabel *labelPasswordReg;
    QLineEdit *lineEditPasswordReg;
    QPushButton *pushButtonRegister;
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
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayoutPassword->addWidget(lineEditPassword);


        verticalLayoutUserPass->addLayout(horizontalLayoutPassword);


        verticalLayoutLogin->addLayout(verticalLayoutUserPass);

        pushButtonLogin = new QPushButton(layoutWidget);
        pushButtonLogin->setObjectName("pushButtonLogin");

        verticalLayoutLogin->addWidget(pushButtonLogin);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(360, 10, 82, 56));
        verticalLayoutDb = new QVBoxLayout(layoutWidget1);
        verticalLayoutDb->setObjectName("verticalLayoutDb");
        verticalLayoutDb->setContentsMargins(0, 0, 0, 0);
        pushButtonDbDrivers = new QPushButton(layoutWidget1);
        pushButtonDbDrivers->setObjectName("pushButtonDbDrivers");

        verticalLayoutDb->addWidget(pushButtonDbDrivers);

        pushButtonTestDb = new QPushButton(layoutWidget1);
        pushButtonTestDb->setObjectName("pushButtonTestDb");

        verticalLayoutDb->addWidget(pushButtonTestDb);

        groupBoxRegister = new QGroupBox(centralwidget);
        groupBoxRegister->setObjectName("groupBoxRegister");
        groupBoxRegister->setGeometry(QRect(70, 350, 291, 231));
        layoutWidget2 = new QWidget(groupBoxRegister);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 30, 271, 188));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        firstNameReg = new QHBoxLayout();
        firstNameReg->setObjectName("firstNameReg");
        labelFirstNameReg = new QLabel(layoutWidget2);
        labelFirstNameReg->setObjectName("labelFirstNameReg");

        firstNameReg->addWidget(labelFirstNameReg);

        lineEditFirstNameReg = new QLineEdit(layoutWidget2);
        lineEditFirstNameReg->setObjectName("lineEditFirstNameReg");

        firstNameReg->addWidget(lineEditFirstNameReg);


        verticalLayout->addLayout(firstNameReg);

        lastNameReg = new QHBoxLayout();
        lastNameReg->setObjectName("lastNameReg");
        labelLastNameReg = new QLabel(layoutWidget2);
        labelLastNameReg->setObjectName("labelLastNameReg");

        lastNameReg->addWidget(labelLastNameReg);

        lineEditLastNameReg = new QLineEdit(layoutWidget2);
        lineEditLastNameReg->setObjectName("lineEditLastNameReg");

        lastNameReg->addWidget(lineEditLastNameReg);


        verticalLayout->addLayout(lastNameReg);

        emailReg = new QHBoxLayout();
        emailReg->setObjectName("emailReg");
        labelEmailReg = new QLabel(layoutWidget2);
        labelEmailReg->setObjectName("labelEmailReg");

        emailReg->addWidget(labelEmailReg);

        lineEditEmailReg = new QLineEdit(layoutWidget2);
        lineEditEmailReg->setObjectName("lineEditEmailReg");

        emailReg->addWidget(lineEditEmailReg);


        verticalLayout->addLayout(emailReg);

        usernameReg = new QHBoxLayout();
        usernameReg->setObjectName("usernameReg");
        labelUsernameReg = new QLabel(layoutWidget2);
        labelUsernameReg->setObjectName("labelUsernameReg");

        usernameReg->addWidget(labelUsernameReg);

        lineEditUsernameReg = new QLineEdit(layoutWidget2);
        lineEditUsernameReg->setObjectName("lineEditUsernameReg");

        usernameReg->addWidget(lineEditUsernameReg);


        verticalLayout->addLayout(usernameReg);

        passwordReg = new QHBoxLayout();
        passwordReg->setObjectName("passwordReg");
        labelPasswordReg = new QLabel(layoutWidget2);
        labelPasswordReg->setObjectName("labelPasswordReg");

        passwordReg->addWidget(labelPasswordReg);

        lineEditPasswordReg = new QLineEdit(layoutWidget2);
        lineEditPasswordReg->setObjectName("lineEditPasswordReg");
        lineEditPasswordReg->setEnabled(true);
        lineEditPasswordReg->setEchoMode(QLineEdit::Password);

        passwordReg->addWidget(lineEditPasswordReg);


        verticalLayout->addLayout(passwordReg);


        verticalLayout_2->addLayout(verticalLayout);

        pushButtonRegister = new QPushButton(layoutWidget2);
        pushButtonRegister->setObjectName("pushButtonRegister");

        verticalLayout_2->addWidget(pushButtonRegister);

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
        pushButtonDbDrivers->setText(QCoreApplication::translate("MainWindow", "DB Drivers", nullptr));
        pushButtonTestDb->setText(QCoreApplication::translate("MainWindow", "Test DB", nullptr));
        groupBoxRegister->setTitle(QCoreApplication::translate("MainWindow", "Register", nullptr));
        labelFirstNameReg->setText(QCoreApplication::translate("MainWindow", "First name", nullptr));
        labelLastNameReg->setText(QCoreApplication::translate("MainWindow", "Last name", nullptr));
        labelEmailReg->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        labelUsernameReg->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        labelPasswordReg->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
