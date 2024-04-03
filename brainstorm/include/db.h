#ifndef DB_H
#define DB_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class Database
{

public:
    Database();
    QSqlDatabase getDb();
    void openConnection();
    void closeConnection();

private:
    QSqlDatabase db;

};

#endif // DB_H
