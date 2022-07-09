#ifndef MANAGER_EDIT_SALARY_DIALOG_H
#define MANAGER_EDIT_SALARY_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidget>
#include "mainwindow.h"

namespace Ui {
class manager_edit_salary_dialog;
}

class manager_edit_salary_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit manager_edit_salary_dialog(MainWindow *,QWidget *parent = nullptr);
    ~manager_edit_salary_dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::manager_edit_salary_dialog *ui;
    MainWindow * mainwindow;
};

#endif // MANAGER_EDIT_SALARY_DIALOG_H
