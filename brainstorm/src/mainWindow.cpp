#include <QMessageBox>
#include "./include/mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditUsername->text();

    if (username == "admin" and password == "admin")
    {
        QMessageBox::information(this, "Login", "Logged in");
    }
    else
    {
        QMessageBox::warning(this, "login", "Login failed");
    }
}
