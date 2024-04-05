#include "../include/loggedInWindow.h"
#include "ui_loggedInWindow.h"

LoggedInWindow::LoggedInWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoggedInWindow)
{
    ui->setupUi(this);
}

LoggedInWindow::~LoggedInWindow()
{
    delete ui;
}
