#include "../include/loggedInWindowAdmin.h"
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
