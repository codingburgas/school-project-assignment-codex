#include "../include/loggedInWindow.h"
#include "../include/gradesButtons.h"
#include "../include/user.h"
#include "../include/db.h"
#include "ui_loggedInWindow.h"

// Constructor.
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
    setFixedSize(size());

    checkPermissions();
    addUsersToComboBox();
    addUsersIDsToComboBox();

    // Sets background image and makes it transparent.
    QPixmap backgroundImage(":/assets/assets/background.jpg");
    ui->backgroundLabel->setPixmap(backgroundImage);
    ui->backgroundLabel->setScaledContents(true); // Scale the image to fit the label.
    ui->backgroundLabel->setStyleSheet("background-color: rgba(255, 255, 255, 1);"); // Set transparency.

    // Connect button signals to handleButtonClick slot.
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
    connect(ui->pushButtonAddAbsence_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateAbsence_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteAbsence_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonAddFeedback_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonUpdateFeedback_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteFeedback_2, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);
    connect(ui->pushButtonDeleteAccount, &QPushButton::clicked, this, &LoggedInWindow::handleButtonClick);

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

    QPixmap pixmap(":/assets/assets/logo.png");

    // Set the pixmap to the QLabel.
    ui->label_logo->setPixmap(pixmap);
    ui->label_logo_2->setPixmap(pixmap);
    ui->label_logo_7->setPixmap(pixmap);


    ui->label->setText("<b>Welcome back, " + firstName + " " + lastName + "!</b>");
    ui->label_2->setText("<b>Welcome back, " + firstName + " " + lastName + "!</b>");

    QFont font = ui->label->font();
    font.setPointSize(24);

    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);
    ui->label_53->setFont(font);
    ui->gpaLabel->setFont(font);
    ui->absenceLabel->setFont(font);
    ui->feedbackLabel->setFont(font);
}

// Destructor.
LoggedInWindow::~LoggedInWindow()
{
    delete ui;
}

// Checks the particular user's permissions.
void LoggedInWindow::checkPermissions()
{
    // Based on the permission level, set the initial stacked widget index.
    if (perms == 1)
    {
        ui->stackedWidget->setCurrentIndex(1); // Index of the page for permission level 1.
    }
    else if (perms == 2)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0); // Index of the page other permission level 0.
    }
}

// Adds the users to a drop down menu (combo box).
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

// Adds the users' IDs to a drop down menu (combo box).
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

// Handles buttons' actions when clicked.
void LoggedInWindow::handleButtonClick()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton)
    {
        GradesButtons* gradesButtons = new GradesButtons(this, userID);

        if (clickedButton == ui->pushButtonAddGrade || clickedButton == ui->pushButtonAddGrade_2)
        {
            // Pass index to GradesButtons constructor.
            gradesButtons->setStackedWidgetIndex(0);
        }
        else if (clickedButton == ui->pushButtonAddToGrade)
        {
            gradesButtons->setStackedWidgetIndex(1);
        }
        else if (clickedButton == ui->pushButtonDeleteAccount)
        {
            gradesButtons->setStackedWidgetIndex(2);
        }
        else if (clickedButton == ui->pushButtonUpdateGrade || clickedButton == ui->pushButtonUpdateGrade_2)
        {
            gradesButtons->setStackedWidgetIndex(3);
        }
        else if (clickedButton == ui->pushButtonAddPerms)
        {
            gradesButtons->setStackedWidgetIndex(4);
        }
        else if (clickedButton == ui->pushButtonDeleteGrade || clickedButton == ui->pushButtonDeleteGrade_2)
        {
            gradesButtons->setStackedWidgetIndex(5);
        }
        else if (clickedButton == ui->pushButtonAddAbsence)
        {
            gradesButtons->setStackedWidgetIndex(6);
        }
        else if (clickedButton == ui->pushButtonAddAbsence_2)
        {
            gradesButtons->setStackedWidgetIndex(6);
        }
        else if (clickedButton == ui->pushButtonUpdateAbsence)
        {
            gradesButtons->setStackedWidgetIndex(7);
        }
        else if (clickedButton == ui->pushButtonUpdateAbsence_2)
        {
            gradesButtons->setStackedWidgetIndex(7);
        }
        else if (clickedButton == ui->pushButtonDeleteAbsence)
        {
            gradesButtons->setStackedWidgetIndex(8);
        }
        else if (clickedButton == ui->pushButtonDeleteAbsence_2)
        {
            gradesButtons->setStackedWidgetIndex(8);
        }
        else if (clickedButton == ui->pushButtonAddFeedback)
        {
            gradesButtons->setStackedWidgetIndex(9);
        }
        else if (clickedButton == ui->pushButtonAddFeedback_2)
        {
            gradesButtons->setStackedWidgetIndex(9);
        }
        else if (clickedButton == ui->pushButtonUpdateFeedback)
        {
            gradesButtons->setStackedWidgetIndex(10);
        }
        else if (clickedButton == ui->pushButtonUpdateFeedback_2)
        {
            gradesButtons->setStackedWidgetIndex(10);
        }
        else if (clickedButton == ui->pushButtonDeleteFeedback)
        {
            gradesButtons->setStackedWidgetIndex(11);
        }
        else if (clickedButton == ui->pushButtonDeleteFeedback_2)
        {
            gradesButtons->setStackedWidgetIndex(11);
        }

        gradesButtons->show();
    }
}

