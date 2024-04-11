#ifndef GRADES_H
#define GRADES_H

#include "../include/pch.h"

void addGrade(int userID, const QString& subject, int grade);
void updateGrade(int gradeID, int newGrade);
void deleteGrade(int gradeID);
double getGrade(int gradeID);

#endif // GRADES_H
