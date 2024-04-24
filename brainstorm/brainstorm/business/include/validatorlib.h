#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "pch.h"

// Contains the validation methods.
class Validator
{
public:
    // Checks if all fields are empty.
    bool areAllEmpty(const QString& firstName, const QString& lastName, const QString& email, const QString& username, const QString& password);
    // Validates the user's username.
    bool validateUsername(const QString& username);
    // Validates the user's password.
    bool validatePassword(const QString& password);
    // Validates the user's email.
    bool validateEmail(const QString& email);
    // Validates the user's first and last name.
    bool validateName(const QString& name);
    // Validates the user's ID.
    bool validateID(const QString& id);
};

#endif // VALIDATOR_H
