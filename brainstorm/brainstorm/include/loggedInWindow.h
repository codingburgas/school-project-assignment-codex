#ifndef LOGGEDINWINDOW_H
#define LOGGEDINWINDOW_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LoggedInWindow;
}
QT_END_NAMESPACE

// Contains the logged in window methods.
class LoggedInWindow : public QDialog
{
    Q_OBJECT

public:
    // Constructor.
    explicit LoggedInWindow(QWidget *parent = nullptr, const QString& username = "", int perms = 0, int userID = 0, const QString& firstName = "", const QString& lastName = "");
    //Destructor.
    ~LoggedInWindow();
    // Checks the particular user's permissions.
    void checkPermissions();
    // Adds the users to a drop down menu (combo box).
    void addUsersToComboBox();
    // Adds the users' IDs to a drop down menu (combo box).
    void addUsersIDsToComboBox();
    // Handles buttons' actions when clicked.
    void handleButtonClick();
    // Displays the average grade of a particular user on a label.
    void setAverageGradeLabel();
    // Displays the absence count of a particular user on a label.
    void setAbsenceLabel();
    // Displays the feedback count of a particular user on a label.
    void setFeedbackLabel();
    // Shows the GPA of the user on the tab widget in the user menu.
    void showFirstPage();
    // Shows the absences of the user on the tab widget in the user menu.
    void showSecondPage();
    // Shows the feedbacks of the user on the tab widget in the user menu.
    void showThirdPage();


private slots:
    // Table widget actions.
    void on_tableWidget_2_cellClicked(int row, int column);

    // Combo box actions when a criteria is changed.
    void onComboBoxUserChanged(int index);
    void onComboBoxGradesChanged(int index);
    void onComboBoxFeedbackChanged(int index);
    void onComboBoxAbsenceChanged(int index);

    // Button actions when clicked.
    void on_gradesButton_clicked();
    void on_absencesButton_clicked();
    void on_feedbacksButton_clicked();

private:
    Ui::LoggedInWindow *ui;
    QString username;
    int perms;
    int userID;
    QString firstName;
    QString lastName;
};

#endif // LOGGEDINWINDOW_H
