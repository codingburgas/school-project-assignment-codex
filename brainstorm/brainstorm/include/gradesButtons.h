#ifndef GRADESBUTTONS_H
#define GRADESBUTTONS_H

#include <QDialog>

namespace Ui {
class GradesButtons;
}

class GradesButtons : public QDialog
{
    Q_OBJECT

public:
    explicit GradesButtons(QWidget *parent = nullptr);
    ~GradesButtons();
    void setStackedWidgetIndex(int index);

private slots:
    void on_pushButtonAddGrade_clicked();

    void on_pushButtonUpdateGrade_clicked();

    void on_pushButtonDeleteGrade_clicked();

private:
    Ui::GradesButtons *ui;
    int stackedWidgetIndex; // Declare here
};

#endif // GRADESBUTTONS_H
