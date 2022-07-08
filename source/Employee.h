#pragma once

#include "Human.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRandomGenerator>
#include <string>
using namespace std;


class Employee : public Human
{
private:
    int salary;
    int employeeID;
    string username;
    string password;
public:
    Employee(string f_name, string l_name, int a, string username, string password, int salary = 1000000);
    ~Employee();

    void set_salary(int);
    void set_employee_ID(int id);
    int get_salary();
    int get_employee_ID();

    virtual void sign_up();
};
