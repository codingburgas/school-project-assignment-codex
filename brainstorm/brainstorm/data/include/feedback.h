#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "../../business/include/pch.h"

// Contains the feecback methods.
class Feedbacks {
public:
    // Adds a feedback to the database for a particuar user.
    void addFeedback(int userID, const QString& subject, const QString& type, const QString& reason);
    // Updates a feedback in the database for a particuar user.
    void updateFeedback(int feedbackID, const QString& newType, const QString& newReason);
    // Deletes a feedback in the database for a particuar user.
    void deleteFeedback(int feedbackID);
};

#endif // FEEDBACK_H
