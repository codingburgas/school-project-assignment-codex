#include "../../data/include/db.h"
#include "../../data/include/feedback.h"

// Adds a feedback to the database for a particuar user.
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

// Updates a feedback in the database for a particuar user.
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

// Deletes a feedback in the database for a particuar user.
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
