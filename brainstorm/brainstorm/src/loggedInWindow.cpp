#include "../include/loggedInWindow.h"
#include "../include/gradesButtons.h"
#include "../include/user.h"
#include "../include/db.h"
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
    addUsersToComboBox();
    addUsersIDsToComboBox();

    // Set background image and make it transparent
    QPixmap backgroundImage("../brainstorm/assets/background.jpg");
    ui->backgroundLabel->setPixmap(backgroundImage);
    ui->backgroundLabel->setScaledContents(true); // Scale the image to fit the label
    ui->backgroundLabel->setStyleSheet("background-color: rgba(255, 255, 255, 1);"); // Set transparency

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
    connect(ui->pushButtonAddFeedback, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateFeedback, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteFeedback, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);

    connect(ui->comboBoxUsers, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &LoggedInWindow::onComboBoxUserChanged);
    connect(ui->comboBoxGrades, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &LoggedInWindow::onComboBoxGradesChanged);
    connect(ui->comboBoxFeedback, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &LoggedInWindow::onComboBoxFeedbackChanged);
    connect(ui->comboBoxAbsence, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &LoggedInWindow::onComboBoxAbsenceChanged);

    setAverageGradeLabel();
    setAbsenceLabel();
    setFeedbackLabel();

    ui->tabWidget->setTabText(0, "GPA");
    ui->tabWidget->setTabText(1, "Absences");
    ui->tabWidget->setTabText(2, "Feedbacks");

    ui->label->setText("Welcome back, " + firstName + " " + lastName + "!");
    ui->label_2->setText("Welcome back, " + firstName + " " + lastName + "!");
    ui->label_3->setText("Welcome back, " + firstName + " " + lastName + "!");
    QFont font = ui->label->font();
    font.setPointSize(24);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);
    ui->label_8->setFont(font);
    ui->gpaLabel->setFont(font);
    ui->absenceLabel->setFont(font);
    ui->feedbackLabel->setFont(font);
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

void LoggedInWindow::addUsersToComboBox()
{
    ui->comboBoxUsers->clear();
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    if(query.exec("SELECT username FROM users"))
    {
        while(query.next())
        {
            QString username = query.value(0).toString();
            ui->comboBoxUsers->addItem(username);
        }
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
    }
}

