#ifndef GRADES_H
#define GRADES_H

#include "pch.h"

class Grades {
public:
    void addGrade(int userID, const QString& subject, int grade);
    void updateGrade(int gradeID, int newGrade);
    void deleteGrade(int gradeID);
};

#endif // GRADES_H
