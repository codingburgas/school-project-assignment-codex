#include "../include/db.h"
#include "../include/admin.h"

void setPermissions(int userID, int perms, int loggedInUserID)
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
