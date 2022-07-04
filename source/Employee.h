#pragma once

#include <Human.h>
#include <iostream>
using namespace std;
#include <string>


class Employee : public Human
{
private:
    string role;
    int employee_ID;
    int salary;
public:
    Employee(string f_name, string l_name, int a, int, string, int em_id = 0, int salary = 0);
    ~Employee();

    void set_role(string);
    void set_employee_ID(int);
    void set_salary(int);

    string get_role();
    int get_employee_ID();
    int get_salary();

    virtual void sign_up();
};
