#include "../../data/include/user.h"

// Retrieves a particular user's grades from the database.
QList<int> User::retrieveGrades(int userID) {
    QList<int> grades;

    QSqlQuery query;
    query.prepare("SELECT grade FROM grades WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec()) {
        while (query.next()) {
            grades.append(query.value(0).toInt());
        }
    } else {
        qDebug() << "Error retrieving grades for user ID: " << userID << ", Error: " << query.lastError().text();
    }

    return grades;
}

// Retrieves a particular user's absences from the database.
QList<float> User::retrieveAbsences(int userID) {
    QList<float> absences;

    QSqlQuery query;
    query.prepare("SELECT type FROM absences WHERE userID = :userID");

    query.bindValue(":userID", userID);

    if (query.exec()) {
        while (query.next())
        {
            QString type = query.value(0).toString();
            if (type == "    Absence")
            {
                absences.append(1);
            }
            else if (type == "    Lateness")
            {
                absences.append(0.5);
            }
        }
    } else {
        qDebug() << "Error retrieving absences for user ID: " << userID << ", Error: " << query.lastError().text();
    }

    return absences;
}

// Retrieves a particular user's feedbacks from the database.
int User::retrieveFeedbacks(int userID) {
    int feedbackCount = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM feedback WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec()) {
        if (query.next()) {
            feedbackCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error retrieving feedback count for user ID: " << userID << ", Error: " << query.lastError().text();
    }

    return feedbackCount;
}

// Displays a particular user's GPA on a label.
void User::avgGrade(int userID, QLabel* gpaLabel) {
    QList<int> grades = retrieveGrades(userID);

    if (grades.isEmpty()) {
        gpaLabel->setText("No grades found for user.");
    } else {
        int totalSum = 0;
        for (int grade : grades) {
            totalSum += grade;
        }

        double averageGrade = static_cast<double>(totalSum) / grades.size();

        gpaLabel->setText(QString("%1").arg(averageGrade, 0, 'f', 2));
    }
}

// Displays a particular user's absences count on a label.
void User::totalAbsences(int userID, QLabel* absencesLabel) {
    QList<float> absences = retrieveAbsences(userID);
    double total = 0.0;

    for (double type : absences) {
        total += type;
    }

    absencesLabel->setText(QString("%1").arg(total));
}

// Displays a particular user's feedbacks count on a label.
void User::totalFeedbacks(int userID, QLabel* feedbackLabel) {
    int feedbackCount = retrieveFeedbacks(userID);

    feedbackLabel->setText(QString("%1").arg(feedbackCount));
}

