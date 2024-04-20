#include "../include/db.h"
#include "../include/feedback.h"

void Feedbacks::addFeedback(int userID, const QString& subject, const QString& type, const QString& reason)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("INSERT INTO feedback (userID, subject, type, reason) VALUES (:userID, :subject, :type, :reason)");
    query.bindValue(":userID", userID);
    query.bindValue(":subject", subject);
    query.bindValue(":type", type);
    query.bindValue(":reason", reason);
    if (query.exec())
    {
        QMessageBox::information(nullptr, "Success", "Feedback added successfully!");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to add feedback");
    }
    delete db;
}

void Feedbacks::updateFeedback(int feedbackID, const QString& newType, const QString& newReason)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE feedback SET type = :type, reason = :reason WHERE feedbackID = :feedbackID");
    query.bindValue(":type", newType);
    query.bindValue(":reason", newReason);
    query.bindValue(":feedbackID", feedbackID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Feedback updated successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Feedback with ID " + QString::number(feedbackID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to update feedback");
    }
    delete db;
}

void Feedbacks::deleteFeedback(int feedbackID)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("DELETE FROM feedback WHERE feedbackID = :feedbackID");
    query.bindValue(":feedbackID", feedbackID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Feedback deleted successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Feedback with ID " + QString::number(feedbackID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to delete feedback");
    }
    delete db;
}
