#ifndef DB_H
#define DB_H

#include "pch.h"

class Database
{
public:
    Database();
    QSqlDatabase getDb();
    void openConnection();
    void closeConnection();
    ~Database();

private:
    QSqlDatabase db;
};

#endif // DB_H
