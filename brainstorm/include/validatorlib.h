#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QRegularExpression>
#include <QMessageBox>
#include <QString>
#include <QDebug>


class Validator
{
public:
    bool areAllEmpty(const QString& firstName, const QString& lastName, const QString& email, const QString& username, const QString& password);
    bool validateUsername(const QString& username);
    bool validatePassword(const QString& password);
    bool validateEmail(const QString& email);
    bool validateName(const QString& name);
};

#endif // VALIDATOR_H
