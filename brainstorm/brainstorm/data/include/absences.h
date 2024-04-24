#ifndef ABSENCES_H
#define ABSENCES_H

#include "../../business/include/pch.h"

// Contains the absence methods.
class Absences {
public:
    // Adds an absence to the database for a particular user.
    void addAbsence(int userID, const QString& subject, const QString& type);
    // Updates an absence in the database for a particular user.
    void updateAbsence(int absenceID, const QString& newType);
    // Deletes an absence in the database for a particular user.
    void deleteAbsence(int absenceID);
};

#endif // ABSENCES_H
