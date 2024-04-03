#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QCryptographicHash>
#include <QDebug>
#include "./include/mainWindow.h"
#include "./include/db.h"
#include "./include/loggedInWindow.h"
#include "./include/loggedInWindowAdmin.h"
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
    QString password = ui->lineEditPassword->text();

    // Hash the entered password using SHA-256
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    Database* db = new Database;
    db->openConnection();
    QSqlQuery query;

    // Retrieve password and perms in a single query
    query.prepare("SELECT password, perms FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next())
    {
        QByteArray storedPassword = query.value("password").toByteArray();

        if (hashedPassword == storedPassword) {
            QMessageBox::information(this, "Login", "Logged in");

            int perms = query.value("perms").toInt(); // Get the permission value

            // Update lastActive with current date and time (UTC)
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

            // Prepare and execute update query
            query.prepare("UPDATE users SET lastActive = :lastActive WHERE username = :username");
            query.bindValue(":lastActive", formattedDateTime);
            query.bindValue(":username", username);

            if (!query.exec())
            {
                QMessageBox::warning(this, "Database Error", "Failed to update last active date: " + query.lastError().text());
            }

            // Open appropriate window based on perms
            if (perms == 0)
            {
                LoggedInWindow* loggedInWindow = new LoggedInWindow(this);
                loggedInWindow->show();
            }
            else if (perms == 1)
            {
                LoggedInWindowAdmin* loggedInWindowAdmin = new LoggedInWindowAdmin(this);
                loggedInWindowAdmin->show();
            }
            else
            {
                QMessageBox::warning(this, "Login", "Invalid permission level");
            }
;
        }
        else
        {
            QMessageBox::warning(this, "Login", "Login failed: Incorrect username or password");
            qDebug() << hashedPassword << " " << storedPassword;
        }
    }
    else
    {
        QMessageBox::warning(this, "Login", "Login failed: Username not found");
    }

    db->closeConnection();
}

void MainWindow::on_pushButtonDbDrivers_clicked()
{
    qDebug() << QSqlDatabase::drivers();
}

void MainWindow::on_pushButtonTestDb_clicked()
{
    Database* db = new Database;
    db->openConnection();

    QString firstName, lastName, email;

    QSqlQuery qry;
    qry.exec("SELECT * FROM users");

    while (qry.next())
    {
        firstName = qry.value("firstName").toString().toUtf8().constData();
        lastName = qry.value("lastName").toString().toUtf8().constData();
        email = qry.value("email").toString().toUtf8().constData();

        qDebug() << firstName << " " << lastName << " " << email;
    }

    db->closeConnection();
}

void MainWindow::on_pushButtonRegister_clicked()
{
    QString firstName = ui->lineEditFirstNameReg->text();
    QString lastName = ui->lineEditLastNameReg->text();
    QString email = ui->lineEditEmailReg->text();
    QString username = ui->lineEditUsernameReg->text();
    QString password = ui->lineEditPasswordReg->text();

    // Check if any of the input fields are empty
    if (firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Registration", "Please fill in all the fields");
        return;
    }

    // Check if email is in a valid format
    QRegularExpression emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
    if (!emailRegex.match(email).hasMatch())
    {
        QMessageBox::warning(this, "Registration", "Invalid email format");
        return;
    }

    // Check if username already exists in the database
    Database* db = new Database;
    db->openConnection();
    QSqlQuery usernameQuery;
    usernameQuery.prepare("SELECT username FROM users WHERE username = :username");
    usernameQuery.bindValue(":username", username);
    if (usernameQuery.exec() && usernameQuery.next())
    {
        QMessageBox::warning(this, "Registration", "Username already exists");
        db->closeConnection();
        delete db;
        return;
    }

    // Check if username already exists in the database
    QSqlQuery emailQuery;
    emailQuery.prepare("SELECT email FROM users WHERE email = :email");
    emailQuery.bindValue(":email", email);
    if (emailQuery.exec() && emailQuery.next())
    {
        QMessageBox::warning(this, "Registration", "Email is already in use");
        db->closeConnection();
        delete db;
        return;
    }

    // Check if username length is above 16 characters
    if (username.length() > 16)
    {
        QMessageBox::warning(this, "Registration", "Username must be 16 characters or less");
        db->closeConnection();
        delete db;
        return;
    }

    // Check if password meets requirements
    QRegularExpression uppercaseRegex("[A-Z]");
    QRegularExpression numberRegex("[0-9]");

    if (password.length() < 8 || !uppercaseRegex.match(password).hasMatch() || !numberRegex.match(password).hasMatch())
    {
        QMessageBox::warning(this, "Registration", "Password must be at least 8 characters long, contain at least one uppercase letter, and at least one number");
        db->closeConnection();
        delete db;
        return;
    }

    // Hash the password using SHA-256
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Proceed with registration
    QSqlQuery query;
    query.prepare("INSERT INTO users (firstName, lastName, email, username, password) VALUES (:firstName, :lastName, :email, :username, :password)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":email", email);
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);

    if (query.exec())
    {
        QMessageBox::information(this, "Registration", "Registration successful");
    }
    else
    {
        QMessageBox::warning(this, "Registration", "Registration failed: " + query.lastError().text());
    }

    db->closeConnection();
}



