#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "pch.h"

class Feedbacks {
public:
    void addFeedback(int userID, const QString& subject, const QString& type);
    void updateFeedback(int feedbackID, const QString& newType);
    void deleteFeedback(int feedbackID);
};

#endif // FEEDBACK_H
