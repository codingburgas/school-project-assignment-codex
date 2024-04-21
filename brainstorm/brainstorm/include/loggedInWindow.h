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
    explicit LoggedInWindow(QWidget *parent = nullptr, const QString& username = "", int perms = 0, int userID = 0, const QString& firstName = "", const QString& lastName = "");
    ~LoggedInWindow();
    void checkPermissions();
    void handleButtonClick();
    void setAverageGradeLabel();
    void setAbsenceLabel();
    void setFeedbackLabel();

private slots:
    void on_tableWidget_2_cellClicked(int row, int column);

private:
    Ui::LoggedInWindow *ui;
    QString username;
    int perms;
    int userID;
    QString firstName;
    QString lastName;
};

#endif // LOGGEDINWINDOW_H
