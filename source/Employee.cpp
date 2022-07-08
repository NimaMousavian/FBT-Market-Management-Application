#include "Employee.h"
#include <iostream>
#include <fstream>
using namespace std;

Employee::Employee(string f_name, string l_name, int a, int id, string _username, string _password, int salary)
    :Human(f_name, l_name, a)
{
    this->employeeID = id;
    this->username = _username;
    this->password = _password;
    this->salary = salary;
    return;
}

Employee::~Employee()
{
    return;
}


void Employee::set_salary(int s)
{
    this->salary = s;
    return;
}

void Employee::set_employee_ID(int id)
{
    this->employeeID = id;
    return;
}

int Employee::get_salary()
{
    return this->salary;
}

int Employee::get_employee_ID()
{
    return this->employeeID;
}

void Employee::sign_up()
{
    QFile employeesFile("database/employee.json");

    QJsonObject employeesObj;
    if (employeesFile.open(QIODevice::ReadOnly))
    {
        employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
        employeesFile.close();
    }
    QJsonObject newEmployeeInfo = { {"first name", QString::fromStdString(Human::get_first_name())},
                                    {"last name", QString::fromStdString(Human::get_last_name())},
                                    {"user name", QString::fromStdString(this->username)},
                                    {"password", QString::fromStdString(this->password)},
                                    {"ID number", this->employeeID},
                                    {"age", Human::get_age()},
                                    {"salary", this->salary}};

    QJsonArray empArray = employeesObj["Employees"].toArray();
    empArray.append(newEmployeeInfo);
    employeesObj["Employees"] = empArray;
    employeesFile.open(QIODevice::WriteOnly);
    employeesFile.write(QJsonDocument (employeesObj).toJson());
    employeesFile.close();
    return;
}
