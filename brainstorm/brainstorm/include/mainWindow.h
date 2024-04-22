#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Contains the main window methods.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor.
    MainWindow(QWidget *parent = nullptr);
    // Destructor.
    ~MainWindow();

private slots:
    // Button actions when clicked.
    void on_pushButtonLogin_clicked();
    void on_pushButtonRegister_clicked();
    void on_switchFormButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