// Displays the particular user with their grade.
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
        //Create a new widget to display the results.
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

            //If it's a new user, display the information for the previous user (if any).
            if (userID != currentUserID && !currentUserID.isEmpty())
            {
                QLabel *label = new QLabel(currentUserID + " " + currentName + " " + currentLastName + ": " + currentUserGrades);
                layout->addWidget(label);

                //Reset the information for the new user.
                currentUserID = userID;
                currentName = firstName;
                currentLastName = lastName;
                currentUserGrades = subject + " (ID: " + gradeID + ") " + gradeValue; // Include gradeID.
            }
            // If it's the same user, append the grade to the current user's grades.
            else
            {
                currentUserGrades += "; (ID: " + gradeID + ") " + subject + " " + gradeValue; // Include gradeID before subject.
            }

            //Update the current user's information.
            currentUserID = userID;
            currentName = firstName;
            currentLastName = lastName;
        }

        // Display the last user's information.
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

// Displays the particular user's with their information.
void displayUsersInfo(const QString& selectedUsername, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget.
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch user information from the database.
    QSqlQuery queryUsers;
    QString queryUsersString = "SELECT userID, firstName, lastName, email, grade, perms FROM users WHERE username = :username";
    queryUsers.prepare(queryUsersString);
    queryUsers.bindValue(":username", selectedUsername);

    if(queryUsers.exec())
    {
        // Create a new widget to display the user information.
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results.
        while (queryUsers.next())
        {
            QString userID = queryUsers.value(0).toString();
            QString firstName = queryUsers.value(1).toString();
            QString lastName = queryUsers.value(2).toString();
            QString email = queryUsers.value(3).toString();
            QString grade = queryUsers.value(4).toString();
            QString perms = queryUsers.value(5).toString();

            // Create labels to display user information.
            QLabel *userIDLabel = new QLabel("User ID: " + userID);
            QLabel *fullNameLabel = new QLabel("Name: " + firstName + " " + lastName);
            QLabel *emailLabel = new QLabel("Email: " + email);
            QLabel *gradeLabel = new QLabel("Grade: " + grade);
            QLabel *permsLabel = new QLabel("Perms: " + perms);

            // Add labels to the layout.
            layout->addWidget(userIDLabel);
            layout->addWidget(fullNameLabel);
            layout->addWidget(emailLabel);
            layout->addWidget(gradeLabel);
            layout->addWidget(permsLabel);

            page->setLayout(layout);
        }

        // Add the page to the stackedWidget and display it.
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryUsers.lastError().text();
    }
}

// Displays a particular user's grades.
void displayAllGrades(const QString& userID, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget.
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch grades information from the database.
    QSqlQuery queryGrades;
    QString queryGradesString = "SELECT gradeID, subject, grade FROM grades WHERE userID = :userID";
    queryGrades.prepare(queryGradesString);
    queryGrades.bindValue(":userID", userID);

    if(queryGrades.exec())
    {
        // Create a new widget to display the grades information.
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results.
        while (queryGrades.next())
        {
            QString gradeID = queryGrades.value(0).toString();
            QString subject = queryGrades.value(1).toString();
            QString grade = queryGrades.value(2).toString();

            QString gradeInfo = "Grade ID: " + gradeID + ", Subject: " + subject + ", Grade: " + grade;
            QLabel *gradeInfoLabel = new QLabel(gradeInfo);

            layout->addWidget(gradeInfoLabel);
        }

        page->setLayout(layout);

        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryGrades.lastError().text();
    }
}

