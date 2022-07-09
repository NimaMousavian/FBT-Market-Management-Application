#include "manager_remove_employee_dialog.h"
#include "ui_manager_remove_employee_dialog.h"

manager_remove_employee_dialog::manager_remove_employee_dialog(MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_remove_employee_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    QFile employeesFile("database/employee.json");

    QJsonObject employeesObj;
    if (employeesFile.open(QIODevice::ReadOnly))
    {
        employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
        employeesFile.close();

        foreach(QJsonValue x, employeesObj["Employees"].toArray() )
               ui->comboBox->addItem(x["first name"].toString() + " " + x["last name"].toString());

    }
}

manager_remove_employee_dialog::~manager_remove_employee_dialog()
{
    delete ui;
}

void manager_remove_employee_dialog::on_pushButton_clicked()
{
    QJsonArray resultArr;
    QJsonObject resultObj;

    QFile employeesFile("database/employee.json");

    QJsonObject employeesObj;
    if (employeesFile.open(QIODevice::ReadOnly))
    {
        employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
        employeesFile.close();

        foreach(QJsonValue x, employeesObj["Employees"].toArray() )
        {
            if (x["first name"].toString() + " " + x["last name"].toString() != ui->comboBox->currentText())
            {
                resultArr.append(x);
            }
        }

      resultObj["Employees"] = resultArr;
      employeesFile.open(QIODevice::WriteOnly);
      employeesFile.write(QJsonDocument (resultObj).toJson());
      employeesFile.close();
      this->close();
      mainwindow->manager_window();
      mainwindow->display_info("Employee Removed.");
    }
}


void manager_remove_employee_dialog::on_pushButton_2_clicked()
{
    this->close();
}

