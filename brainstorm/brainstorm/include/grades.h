#ifndef GRADES_H
#define GRADES_H

#include "pch.h"

// Contains the grades methods.
class Grades {
public:
    // Adds a grade to the database for a particuar user.
    void addGrade(int userID, const QString& subject, int grade);
    // Updates a grade in the database for a particuar user.
    void updateGrade(int gradeID, int newGrade);
    // Deletes a grade in the database for a particuar user.
    void deleteGrade(int gradeID);
};

#endif // GRADES_H
