#include "../../business/include/gradesButtons.h"
#include "../../data/include/absences.h"
#include "../../data/include/feedback.h"
#include "../../data/include/grades.h"
#include "../../data/include/admin.h"
#include "../../business/include/validatorlib.h"
#include "../../data/include/db.h"
#include "ui_gradesButtons.h"

// Constructor.
GradesButtons::GradesButtons(QWidget *parent, int userID)
    : QDialog(parent)
    , ui(new Ui::GradesButtons)
    , userID(userID)
{
    ui->setupUi(this);
    QIcon icon(":/assets/assets/icon.png");
    this->setWindowIcon(icon);
    setFixedSize(size());
    stackedWidgetIndex = 0;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndex);

    ui->comboBoxAbsenceType->addItem(QIcon(":/ico/assets/icons/absence.png"), "    Absence");
    ui->comboBoxAbsenceType->addItem(QIcon(":/ico/assets/icons/lateness.png"), "    Lateness");

    ui->comboBoxUpdateAbsence->addItem(QIcon(":/ico/assets/icons/absence.png"), "    Absence");
    ui->comboBoxUpdateAbsence->addItem(QIcon(":/ico/assets/icons/lateness.png"), "    Lateness");

    ui->comboBoxUpdateFeedback->addItem(QIcon(":/ico/assets/icons/remark.png"), "    Remark");
    ui->comboBoxUpdateFeedback->addItem(QIcon(":/ico/assets/icons/praise.png"), "    Praise");

    ui->comboBoxFeedbackType->addItem(QIcon(":/ico/assets/icons/remark.png"), "    Remark");
    ui->comboBoxFeedbackType->addItem(QIcon(":/ico/assets/icons/praise.png"), "    Praise");

    ui->comboBoxPermissionLevel->addItem("0");
    ui->comboBoxPermissionLevel->addItem("1");
    ui->comboBoxPermissionLevel->addItem("2");
    ui->comboBoxPermissionLevel->addItem("3");

    ui->comboBoxAddGrade->addItem("9A");
    ui->comboBoxAddGrade->addItem("9B");
    ui->comboBoxAddGrade->addItem("9V");
    ui->comboBoxAddGrade->addItem("9G");
    ui->comboBoxAddGrade->addItem("10A");
    ui->comboBoxAddGrade->addItem("10B");
    ui->comboBoxAddGrade->addItem("10V");
    ui->comboBoxAddGrade->addItem("10G");

    ui->comboBoxGrade->addItem(QIcon(":/ico/assets/icons/2.png"), "    2");
    ui->comboBoxGrade->addItem(QIcon(":/ico/assets/icons/3.png"), "    3");
    ui->comboBoxGrade->addItem(QIcon(":/ico/assets/icons/4.png"), "    4");
    ui->comboBoxGrade->addItem(QIcon(":/ico/assets/icons/5.png"), "    5");
    ui->comboBoxGrade->addItem(QIcon(":/ico/assets/icons/6.png"), "    6");

    ui->comboBoxNewGrade->addItem(QIcon(":/ico/assets/icons/2.png"), "    2");
    ui->comboBoxNewGrade->addItem(QIcon(":/ico/assets/icons/3.png"), "    3");
    ui->comboBoxNewGrade->addItem(QIcon(":/ico/assets/icons/4.png"), "    4");
    ui->comboBoxNewGrade->addItem(QIcon(":/ico/assets/icons/5.png"), "    5");
    ui->comboBoxNewGrade->addItem(QIcon(":/ico/assets/icons/6.png"), "    6");

    ui->comboSubject->addItem(QIcon(":/ico/assets/icons/chemistry.png"), "    Chemistry");
    ui->comboSubject->addItem(QIcon(":/ico/assets/icons/programming.png"), "    Programming");
    ui->comboSubject_2->addItem(QIcon(":/ico/assets/icons/chemistry.png"), "    Chemistry");
    ui->comboSubject_2->addItem(QIcon(":/ico/assets/icons/programming.png"), "    Programming");
    ui->comboBoxSubject->addItem(QIcon(":/ico/assets/icons/chemistry.png"), "    Chemistry");
    ui->comboBoxSubject->addItem(QIcon(":/ico/assets/icons/programming.png"), "    Programming");
}

// Destructor.
GradesButtons::~GradesButtons()
{
    delete ui;
}

// Sets the stacked widget index when called.
void GradesButtons::setStackedWidgetIndex(int index)
{
    stackedWidgetIndex = index;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndex);
}

