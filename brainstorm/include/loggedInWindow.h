#ifndef LOGGEDINWINDOW_H
#define LOGGEDINWINDOW_H

#include <QDialog>

namespace Ui {
class LoggedInWindow;
}

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
