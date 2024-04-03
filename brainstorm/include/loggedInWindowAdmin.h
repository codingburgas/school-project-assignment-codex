#ifndef LOGGEDINWINDOWADMIN_H
#define LOGGEDINWINDOWADMIN_H

#include <QDialog>

namespace Ui {
class LoggedInWindowAdmin;
}

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
