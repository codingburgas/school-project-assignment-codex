#ifndef ADMIN_H
#define ADMIN_H

#include "pch.h"

void setPermissions(int userID, int perms, int loggedInUserID);
void addToGrade(int userID, QString grade, int loggedInUserID);

#endif // ADMIN_H