// Displays a particular user's feedbacks.
void displayFeedback(const QString& userID, QStackedWidget *stackedWidget)
{
    // Clear existing widgets in the stackedWidget.
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Fetch feedback information from the database.
    QSqlQuery queryFeedback;
    QString queryFeedbackString = "SELECT feedbackID, type, subject, reason FROM feedback WHERE userID = :userID";
    queryFeedback.prepare(queryFeedbackString);
    queryFeedback.bindValue(":userID", userID);

    if (queryFeedback.exec())
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        // Iterate over the results.
        while (queryFeedback.next())
        {
            QString feedbackID = queryFeedback.value(0).toString();
            QString type = queryFeedback.value(1).toString();
            QString subject = queryFeedback.value(2).toString();
            QString reason = queryFeedback.value(3).toString();
            QString feedbackInfo = "Feedback ID: " + feedbackID + ", Type: " + type + ", Subject: " + subject;

            QLabel* feedbackInfoLabel = new QLabel(feedbackInfo);
            QLabel* reasonLabel = new QLabel("Reason: " + reason);

            layout->addWidget(feedbackInfoLabel);
            layout->addWidget(reasonLabel);
        }

        page->setLayout(layout);

        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryFeedback.lastError().text();
    }
}

// Displays a particular user's absences.
void displayAbsence(const QString& userID, QStackedWidget *stackedWidget)
{
    while (stackedWidget->count() > 0)
    {
        QWidget *widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        delete widget;
    }

    QSqlQuery queryAbsence;
    QString queryAbsenceString = "SELECT absenceID, subject, type FROM absences WHERE userID = :userID";
    queryAbsence.prepare(queryAbsenceString);
    queryAbsence.bindValue(":userID", userID);

    if (queryAbsence.exec())
    {
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        layout->setSpacing(1);

        while (queryAbsence.next())
        {
            QString absenceID = queryAbsence.value(0).toString();
            QString subject = queryAbsence.value(1).toString();
            QString type = queryAbsence.value(2).toString();
            QString absenceInfo = "Absence ID: " + absenceID + ", Subject: " + subject + ", Type: " + type;

            QLabel *absenceInfoLabel = new QLabel(absenceInfo);

            layout->addWidget(absenceInfoLabel);
        }

        page->setLayout(layout);
        stackedWidget->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << queryAbsence.lastError().text();
    }
}

