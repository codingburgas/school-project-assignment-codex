#ifndef USER_H
#define USER_H

#include "../../business/include/pch.h"

// Contains the user methods.
class User {
public:
    // Retrieves a particular user's grades from the database.
    QList<int> retrieveGrades(int userID);
    // Retrieves a particular user's absences from the database.
    QList<float> retrieveAbsences(int userID);
    // Retrieves a particular user's feedbacks from the database.
    int retrieveFeedbacks(int userID);
    // Displays a particular user's GPA on a label.
    void avgGrade(int userID, QLabel* gpaLabel);
    // Displays a particular user's absences count on a label.
    void totalAbsences(int userID, QLabel* absencesLabel);
    // Displays a particular user's feedbacks count on a label.
    void totalFeedbacks(int userID, QLabel* feedbackLabel);
};

#endif // USER_H
