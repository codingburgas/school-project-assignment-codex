#ifndef GRADESBUTTONS_H
#define GRADESBUTTONS_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GradesButtons;
}
QT_END_NAMESPACE

class GradesButtons : public QDialog
{
    Q_OBJECT

public:
    explicit GradesButtons(QWidget *parent = nullptr, int userID = 0);
    ~GradesButtons();
    void setStackedWidgetIndex(int index);

private slots:
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

private:
    Ui::GradesButtons *ui;
    int stackedWidgetIndex;
    int userID;
};

#endif // GRADESBUTTONS_H