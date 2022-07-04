#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string f_name, string l_name, int a, int id,string role, int em_id, int salary)
    :Human(f_name,l_name,a,id)
{
    this->role = role;
    this->employee_ID = em_id;
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

}
