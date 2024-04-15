#ifndef LOGGEDINWINDOW_H
#define LOGGEDINWINDOW_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoggedInWindow;
}
QT_END_NAMESPACE

class LoggedInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedInWindow(QWidget *parent = nullptr, const QString& username = "", int perms = 0, int userID = 0);
    ~LoggedInWindow();
    void checkPermissions();
    void handleButtonClick();

private:
    Ui::LoggedInWindow *ui;
    QString username;
    int perms;
    int userID;
};

#endif // LOGGEDINWINDOW_H
