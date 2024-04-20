#ifndef ABSENCES_H
#define ABSENCES_H

#include "pch.h"

class Absences {
public:
    void addAbsence(int userID, const QString& subject, const QString& type);
    void updateAbsence(int absenceID, const QString& newType);
    void deleteAbsence(int absenceID);
};

#endif // ABSENCES_H
