#include "Employee.h"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

Employee::Employee(string f_name, string l_name, int a, int id, string _username, string _password, string role, int salary)
    :Human(f_name,l_name,a,id)
{
    srand(time(0));
    this->role = role;
    this->username = _username;
    this->password = _password;
    this->employee_ID = rand()%1000;
    this->salary = salary;
    return;
}

Employee::~Employee()
{
    return;
}

void Employee::set_role(string t)
{
    this->role = t;
    return;
}

void Employee::set_employee_ID(int i)
{
    this->employee_ID = i;
    return;
}

void Employee::set_salary(int s)
{
    this->salary = s;
    return;
}

string Employee::get_role()
{
    return this->role;
}

int Employee::get_employee_ID()
{
    return this->employee_ID;
}

int Employee::get_salary()
{
    return this->salary;
}

void Employee::sign_up()
{
    string path = "database/employee_requests.dat";
    ofstream file;
    file.open(path, ios::app | ios::binary);
    if (file)
    {
        file.write((char*)this, sizeof (Employee));
    }
    else
    {
        //error: file can not be opened!
    }
    file.close();
}