// Displays a particular user's grades.
void displayGrades(QStackedWidget *stackedWidgetChemistry, int userID)
{
    while (stackedWidgetChemistry->count() > 0)
    {
        QWidget *widget = stackedWidgetChemistry->widget(0);
        stackedWidgetChemistry->removeWidget(widget);
        delete widget;
    }

    QSqlQuery query;
    QString queryString = "SELECT g.subject, g.grade "
                          "FROM users u "
                          "LEFT JOIN grades g ON u.userID = g.userID "
                          "WHERE u.userID = :userID";

    query.prepare(queryString);
    query.bindValue(":userID", userID);

    if(query.exec())
    {
        // Create a new widget to display the results.
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        while (query.next())
        {
            QString subject = query.value(0).toString();
            QString gradeValue = query.value(1).toString();

            QLabel *label = new QLabel(subject + " - " + gradeValue);
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

// Displays a particular user's absences.
void displayAbsences(QStackedWidget *stackedWidgetChemistry, int userID)
{
    while (stackedWidgetChemistry->count() > 0)
    {
        QWidget *widget = stackedWidgetChemistry->widget(0);
        stackedWidgetChemistry->removeWidget(widget);
        delete widget;
    }

    QSqlQuery query;
    QString queryString = "SELECT a.subject, a.type "
                          "FROM absences a "
                          "WHERE a.userID = :userID";

    query.prepare(queryString);
    query.bindValue(":userID", userID);

    if(query.exec())
    {
        // Create a new widget to display the results.
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        while (query.next())
        {
            QString subject = query.value(0).toString();
            QString type = query.value(1).toString();

            QLabel *label = new QLabel(subject + " - " + type);
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

// Displays a particular user's feedbacks.
void displayFeedbacks(QStackedWidget *stackedWidgetFeedback, int userID)
{
    while (stackedWidgetFeedback->count() > 0)
    {
        QWidget *widget = stackedWidgetFeedback->widget(0);
        stackedWidgetFeedback->removeWidget(widget);
        delete widget;
    }

    QSqlQuery query;
    QString queryString = "SELECT f.type, f.subject, f.reason "
                          "FROM feedback f "
                          "WHERE f.userID = :userID";

    query.prepare(queryString);
    query.bindValue(":userID", userID);

    if(query.exec())
    {
        // Create a new widget to display the results
        QWidget *page = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout();

        while (query.next())
        {
            QString type = query.value(0).toString();
            QString subject = query.value(1).toString();
            QString reason = query.value(2).toString();

            QLabel *label = new QLabel(type + " - " + subject + " - " + reason);
            layout->addWidget(label);
        }

        page->setLayout(layout);
        stackedWidgetFeedback->addWidget(page);
        page->show();
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError().text();
    }
}

// Table widget cell actions.
void LoggedInWindow::on_tableWidget_2_cellClicked(int row, int column)
{
    if (ui->tableWidget_2->item(row, column) == nullptr)
    {
        return;
    }

    // Get the text of the clicked cell.
    QString grade = ui->tableWidget_2->item(row, column)->text();
    qDebug() << "Clicked Grade:" << grade;

    // Display users with the clicked grade.
    displayUsersWithGrade(ui->stackedWidgetChemistry, grade);
}

// Displays the particular user's average grade on a label.
void LoggedInWindow::setAverageGradeLabel() {
    User* user = new User;
    user->avgGrade(userID, ui->gpaLabel);
    delete user;
}

// Displays the particular user's absences on a label.
void LoggedInWindow::setAbsenceLabel() {
    User* user = new User;
    user->totalAbsences(userID, ui->absenceLabel);
    delete user;
}

// Displays the particular user's feedbacks on a label.
void LoggedInWindow::setFeedbackLabel() {
    User* user = new User;
    user->totalFeedbacks(userID, ui->feedbackLabel);
    delete user;
}

// Changes the user on the combo box.
void LoggedInWindow::onComboBoxUserChanged(int index)
{
    if (index >= 0)
    {
        QString selectedUsername = ui->comboBoxUsers->itemText(index);
        displayUsersInfo(selectedUsername, ui->stackedWidgetUserInfo);
    }
}

// Changes the user's grades on the combo box.
void LoggedInWindow::onComboBoxGradesChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxGrades->itemText(index);
        displayAllGrades(selectedGradeID, ui->stackedWidgetGrades);
    }
}

// Changes the user's feedbacks on the combo box.
void LoggedInWindow::onComboBoxFeedbackChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxFeedback->itemText(index);
        displayFeedback(selectedGradeID, ui->stackedWidgetFeedback);
    }
}

// Changes the user's absences on the combo box.
void LoggedInWindow::onComboBoxAbsenceChanged(int index)
{
    if (index >= 0)
    {
        QString selectedGradeID = ui->comboBoxAbsence->itemText(index);
        displayAbsence(selectedGradeID, ui->stackedWidgetAbsence);
    }
}

// Shows the GPA of the user on the tab widget in the user menu.
void LoggedInWindow::showFirstPage() {
    displayGrades(ui->stackedWidget_2, userID);
}

// Shows the absences of the user on the tab widget in the user menu.
void LoggedInWindow::showSecondPage() {
    displayAbsences(ui->stackedWidget_2, userID);
}

// Shows the feedbacks of the user on the tab widget in the user menu.
void LoggedInWindow::showThirdPage() {
    displayFeedbacks(ui->stackedWidget_2, userID);
}

// Grades actions when clicked.
void LoggedInWindow::on_gradesButton_clicked() {
    ui->stackedWidget_2->setCurrentIndex(0);
    displayGrades(ui->stackedWidget_2, userID);
}

// Absences actions when clicked.
void LoggedInWindow::on_absencesButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    displayAbsences(ui->stackedWidget_2, userID);
}

// Feedback actions when clicked.
void LoggedInWindow::on_feedbacksButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    displayFeedbacks(ui->stackedWidget_2, userID);
}
