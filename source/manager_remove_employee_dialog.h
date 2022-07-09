#ifndef MANAGER_REMOVE_EMPLOYEE_DIALOG_H
#define MANAGER_REMOVE_EMPLOYEE_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QComboBox>
#include "mainwindow.h"

namespace Ui {
class manager_remove_employee_dialog;
}

class manager_remove_employee_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit manager_remove_employee_dialog(MainWindow *, QWidget *parent = nullptr);
    ~manager_remove_employee_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::manager_remove_employee_dialog *ui;
    MainWindow * mainwindow;
};

#endif // MANAGER_REMOVE_EMPLOYEE_DIALOG_H
