/********************************************************************************
** Form generated from reading UI file 'loggedInWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGEDINWINDOW_H
#define UI_LOGGEDINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggedInWindow
{
public:
    QPushButton *pushButtonHead;
    QWidget *widget;
    QVBoxLayout *verticalLayoutTestButtons;
    QPushButton *pushButtonPerms;
    QPushButton *pushButtonLastActive;

    void setupUi(QDialog *LoggedInWindow)
    {
        if (LoggedInWindow->objectName().isEmpty())
            LoggedInWindow->setObjectName("LoggedInWindow");
        LoggedInWindow->resize(1280, 720);
        pushButtonHead = new QPushButton(LoggedInWindow);
        pushButtonHead->setObjectName("pushButtonHead");
        pushButtonHead->setGeometry(QRect(560, 20, 80, 24));
        widget = new QWidget(LoggedInWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(560, 340, 82, 56));
        verticalLayoutTestButtons = new QVBoxLayout(widget);
        verticalLayoutTestButtons->setObjectName("verticalLayoutTestButtons");
        verticalLayoutTestButtons->setContentsMargins(0, 0, 0, 0);
        pushButtonPerms = new QPushButton(widget);
        pushButtonPerms->setObjectName("pushButtonPerms");

        verticalLayoutTestButtons->addWidget(pushButtonPerms);

        pushButtonLastActive = new QPushButton(widget);
        pushButtonLastActive->setObjectName("pushButtonLastActive");

        verticalLayoutTestButtons->addWidget(pushButtonLastActive);


        retranslateUi(LoggedInWindow);

        QMetaObject::connectSlotsByName(LoggedInWindow);
    } // setupUi

    void retranslateUi(QDialog *LoggedInWindow)
    {
        LoggedInWindow->setWindowTitle(QCoreApplication::translate("LoggedInWindow", "Dialog", nullptr));
        pushButtonHead->setText(QCoreApplication::translate("LoggedInWindow", "Brainstorm", nullptr));
        pushButtonPerms->setText(QCoreApplication::translate("LoggedInWindow", "Permissions", nullptr));
        pushButtonLastActive->setText(QCoreApplication::translate("LoggedInWindow", "Last Active", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggedInWindow: public Ui_LoggedInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGEDINWINDOW_H
