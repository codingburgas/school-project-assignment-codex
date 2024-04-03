#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonDbDrivers_clicked();
    void on_pushButtonTestDb_clicked();
    void on_pushButtonRegister_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
