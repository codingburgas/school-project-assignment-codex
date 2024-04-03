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
    explicit LoggedInWindow(QWidget *parent = nullptr);
    ~LoggedInWindow();

private:
    Ui::LoggedInWindow *ui;
};

#endif // LOGGEDINWINDOW_H
