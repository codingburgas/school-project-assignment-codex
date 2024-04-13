#include "../include/gradesButtons.h"
#include "ui_gradesButtons.h"
#include "../include/grades.h" // Assuming Grades class is declared here
#include "../include/pch.h"

GradesButtons::GradesButtons(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GradesButtons)
{
    ui->setupUi(this);
    QIcon icon("../assets/icon.png");
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
    int userID = ui->lineEditUserID->text().toInt();
    QString subject = ui->lineEditSubject->text();
    int grade = ui->lineEditGrade->text().toInt();

    addGrade(userID, subject, grade);
}


void GradesButtons::on_pushButtonUpdateGrade_clicked()
{
    int gradeID = ui->lineEditGradeID->text().toInt();
    int newGrade = ui->lineEditnewGrade->text().toInt();

    updateGrade(gradeID, newGrade);
}


void GradesButtons::on_pushButtonDeleteGrade_clicked()
{
    int gradeIDdel = ui->lineEditGradeIDdel->text().toInt();

    deleteGrade(gradeIDdel);
}

