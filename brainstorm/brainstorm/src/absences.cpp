#include "../include/db.h"
#include "../include/absences.h"

// Adds an absence to the database for a particular user.
void Absences::addAbsence(int userID, const QString& subject, const QString& type)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("INSERT INTO absences (userID, subject, type) VALUES (:userID, :subject, :type)");
    query.bindValue(":userID", userID);
    query.bindValue(":subject", subject);
    query.bindValue(":type", type);
    if (query.exec())
    {
        QMessageBox::information(nullptr, "Success", "Absence added successfully!");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to add absence");
    }
    delete db;
}

// Updates an absence in the database for a particular user.
void Absences::updateAbsence(int absenceID, const QString& newType)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE absences SET type = :type WHERE absenceID = :absenceID");
    query.bindValue(":type", newType);
    query.bindValue(":absenceID", absenceID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Absence updated successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Absence with ID " + QString::number(absenceID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to update absence");
    }
    delete db;
}

// Deletes an absence in the database for a particular user.
void Absences::deleteAbsence(int absenceID)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("DELETE FROM absences WHERE absenceID = :absenceID");
    query.bindValue(":absenceID", absenceID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Absence deleted successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Absence with ID " + QString::number(absenceID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to delete absence");
    }
    delete db;
}
