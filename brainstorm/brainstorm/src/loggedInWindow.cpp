#include "../include/loggedInWindow.h"
#include "../include/gradesButtons.h" // Include the header for the GradesButtons class
#include "ui_loggedInWindow.h"

LoggedInWindow::LoggedInWindow(QWidget *parent, const QString& username, int perms)
    : QDialog(parent)
    , ui(new Ui::LoggedInWindow)
    , username(username)
    , perms(perms)
{
    ui->setupUi(this);
    checkPermissions();

    // Connect button signals to handleButtonClick slot
    connect(ui->pushButtonAddGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
}

LoggedInWindow::~LoggedInWindow()
{
    delete ui;
}

void LoggedInWindow::checkPermissions()
{
    // Based on the permission level, set the initial stacked widget index
    if (perms == 1)
    {
        ui->stackedWidget->setCurrentIndex(1); // Index of the page for permission level 1
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0); // Index of the page other permission level 0
    }
}

void LoggedInWindow::handleButtonClick()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton)
    {
        GradesButtons* gradesButtons = new GradesButtons(this);

        if (clickedButton == ui->pushButtonAddGrade)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(0);
        }
        else if (clickedButton == ui->pushButtonDeleteGrade)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(2);
        }
        else if (clickedButton == ui->pushButtonUpdateGrade)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(1);
        }

        gradesButtons->show();
    }
}

