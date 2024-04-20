#include "../include/loggedInWindow.h"
#include "../include/gradesButtons.h"
#include "ui_loggedInWindow.h"

LoggedInWindow::LoggedInWindow(QWidget *parent, const QString& username, int perms, int userID, const QString &firstName, const QString &lastName)
    : QDialog(parent)
    , ui(new Ui::LoggedInWindow)
    , username(username)
    , perms(perms)
    , userID(userID)
    , firstName(firstName)
    , lastName(lastName)
{
    ui->setupUi(this);
    checkPermissions();

    // Connect button signals to handleButtonClick slot
    connect(ui->pushButtonAddGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonAddGrade_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteGrade_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateGrade_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonAddPerms, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonAddToGrade, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonAddAbsence, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateAbsence, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteAbsence, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);

    ui->label->setText("Welcome back, " + firstName + " " + lastName + "!");
    ui->label_2->setText("Welcome back, " + firstName + " " + lastName + "!");
    ui->label_3->setText("Welcome back, " + firstName + " " + lastName + "!");
    QFont font = ui->label->font();
    font.setPointSize(24);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
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
    else if (perms == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0); // Index of the page other permission level 0
    }
}

void LoggedInWindow::handleButtonClick()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton)
    {
        GradesButtons* gradesButtons = new GradesButtons(this, userID);

        if (clickedButton == ui->pushButtonAddGrade || clickedButton == ui->pushButtonAddGrade_2)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(0);
        }
        else if (clickedButton == ui->pushButtonUpdateGrade || clickedButton == ui->pushButtonUpdateGrade_2)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(3);
        }
        else if (clickedButton == ui->pushButtonAddAbsence)
        {
            gradesButtons->setStackedWidgetIndex(6);
        }
        else if (clickedButton == ui->pushButtonUpdateAbsence)
        {
            gradesButtons->setStackedWidgetIndex(7);
        }
        else if (clickedButton == ui->pushButtonDeleteAbsence)
        {
            gradesButtons->setStackedWidgetIndex(8);
        }
        else if (clickedButton == ui->pushButtonAddPerms)
        {
            gradesButtons->setStackedWidgetIndex(4);
        }
        else if (clickedButton == ui->pushButtonDeleteGrade || clickedButton == ui->pushButtonDeleteGrade_2)
        {
            // Pass index to GradesButtons constructor
            gradesButtons->setStackedWidgetIndex(5);
        }
        else if (clickedButton == ui->pushButtonAddToGrade)
        {
            gradesButtons->setStackedWidgetIndex(1);
        }

        gradesButtons->show();
    }
}

void displayUsersWithGrade(QStackedWidget *stackedWidgetChemistry, QString& grade)
{
    while (stackedWidgetChemistry->count() > 0)
    {
        QWidget *widget = stackedWidgetChemistry->widget(0);
        stackedWidgetChemistry->removeWidget(widget);
        delete widget;
    }

    QSqlQuery query;
    QString queryString = "SELECT u.userID, u.firstName, u.lastName, g.subject, g.grade "
                          "FROM users u "
                          "LEFT JOIN grades g ON u.userID = g.userID "
                          "WHERE u.grade = :grade";

    query.prepare(queryString);
    query.bindValue(":grade", grade);

    if(query.exec())
    {
        //Create a new widget to display the results
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();
        QString currentUserID;
        QString currentName;
        QString currentLastName;
        QString currentUserGrades;

        while (query.next())
        {
            QString userID = query.value(0).toString();
            QString firstName = query.value(1).toString();
            QString lastName = query.value(2).toString();
            QString subject = query.value(3).toString();
            QString grade = query.value(4).toString();

            //If it's a new user, display the information for the previous user (if any)
            if (userID != currentUserID && !currentUserID.isEmpty())
            {
                QLabel *label = new QLabel(currentUserID + " " + currentName + " " + currentLastName + ": " + currentUserGrades);
                layout->addWidget(label);

                //Reset the information for the new user
                currentUserID = userID;
                currentName = firstName;
                currentLastName = lastName;
                currentUserGrades = subject + " " + grade;
            }
            else //If it's the same user, append the grade to the current user's grades
            {
                currentUserGrades += "; " + subject + " " + grade;
            }

            //Update the current user's information
            currentUserID = userID;
            currentName = firstName;
            currentLastName = lastName;
        }

        //Display the last user's information
        if (!currentUserID.isEmpty())
        {
            QLabel *label = new QLabel(currentUserID + " " + currentName + " " + currentLastName + ": " + currentUserGrades);
            layout->addWidget(label);
        }

        page->setLayout(layout);
        stackedWidgetChemistry->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
    }
}



void LoggedInWindow::on_tableWidget_2_cellClicked(int row, int column)
{
    if(ui->tableWidget_2->item(row, column) == nullptr)
    {
        return;
    }

    // Get the text of the clicked cell
    QString grade = ui->tableWidget_2->item(row, column)->text();
    qDebug() << "Clicked Grade:" << grade;

    // Display users with the clicked grade
    displayUsersWithGrade(ui->stackedWidgetChemistry, grade);
}
