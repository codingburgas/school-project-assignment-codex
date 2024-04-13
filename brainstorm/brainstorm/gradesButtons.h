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

private slots:
    void on_pushButtonAddGrade_clicked();

private:
    Ui::GradesButtons *ui;
};

#endif // GRADESBUTTONS_H
