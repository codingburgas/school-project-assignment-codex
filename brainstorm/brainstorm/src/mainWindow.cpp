#include "../include/mainWindow.h"
#include "../include/db.h"
#include "../include/loggedInWindow.h"
#include "../include/validatorlib.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(size()); // Set fixed size

    QIcon icon("../assets/icon.png");
    this->setWindowIcon(icon);
    QPixmap logo("../assets/logo.png");
    ui->labelLogo->setPixmap(logo);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    Database* db = new Database;

    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    // Hash the entered password using SHA-256
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    db->openConnection();
    QSqlQuery query;

    // Retrieve password and perms in a single query
    query.prepare("SELECT password, perms FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next())
    {
        QByteArray storedPassword = query.value("password").toByteArray();

        if (hashedPassword == storedPassword) {
            QMessageBox::information(this, "Login", "Logged in.");

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

            LoggedInWindow* loggedInWindow = new LoggedInWindow(this, username, perms);
            loggedInWindow->show();
        }
        else
        {
            QMessageBox::warning(this, "Login", "Login failed: Incorrect username or password.");
            qDebug() << hashedPassword << " " << storedPassword;
        }
    }
    else
    {
        QMessageBox::warning(this, "Login", "Login failed: Username not found.");
    }

    db->closeConnection();
    delete db;
}

void MainWindow::on_pushButtonRegister_clicked()
{
    Validator* validator = new Validator;

    QString firstName = ui->lineEditFirstNameReg->text();
    QString lastName = ui->lineEditLastNameReg->text();
    QString email = ui->lineEditEmailReg->text();
    QString username = ui->lineEditUsernameReg->text();
    QString password = ui->lineEditPasswordReg->text();

    if (validator->areAllEmpty(firstName, lastName, email, username, password) || !validator->validateEmail(email) || !validator->validateUsername(username)
        || !validator->validatePassword(password) || (!validator->validateName(firstName) || !validator->validateName(lastName))) {
        return;
    }

    // Check if email already exists in the database
    Database* db = new Database;
    db->openConnection();
    QSqlQuery emailQuery;
    emailQuery.prepare("SELECT email FROM users WHERE email = :email");
    emailQuery.bindValue(":email", email);
    if (emailQuery.exec() && emailQuery.next()) {
        QMessageBox::warning(this, "Registration", "Email is already in use.");
        db->closeConnection();
        delete db;
        return;
    }

    // Check if username already exists in the database
    QSqlQuery usernameQuery;
    usernameQuery.prepare("SELECT username FROM users WHERE username = :username");
    usernameQuery.bindValue(":username", username);

    if (usernameQuery.exec() && usernameQuery.next()) {
        QMessageBox::warning(this, "Registration", "Username already exists.");
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

    if (query.exec()) {
        QMessageBox::information(this, "Registration", "Registration successful.");
    }
    else {
        QMessageBox::warning(this, "Registration", "Registration failed: " + query.lastError().text());
    }

    db->closeConnection();
    delete db;
}

void MainWindow::on_switchFormButton_clicked()
{
    if (ui->stackedWidget->currentIndex() == 0) {
        ui->stackedWidget->setCurrentIndex(1);
        ui->switchFormButton->setText("Create your account.");
    }
    else {
        ui->stackedWidget->setCurrentIndex(0);
        ui->switchFormButton->setText("Back to login page.");
    }
}
