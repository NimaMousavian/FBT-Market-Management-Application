#pragma once

#include <iostream>
using namespace std;
#include <string>


class Employee
{
private:
    string role;
    int employee_ID;
    int salary;
public:
    Employee(string, int, int);
    ~Employee();

    void set_role(string);
    void set_employee_ID(int);
    void set_salary(int);

    string get_role();
    int get_employee_ID();
    int get_salary();
};