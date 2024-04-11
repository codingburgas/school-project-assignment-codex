#include "../include/db.h"

void addGrade(int userID, const QString& subject, int grade)
{
    Database db;
    QSqlDatabase database = db.getDb();
    QSqlQuery query(database);
    query.prepare("INSERT INTO grades (userID, subject, grade) VALUES (:userID, :subject, :grade)");
    query.bindValue(":userID", userID);
    query.bindValue(":subject", subject);
    query.bindValue(":grade", grade);
    if (!query.exec())
    {
        qDebug() << "Error inserting grade:" << query.lastError().text();
    }
}

void updateGrade(int gradeID, int newGrade)
{
    Database db;
    QSqlDatabase database = db.getDb();
    QSqlQuery query(database);
    query.prepare("UPDATE grades SET grade = :grade WHERE gradeID = :gradeID");
    query.bindValue(":grade", newGrade);
    query.bindValue(":gradeID", gradeID);
    if (!query.exec())
    {
        qDebug() << "Error updating grade:" << query.lastError().text();
    }
}

void deleteGrade(int gradeID) {
    Database db;
    QSqlDatabase database = db.getDb();
    QSqlQuery query(database);
    query.prepare("DELETE FROM grades WHERE gradeID = :gradeID");
    query.bindValue(":gradeID", gradeID);
    if (!query.exec())
    {
        qDebug() << "Error deleting grade:" << query.lastError().text();
    }
}
