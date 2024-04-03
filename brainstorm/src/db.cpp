#include "./include/db.h"

Database::Database() {}

QSqlDatabase Database::getDb()
{
    return db;
}

void Database::openConnection()
{
    // Configure the database connection parameters
    QSqlDatabase db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("sql11.freemysqlhosting.net");
    db.setPort(3306);  // Default MySQL port
    db.setDatabaseName("sql11696216");
    db.setUserName("sql11696216");
    db.setPassword("Z2JUbIkKpS");

    // Open the database connection and handle success or failure
    if (db.open())
    {
        qDebug() << "Database connected successfully";
    }
    else
    {
        // Handle connection error
        qDebug() << "Database failed to connect";
        qDebug() << db.lastError().text();
    }
}

void Database::closeConnection()
{
    // Close the database connection
    db.close();
}
