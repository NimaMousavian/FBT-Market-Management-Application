#ifndef MANAGERADDEMPLOYEEDIALOG_H
#define MANAGERADDEMPLOYEEDIALOG_H

#include <QDialog>
#include <QFile>
#include <qjsonarray.h>
#include <QJsonDocument>
#include <QJsonObject>
#include "Employee.h"
#include "mainwindow.h"

namespace Ui {
class managerAddEmployeeDialog;
}

class managerAddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit managerAddEmployeeDialog(MainWindow *, QWidget *parent = nullptr);
    ~managerAddEmployeeDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::managerAddEmployeeDialog *ui;
    MainWindow * mainwindow;
};

#endif // MANAGERADDEMPLOYEEDIALOG_H