void LoggedInWindow::addUsersIDsToComboBox()
{
    ui->comboBoxGrades->clear();
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    if(query.exec("SELECT userID FROM users"))
    {
        while(query.next())
        {
            QString userID = query.value(0).toString();
            ui->comboBoxGrades->addItem(userID);
            ui->comboBoxFeedback->addItem(userID);
            ui->comboBoxAbsence->addItem(userID);
        }
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
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
        else if (clickedButton == ui->pushButtonAddFeedback)
        {
            gradesButtons->setStackedWidgetIndex(9);
        }
        else if (clickedButton == ui->pushButtonUpdateFeedback)
        {
            gradesButtons->setStackedWidgetIndex(10);
        }
        else if (clickedButton == ui->pushButtonDeleteFeedback)
        {
            gradesButtons->setStackedWidgetIndex(11);
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
    QString queryString = "SELECT u.userID, u.firstName, u.lastName, g.gradeID, g.subject, g.grade "
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
            QString gradeID = query.value(3).toString();
            QString subject = query.value(4).toString();
            QString gradeValue = query.value(5).toString();

            //If it's a new user, display the information for the previous user (if any)
            if (userID != currentUserID && !currentUserID.isEmpty())
            {
                QLabel *label = new QLabel(currentUserID + " " + currentName + " " + currentLastName + ": " + currentUserGrades);
                layout->addWidget(label);

                //Reset the information for the new user
                currentUserID = userID;
                currentName = firstName;
                currentLastName = lastName;
                currentUserGrades = subject + " (ID: " + gradeID + ") " + gradeValue; // Include gradeID
            }
            else // If it's the same user, append the grade to the current user's grades
            {
                currentUserGrades += "; (ID: " + gradeID + ") " + subject + " " + gradeValue; // Include gradeID before subject
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

void displayUsersInfo(const QString& selectedUsername, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch user information from the database
    QSqlQuery queryUsers;
    QString queryUsersString = "SELECT userID, firstName, lastName, email, grade, perms FROM users WHERE username = :username";
    queryUsers.prepare(queryUsersString);
    queryUsers.bindValue(":username", selectedUsername);

    if(queryUsers.exec())
    {
        //Create a new widget to display the user information
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results
        while (queryUsers.next())
        {
            QString userID = queryUsers.value(0).toString();
            QString firstName = queryUsers.value(1).toString();
            QString lastName = queryUsers.value(2).toString();
            QString email = queryUsers.value(3).toString();
            QString grade = queryUsers.value(4).toString();
            QString perms = queryUsers.value(5).toString();
            //QString lastActive = query.value(5).toString();
            // Retrieve other columns as needed

            // Create labels to display user information
            QLabel *userIDLabel = new QLabel("User ID: " + userID);
            QLabel *fullNameLabel = new QLabel("Name: " + firstName + " " + lastName);
            QLabel *emailLabel = new QLabel("Email: " + email);
            QLabel *gradeLabel = new QLabel("Grade: " + grade);
            QLabel *permsLabel = new QLabel("Perms: " + perms);
            //QLabel *lastActiveLabel = new QLabel("Last active: " + lastActive);
            /*
            QLabel *usernameLabel = new QLabel("Username: " + username);
            QLabel *permsLabel = new QLabel("Perms: " + perms);
            // Add other labels for additional information
*/

            // Add labels to the layout
            layout->addWidget(userIDLabel);
            layout->addWidget(fullNameLabel);
            layout->addWidget(emailLabel);
            layout->addWidget(gradeLabel);
            layout->addWidget(permsLabel);
            //layout->addWidget(lastActiveLabel);
            /*
            layout->addWidget(usernameLabel);
            layout->addWidget(permsLabel);
*/
            // Add other labels to display additional information

            // Set layout for the page
            page->setLayout(layout);
        }

        // Add the page to the stackedWidget and display it
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryUsers.lastError().text();
    }
}

void displayAllGrades(const QString& userID, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch grades information from the database
    QSqlQuery queryGrades;
    QString queryGradesString = "SELECT gradeID, subject, grade FROM grades WHERE userID = :userID";
    queryGrades.prepare(queryGradesString);
    queryGrades.bindValue(":userID", userID);

    if(queryGrades.exec())
    {
        // Create a new widget to display the grades information
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results
        while (queryGrades.next())
        {
            QString gradeID = queryGrades.value(0).toString();
            QString subject = queryGrades.value(1).toString();
            QString grade = queryGrades.value(2).toString();

            // Concatenate grade information into one label
            QString gradeInfo = "Grade ID: " + gradeID + ", Subject: " + subject + ", Grade: " + grade;
            QLabel *gradeInfoLabel = new QLabel(gradeInfo);

            // Add the concatenated label to the layout
            layout->addWidget(gradeInfoLabel);
        }

        // Set layout for the page
        page->setLayout(layout);

        // Add the page to the stackedWidget and display it
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryGrades.lastError().text();
    }
}

void displayFeedback(const QString& userID, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch feedback information from the database
    QSqlQuery queryFeedback;
    QString queryFeedbackString = "SELECT feedbackID, type, subject, reason FROM feedback WHERE userID = :userID";
    queryFeedback.prepare(queryFeedbackString);
    queryFeedback.bindValue(":userID", userID);

    if(queryFeedback.exec())
    {
        // Create a new widget to display the feedback information
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results
        while (queryFeedback.next())
        {
            QString feedbackID = queryFeedback.value(0).toString();
            QString type = queryFeedback.value(1).toString();
            QString subject = queryFeedback.value(2).toString();
            QString reason = queryFeedback.value(3).toString();

            // Concatenate feedback information except reason into one label
            QString feedbackInfo = "Feedback ID: " + feedbackID + ", Type: " + type + ", Subject: " + subject;
            QLabel *feedbackInfoLabel = new QLabel(feedbackInfo);

            // Create label for reason
            QLabel *reasonLabel = new QLabel("Reason: " + reason);

            // Add labels to the layout
            layout->addWidget(feedbackInfoLabel);
            layout->addWidget(reasonLabel);
        }

        // Set layout for the page
        page->setLayout(layout);

        // Add the page to the stackedWidget and display it
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryFeedback.lastError().text();
    }
}

void displayAbsence(const QString& userID, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch absence information from the database
    QSqlQuery queryAbsence;
    QString queryAbsenceString = "SELECT absenceID, subject, type FROM absences WHERE userID = :userID";
    queryAbsence.prepare(queryAbsenceString);
    queryAbsence.bindValue(":userID", userID);

    if(queryAbsence.exec())
    {
        // Create a new widget to display the absence information
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results
        while (queryAbsence.next())
        {
            QString absenceID = queryAbsence.value(0).toString();
            QString subject = queryAbsence.value(1).toString();
            QString type = queryAbsence.value(2).toString();

            // Concatenate absence information into one label
            QString absenceInfo = "Absence ID: " + absenceID + ", Subject: " + subject + ", Type: " + type;
            QLabel *absenceInfoLabel = new QLabel(absenceInfo);

            // Add the concatenated label to the layout
            layout->addWidget(absenceInfoLabel);
        }

        // Set layout for the page
        page->setLayout(layout);

        // Add the page to the stackedWidget and display it
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryAbsence.lastError().text();
    }
}

/*
void deleteAccount(const QString& userID)
{
    // Prepare the SQL query to delete the account
    QSqlQuery queryDeleteAccount;
    QString queryDeleteAccountString = "DELETE FROM users WHERE userID = :userID";
    queryDeleteAccount.prepare(queryDeleteAccountString);
    queryDeleteAccount.bindValue(":userID", userID);

    // Execute the query to delete the account
    if(queryDeleteAccount.exec())
    {
        QMessageBox::information(nullptr, "Account Deleted", "Account deleted successfully.");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Error deleting account: " + queryDeleteAccount.lastError().text());
    }
}
*/

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

void LoggedInWindow::setAverageGradeLabel() {
    User* user = new User;
    user->avgGrade(userID, ui->gpaLabel);
    delete user;
}

void LoggedInWindow::setAbsenceLabel() {
    User* user = new User;
    user->totalAbsences(userID, ui->absenceLabel);
    delete user;
}

void LoggedInWindow::setFeedbackLabel() {
    User* user = new User;
    user->totalFeedbacks(userID, ui->feedbackLabel);
    delete user;
}

void LoggedInWindow::onComboBoxUserChanged(int index)
{
    if (index >= 0)
    {
        QString selectedUsername = ui->comboBoxUsers->itemText(index);
        displayUsersInfo(selectedUsername, ui->stackedWidgetUserInfo);
    }
}

void LoggedInWindow::onComboBoxGradesChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxGrades->itemText(index);
        displayAllGrades(selectedGradeID, ui->stackedWidgetGrades);
    }
}

void LoggedInWindow::onComboBoxFeedbackChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxFeedback->itemText(index);
        displayFeedback(selectedGradeID, ui->stackedWidgetFeedback);
    }
}

void LoggedInWindow::onComboBoxAbsenceChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxAbsence->itemText(index);
        displayAbsence(selectedGradeID, ui->stackedWidgetAbsence);
    }
}