// Method for adding grade actions.
void GradesButtons::on_pushButtonAddGrade_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Grades* gradeObj = new Grades;

    int userID = ui->lineEditUserID->text().toInt();
    QString subject = ui->comboBoxSubject->currentText();
    int grade = ui->comboBoxGrade->currentText().toInt();

    QString id = QString::number(userID);
    if (!validator->validateID(id))
    {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT userID FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec())
    {
        if (!query.next())
        {
            QMessageBox::warning(nullptr, "Validation", "User ID does not exist.");
            return;
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Failed to check User ID existence: " + query.lastError().text());
    }

    gradeObj->addGrade(userID, subject, grade);
    delete gradeObj;
    delete validator;
    delete db;
}

// Method for updating grade actions.
void GradesButtons::on_pushButtonUpdateGrade_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Grades* grade = new Grades;

    int gradeID = ui->lineEditGradeID->text().toInt();
    int newGrade = ui->comboBoxNewGrade->currentText().toInt();

    QString id = QString::number(gradeID);
    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT gradeID FROM grades WHERE gradeID = :gradeID");
    query.bindValue(":gradeID", gradeID);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "A grade with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Grade ID existence: " + query.lastError().text());
    }

    grade->updateGrade(gradeID, newGrade);
    delete grade;
    delete validator;
    delete db;
}

// Method for deleting grade actions.
void GradesButtons::on_pushButtonDeleteGrade_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Grades* grade = new Grades;

    int gradeIDdel = ui->lineEditGradeIDdel->text().toInt();

    QString id = QString::number(gradeIDdel);
    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT gradeID FROM grades WHERE gradeID = :gradeID");
    query.bindValue(":gradeID", gradeIDdel);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "A grade with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Grade ID existence: " + query.lastError().text());
    }

    grade->deleteGrade(gradeIDdel);
    delete grade;
    delete validator;
    delete db;
}

// Method which updates a particular user's permissions when the push button is clicked.
void GradesButtons::on_pushButtonUpdatePerms_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Admin* admin = new Admin;

    int userIDPerms = ui->lineEditUserIDPerms->text().toInt();
    int permsLevel = ui->comboBoxPermissionLevel->currentText().toInt();

    QString id = QString::number(userIDPerms);
    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT userID FROM users WHERE userID = :userID");
    query.bindValue(":userID", userIDPerms);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "User ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check User ID existence: " + query.lastError().text());
    }

    admin->setPermissions(userIDPerms, permsLevel, userID);
    delete admin;
    delete validator;
    delete db;
}

// Method which adds a particular user to a grade when the push button is clicked.
void GradesButtons::on_pushButtonAddToGrade_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Admin* admin = new Admin;

    int userIDAddToGrade = ui->lineEditUserIDGradeAdd->text().toInt();
    QString grade = ui->comboBoxAddGrade->currentText();
    QString id = QString::number(userIDAddToGrade);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT userID FROM users WHERE userID = :userID");
    query.bindValue(":userID", userIDAddToGrade);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "User ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check User ID existence: " + query.lastError().text());
    }

    admin->addToGrade(userIDAddToGrade, grade, userID);
    delete admin;
    delete validator;
    delete db;
}

// Method which adds an absence to a particular user when the push button is clicked.
void GradesButtons::on_pushButtonAddAbsence_2_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Absences* absence = new Absences;

    int userID = ui->lineEditUserID_2->text().toInt();
    QString subject = ui->comboSubject->currentText();
    QString type = ui->comboBoxAbsenceType->currentText();

    QString id = QString::number(userID);
    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT userID FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "User ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check User ID existence: " + query.lastError().text());
    }


    absence->addAbsence(userID, subject, type);
    delete absence;
    delete validator;
    delete db;
}

// Method which updates an absence of a particular user when the push button is clicked.
void GradesButtons::on_pushButtonUpdateAbsence_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Absences* absence = new Absences;

    int absenceID = ui->lineEditAbsenceID_2->text().toInt();
    QString newAbsence = ui->comboBoxUpdateAbsence->currentText();
    QString id = QString::number(absenceID);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT absenceID FROM absences WHERE absenceID = :absenceID");
    query.bindValue(":absenceID", absenceID);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "An absence with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Absence ID existence: " + query.lastError().text());
    }

    absence->updateAbsence(absenceID, newAbsence);
    delete absence;
    delete validator;
    delete db;
}

// Method which deletes an absence of a particular user when the push button is clicked.
void GradesButtons::on_pushButtonDeleteAbsence_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Absences* absence = new Absences;

    int absenceIDdel = ui->lineEditAbsenceIDdel->text().toInt();
    QString id = QString::number(absenceIDdel);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT absenceID FROM absences WHERE absenceID = :absenceID");
    query.bindValue(":absenceID", absenceIDdel);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "An absence with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Absence ID existence: " + query.lastError().text());
    }


    absence->deleteAbsence(absenceIDdel);
    delete absence;
    delete validator;
    delete db;
}

