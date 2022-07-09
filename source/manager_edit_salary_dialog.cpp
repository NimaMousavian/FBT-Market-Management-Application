#include "manager_edit_salary_dialog.h"
#include "ui_manager_edit_salary_dialog.h"

manager_edit_salary_dialog::manager_edit_salary_dialog(MainWindow * mw,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_edit_salary_dialog)
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

manager_edit_salary_dialog::~manager_edit_salary_dialog()
{
    delete ui;
}


void manager_edit_salary_dialog::on_pushButton_clicked()
{
    if (ui->spinBox->value() == 0)
       mainwindow->display_error("Salary can not be 0.");
    else
    {
        QJsonArray resultArr;
        QJsonObject resultObj;
        QJsonObject editedSalary;
        QFile employeesFile("database/employee.json");

        QJsonObject employeesObj;
        if (employeesFile.open(QIODevice::ReadOnly))
        {
            employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
            employeesFile.close();

            foreach(QJsonValue x, employeesObj["Employees"].toArray() )
            {
                if (x["first name"].toString() + " " + x["last name"].toString() == ui->comboBox->currentText())
                {
                    editedSalary = x.toObject();
                    editedSalary["salary"] = ui->spinBox->value();
                    resultArr.append(editedSalary);
                }
                else
                    resultArr.append(x);
            }
            resultObj["Employees"] = resultArr;
            employeesFile.open(QIODevice::WriteOnly);
            employeesFile.write(QJsonDocument(resultObj).toJson());
            employeesFile.close();
            this->close();
            mainwindow->manager_window();
            mainwindow->display_info("Salary successfully edited.");

        }
    }

}

