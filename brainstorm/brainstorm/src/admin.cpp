#include "../include/db.h"
#include "../include/admin.h"

void Admin::setPermissions(int userID, int perms, int loggedInUserID)
{
    if (userID == loggedInUserID)
    {
        QMessageBox::critical(nullptr, "Error", "Cannot update your own permissions");
        return;
    }

    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE users SET perms = :perms WHERE userID = :userID");
    query.bindValue(":userID", userID);
    query.bindValue(":perms", perms);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Permissions updated successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "User with userID " + QString::number(userID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to update permissions");
    }
    delete db;
}

void Admin::addToGrade(int userID, QString grade, int loggedInUserID)
{
    QSet<QString> validGrades = {"9A", "9B", "9V", "9G", "10A", "10B", "10V", "10G"};

    if (!validGrades.contains(grade))
    {
        QMessageBox::critical(nullptr, "Error", "Not a valid grade");
        return;
    }

    if (userID == loggedInUserID)
    {
        QMessageBox::critical(nullptr, "Error", "Cannot set grade on admin account");
        return;
    }

    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE users SET grade = :grade WHERE userID = :userID");
    query.bindValue(":userID", userID);
    query.bindValue(":grade", grade);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "User added to grade successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "User with userID " + QString::number(userID) + " does not exist in the database or user already has been set into grade");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed add user to grade");
        //QMessageBox::critical(nullptr, "Error", "Failed to execute query: " + query.lastError().text());
    }
    delete db;
}

