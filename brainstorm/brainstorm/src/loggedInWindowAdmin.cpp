#include "../include/loggedInWindowAdmin.h"
#include "../include/grades.h"
#include "ui_loggedInWindowAdmin.h"

LoggedInWindowAdmin::LoggedInWindowAdmin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoggedInWindowAdmin)
{
    ui->setupUi(this);
}

LoggedInWindowAdmin::~LoggedInWindowAdmin()
{
    delete ui;
}

void LoggedInWindowAdmin::on_pushButtonAddGrade_clicked()
{
    QString subj = "English";
    addGrade(11, subj, 2);
}


void LoggedInWindowAdmin::on_pushButtonUpdateGrade_clicked()
{
    updateGrade(3, 5);
}


void LoggedInWindowAdmin::on_pushButtonDeleteGrade_clicked()
{
    deleteGrade(2);
}
