#ifndef ADMIN_H
#define ADMIN_H

#include "pch.h"

// Contains the administrator methods.
class Admin {
public:
    // Sets a permission level for a particular user.
    void setPermissions(int userID, int perms, int loggedInUserID);
    // Adds a user to a grade in the database.
    void addToGrade(int userID, QString grade, int loggedInUserID);
};

#endif // ADMIN_H
