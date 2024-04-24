#ifndef DB_H
#define DB_H

#include "../../business/include/pch.h"

// Contains the database methods (databaselib.lib).
class Database
{
public:
    // Constructor.
    Database();
    // Getter for the db object.
    QSqlDatabase getDb();
    // Method which opens the database connection.
    void openConnection();
    // Method which closes the database connection.
    void closeConnection();
    // Destructor.
    ~Database();

private:
    QSqlDatabase db;
};

#endif // DB_H
