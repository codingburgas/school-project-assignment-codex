#include "../include/db.h"
#include "../include/grades.h"

void Grades::addGrade(int userID, const QString& subject, int grade)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("INSERT INTO grades (userID, subject, grade) VALUES (:userID, :subject, :grade)");
    query.bindValue(":userID", userID);
    query.bindValue(":subject", subject);
    query.bindValue(":grade", grade);
    if (query.exec())
    {
        QMessageBox::information(nullptr, "Success", "Grade added successfully!");
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to add grade");
    }
    delete db;
}

void Grades::updateGrade(int gradeID, int newGrade)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE grades SET grade = :grade WHERE gradeID = :gradeID");
    query.bindValue(":grade", newGrade);
    query.bindValue(":gradeID", gradeID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Grade updated successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Grade with ID " + QString::number(gradeID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to update grade");
    }
    delete db;
}


void Grades::deleteGrade(int gradeID) {
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QSqlQuery query(database);
    query.prepare("DELETE FROM grades WHERE gradeID = :gradeID");
    query.bindValue(":gradeID", gradeID);
    if (query.exec())
    {
        if (query.numRowsAffected() > 0)
        {
            QMessageBox::information(nullptr, "Success", "Grade deleted successfully!");
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "Grade with ID " + QString::number(gradeID) + " does not exist in the database");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to delete grade");
    }
    delete db;
}
