#ifndef LOGGEDINWINDOWADMIN_H
#define LOGGEDINWINDOWADMIN_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoggedInWindowAdmin;
}
QT_END_NAMESPACE

class LoggedInWindowAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedInWindowAdmin(QWidget *parent = nullptr);
    ~LoggedInWindowAdmin();

private:
    Ui::LoggedInWindowAdmin *ui;
};

#endif // LOGGEDINWINDOWADMIN_H
