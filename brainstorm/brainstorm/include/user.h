#ifndef USER_H
#define USER_H

#include "pch.h"

class User {
public:
    QList<int> retrieveGrades(int userID);
    QList<float> retrieveAbsences(int userID);
    int retrieveFeedbacks(int userID);
    void avgGrade(int userID, QLabel* gpaLabel);
    void totalAbsences(int userID, QLabel* absencesLabel);
    void totalFeedbacks(int userID, QLabel* feedbackLabel);
};

#endif // USER_H