// Method which adds a feedback to a particular user when the push button is clicked.
void GradesButtons::on_pushButtonAddFeedback_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Feedbacks* feedback = new Feedbacks;

    int userID = ui->lineEditUserID_3->text().toInt();
    QString subject = ui->comboSubject_2->currentText();
    QString type = ui->comboBoxFeedbackType->currentText();
    QString reason = ui->lineEditReasonFeedback_12->text();
    QString id = QString::number(userID);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT userID FROM users WHERE userID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validation", "User ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check User ID existence: " + query.lastError().text());
    }


    feedback->addFeedback(userID, subject, type, reason);
    delete feedback;
    delete validator;
    delete db;
}

// Method which updates a feedback of a particular user when the push button is clicked.
void GradesButtons::on_pushButtonUpdateFeedback_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Feedbacks* feedback = new Feedbacks;

    int feedbackID = ui->lineEditFeedbackID->text().toInt();
    QString newType = ui->comboBoxUpdateFeedback->currentText();
    QString newReason = ui->lineEditNewReason->text();
    QString id = QString::number(feedbackID);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT feedbackID FROM feedback WHERE feedbackID = :feedbackID");
    query.bindValue(":feedbackID", feedbackID);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validator", "Feedback with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Feedback ID existence: " + query.lastError().text());
    }

    feedback->updateFeedback(feedbackID, newType, newReason);
    delete feedback;
    delete validator;
    delete db;
}

// Method which updates a feedback of a particular user when the push button is clicked.
void GradesButtons::on_pushButtonDeleteFeedback_clicked()
{
    Database* db = new Database;
    Validator* validator = new Validator;
    Feedbacks* feedback = new Feedbacks;
    int feedbackIDdel = ui->lineEditFeedbackIDdel->text().toInt();
    QString id = QString::number(feedbackIDdel);

    if (!validator->validateID(id)) {
        return;
    }

    QSqlQuery query(db->getDb());
    query.prepare("SELECT feedbackID FROM feedback WHERE feedbackID = :feedbackID");
    query.bindValue(":feedbackID", feedbackIDdel);

    if (query.exec()) {
        if (!query.next()) {
            QMessageBox::warning(nullptr, "Validator", "Feedback with this ID does not exist.");
            return;
        }
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Failed to check Feedback ID existence: " + query.lastError().text());
    }

    feedback->deleteFeedback(feedbackIDdel);
    delete feedback;
    delete validator;
    delete db;
}

// Method which deletes a particular user's account.
void GradesButtons::deleteAccount(int loggedInUserID)
{
    Database* db = new Database;
    QSqlDatabase database = db->getDb();
    QString userIDStr = ui->lineEditDeleteAccount->text();
    int userIDint = ui->lineEditDeleteAccount->text().toInt();

    if (userIDint == loggedInUserID)
    {
        QMessageBox::critical(nullptr, "Error", "Cannot delete your own account");
        return;
    }

    QSqlQuery query(database);
    database.transaction();

    // Check if the user exists
    query.prepare("SELECT COUNT(*) FROM users WHERE userID = :userID");
    query.bindValue(":userID", userIDint);
    if (!query.exec() || !query.first())
    {
        QMessageBox::critical(nullptr, "Error", "Database error occurred");
        database.rollback();
        return;
    }
    int userCount = query.value(0).toInt();
    if (userCount <= 0)
    {
        QMessageBox::critical(nullptr, "Error", "User with ID " + userIDStr + " does not exist");
        database.rollback();
        return;
    }

    // Delete referencing records in the grades table
    query.prepare("DELETE FROM grades WHERE userID = :userID");
    query.bindValue(":userID", userIDint);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Database error occurred while deleting referencing records from grades: " + query.lastError().text());
        database.rollback();
        return;
    }

    // Delete referencing records in the feedback table
    query.prepare("DELETE FROM feedback WHERE userID = :userID");
    query.bindValue(":userID", userIDint);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Database error occurred while deleting referencing records from feedback: " + query.lastError().text());
        database.rollback();
        return;
    }

    // Delete referencing records in the absences table
    query.prepare("DELETE FROM absences WHERE userID = :userID");
    query.bindValue(":userID", userIDint);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Database error occurred while deleting referencing records from absences: " + query.lastError().text());
        database.rollback();
        return;
    }

    // Delete the user's account
    query.prepare("DELETE FROM users WHERE userID = :userID");
    query.bindValue(":userID", userIDint);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Database error occurred while deleting user account: " + query.lastError().text());
        database.rollback();
        return;
    }

    database.commit();

    QMessageBox::information(nullptr, "Success", "User with ID " + userIDStr + " and associated records have been deleted successfully.");
}


// Method which deletes a particular user's account when the push button is clicked.
void GradesButtons::on_pushButtonDeleteAccount_clicked()
{
    deleteAccount(userID);
}

