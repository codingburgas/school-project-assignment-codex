#include "../include/gradesButtons.h"
#include "../include/absences.h"
#include "../include/grades.h"
#include "../include/admin.h"
#include "ui_gradesButtons.h"

GradesButtons::GradesButtons(QWidget *parent, int userID)
    : QDialog(parent)
    , ui(new Ui::GradesButtons)
    , userID(userID)
{
    ui->setupUi(this);
    QIcon icon("../brainstorm/assets/icon.png");
    this->setWindowIcon(icon);
    // Initialize stackedWidgetIndex to 0 or any default value
    stackedWidgetIndex = 0;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndex);
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
    QString subject = ui->lineEditSubject->text();
    int grade = ui->lineEditGrade->text().toInt();

    gradeObj->addGrade(userID, subject, grade);
    delete gradeObj;
}


void GradesButtons::on_pushButtonUpdateGrade_clicked()
{
    Grades* grade = new Grades;
    int gradeID = ui->lineEditGradeID->text().toInt();
    int newGrade = ui->lineEditnewGrade->text().toInt();

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
    int permsLevel = ui->lineEditPermsLevel->text().toInt();

    admin->setPermissions(userIDPerms, permsLevel, userID);
    delete admin;
}


void GradesButtons::on_pushButtonAddToGrade_clicked()
{
    Admin* admin = new Admin;
    int userIDAddToGrade = ui->lineEditUserIDGradeAdd->text().toInt();
    QString grade = ui->lineEditAddToGrade->text();

    admin->addToGrade(userIDAddToGrade, grade, userID);
    delete admin;
}

void GradesButtons::on_pushButtonAddAbsence_2_clicked()
{
    Absences* absence = new Absences;
    int userID = ui->lineEditUserID_2->text().toInt();
    QString subject = ui->lineEditSubject_2->text();
    QString type = ui->lineEditAbsence->text();

    absence->addAbsence(userID, subject, type);
    delete absence;
}


void GradesButtons::on_pushButtonUpdateAbsence_clicked()
{
    Absences* absence = new Absences;
    int absenceID = ui->lineEditAbsenceID_2->text().toInt();
    QString newAbsence = ui->lineEditNewAbsence->text();

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
