#ifndef GRADESBUTTONS_H
#define GRADESBUTTONS_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GradesButtons;
}
QT_END_NAMESPACE

// Contains the grades buttons action methods.
class GradesButtons : public QDialog
{
    Q_OBJECT

public:
    // Constructor.
    explicit GradesButtons(QWidget *parent = nullptr, int userID = 0);
    // Destructor.
    ~GradesButtons();

    // Sets the stacked widget index when called.
    void setStackedWidgetIndex(int index);

private slots:
    // Methods for button actions.
    void on_pushButtonAddGrade_clicked();
    void on_pushButtonUpdateGrade_clicked();
    void on_pushButtonDeleteGrade_clicked();
    void on_pushButtonUpdatePerms_clicked();
    void on_pushButtonAddToGrade_clicked();
    void on_pushButtonAddAbsence_2_clicked();
    void on_pushButtonUpdateAbsence_clicked();
    void on_pushButtonDeleteAbsence_clicked();
    void on_pushButtonAddFeedback_clicked();
    void on_pushButtonUpdateFeedback_clicked();
    void on_pushButtonDeleteFeedback_clicked();
    void on_pushButtonDeleteAccount_clicked();

    // Method which deletes a particular user's account.
    void deleteAccount(int loggedInUserID);

private:
    Ui::GradesButtons *ui;
    int stackedWidgetIndex;
    int userID;
};

#endif // GRADESBUTTONS_H
