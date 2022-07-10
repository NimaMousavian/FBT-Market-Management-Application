#include "manager_edit_salary_dialog.h"
#include "ui_manager_edit_salary_dialog.h"

manager_edit_salary_dialog::manager_edit_salary_dialog(MainWindow * mw,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager_edit_salary_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Edit Salary");

    //----------------- set push buttons stylesheet -------------------

    ui->pushButton_2->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:12px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    ui->pushButton->setStyleSheet(
    "*{background-color:#91c3c1;"
    "border:2px solid #0e5b56;"
    "border-radius:12px;}"
    "*:hover{background: '#568c89';}");

    //----------------- set line edits stylesheet -------------------------

    ui->spinBox->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->comboBox->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");




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


void manager_edit_salary_dialog::on_pushButton_2_clicked()
{
    this->close();
}

