#include "../include/gradesButtons.h"
#include "../include/absences.h"
#include "../include/feedback.h"
#include "../include/grades.h"
#include "../include/admin.h"
#include "ui_gradesButtons.h"

GradesButtons::GradesButtons(QWidget *parent, int userID)
    : QDialog(parent)
    , ui(new Ui::GradesButtons)
    , userID(userID)
{
    ui->setupUi(this);
    QIcon icon("../assets/icon.png");
    this->setWindowIcon(icon);
    // Initialize stackedWidgetIndex to 0 or any default value
    stackedWidgetIndex = 0;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndex);

    ui->comboBoxAbsenceType->addItem("Absence");
    ui->comboBoxAbsenceType->addItem("Lateness");

    ui->comboBoxUpdateAbsence->addItem("Absence");
    ui->comboBoxUpdateAbsence->addItem("Lateness");

    ui->comboBoxUpdateFeedback->addItem("Remark");
    ui->comboBoxUpdateFeedback->addItem("Praise");

    ui->comboBoxFeedbackType->addItem("Remark");
    ui->comboBoxFeedbackType->addItem("Praise");

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

    ui->comboBoxGrade->addItem("2");
    ui->comboBoxGrade->addItem("3");
    ui->comboBoxGrade->addItem("4");
    ui->comboBoxGrade->addItem("5");
    ui->comboBoxGrade->addItem("6");

    ui->comboBoxNewGrade->addItem("2");
    ui->comboBoxNewGrade->addItem("3");
    ui->comboBoxNewGrade->addItem("4");
    ui->comboBoxNewGrade->addItem("5");
    ui->comboBoxNewGrade->addItem("6");

    ui->comboSubject->addItem("Chemistry");
    ui->comboSubject->addItem("Programming");
    ui->comboSubject_2->addItem("Chemistry");
    ui->comboSubject_2->addItem("Programming");
    ui->comboBoxSubject->addItem("Chemistry");
    ui->comboBoxSubject->addItem("Programming");
}

GradesButtons::~GradesButtons()
{
    delete ui;
}

void GradesButtons::setStackedWidgetIndex(int index)
{
    stackedWidgetIndex = index;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndex);
}


void GradesButtons::on_pushButtonAddGrade_clicked()
{
    Grades* gradeObj = new Grades;
    int userID = ui->lineEditUserID->text().toInt();
    //QString subject = ui->lineEditSubject->text();
    //int grade = ui->lineEditGrade->text().toInt();
    QString subject = ui->comboBoxSubject->currentText();
    int grade = ui->comboBoxGrade->currentText().toInt();

    gradeObj->addGrade(userID, subject, grade);
    delete gradeObj;
}


void GradesButtons::on_pushButtonUpdateGrade_clicked()
{
    Grades* grade = new Grades;
    int gradeID = ui->lineEditGradeID->text().toInt();
    //int newGrade = ui->lineEditnewGrade->text().toInt();
    int newGrade = ui->comboBoxNewGrade->currentText().toInt();

    grade->updateGrade(gradeID, newGrade);
    delete grade;
}


void GradesButtons::on_pushButtonDeleteGrade_clicked()
{
    Grades* grade = new Grades;
    int gradeIDdel = ui->lineEditGradeIDdel->text().toInt();

    grade->deleteGrade(gradeIDdel);
    delete grade;
}




void GradesButtons::on_pushButtonUpdatePerms_clicked()
{
    Admin* admin = new Admin;
    int userIDPerms = ui->lineEditUserIDPerms->text().toInt();
    //int permsLevel = ui->lineEditPermsLevel->text().toInt();
    int permsLevel = ui->comboBoxPermissionLevel->currentText().toInt();

    admin->setPermissions(userIDPerms, permsLevel, userID);
    delete admin;
}


void GradesButtons::on_pushButtonAddToGrade_clicked()
{
    Admin* admin = new Admin;
    int userIDAddToGrade = ui->lineEditUserIDGradeAdd->text().toInt();
    //QString grade = ui->lineEditAddToGrade->text();
    QString grade = ui->comboBoxAddGrade->currentText();

    admin->addToGrade(userIDAddToGrade, grade, userID);
    delete admin;
}

void GradesButtons::on_pushButtonAddAbsence_2_clicked()
{
    Absences* absence = new Absences;
    int userID = ui->lineEditUserID_2->text().toInt();
    //QString subject = ui->lineEditSubject_2->text();
    //QString type = ui->lineEditAbsence->text();
    QString subject = ui->comboSubject->currentText();
    QString type = ui->comboBoxAbsenceType->currentText();

    absence->addAbsence(userID, subject, type);
    delete absence;
}


void GradesButtons::on_pushButtonUpdateAbsence_clicked()
{
    Absences* absence = new Absences;
    int absenceID = ui->lineEditAbsenceID_2->text().toInt();
    //QString newAbsence = ui->lineEditNewAbsence->text();
    QString newAbsence = ui->comboBoxUpdateAbsence->currentText();

    absence->updateAbsence(absenceID, newAbsence);
    delete absence;
}

void GradesButtons::on_pushButtonDeleteAbsence_clicked()
{
    Absences* absence = new Absences;
    int absenceIDdel = ui->lineEditAbsenceIDdel->text().toInt();

    absence->deleteAbsence(absenceIDdel);
    delete absence;
}

void GradesButtons::on_pushButtonAddFeedback_clicked()
{
    Feedbacks* feedback = new Feedbacks;
    int userID = ui->lineEditUserID_3->text().toInt();
    //QString subject = ui->lineEditSubject_3->text();
    //QString type = ui->lineEditFeedback->text();
    QString subject = ui->comboSubject_2->currentText();
    QString type = ui->comboBoxFeedbackType->currentText();

    feedback->addFeedback(userID, subject, type);
    delete feedback;
}


void GradesButtons::on_pushButtonUpdateFeedback_clicked()
{
    Feedbacks* feedback = new Feedbacks;
    int feedbackID = ui->lineEditFeedbackID->text().toInt();
    //QString newFeedback = ui->lineEditNewFeedback->text();
    QString newFeedback = ui->comboBoxUpdateFeedback->currentText();

    feedback->updateFeedback(feedbackID, newFeedback);
    delete feedback;
}

void GradesButtons::on_pushButtonDeleteFeedback_clicked()
{
    Feedbacks* feedback = new Feedbacks;
    int feedbackIDdel = ui->lineEditFeedbackIDdel->text().toInt();

    feedback->deleteFeedback(feedbackIDdel);
    delete feedback;
}
