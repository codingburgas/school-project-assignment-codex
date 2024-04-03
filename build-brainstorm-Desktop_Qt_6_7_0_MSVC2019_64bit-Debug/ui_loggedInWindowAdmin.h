/********************************************************************************
** Form generated from reading UI file 'loggedInWindowAdmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGEDINWINDOWADMIN_H
#define UI_LOGGEDINWINDOWADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LoggedInWindowAdmin
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *LoggedInWindowAdmin)
    {
        if (LoggedInWindowAdmin->objectName().isEmpty())
            LoggedInWindowAdmin->setObjectName("LoggedInWindowAdmin");
        LoggedInWindowAdmin->resize(1280, 720);
        textEdit = new QTextEdit(LoggedInWindowAdmin);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(410, 30, 461, 70));

        retranslateUi(LoggedInWindowAdmin);

        QMetaObject::connectSlotsByName(LoggedInWindowAdmin);
    } // setupUi

    void retranslateUi(QDialog *LoggedInWindowAdmin)
    {
        LoggedInWindowAdmin->setWindowTitle(QCoreApplication::translate("LoggedInWindowAdmin", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("LoggedInWindowAdmin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Admin Permissions</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggedInWindowAdmin: public Ui_LoggedInWindowAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGEDINWINDOWADMIN_H
