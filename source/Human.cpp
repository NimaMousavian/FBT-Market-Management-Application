#include <iostream>
using namespace std;
#include "Human.h"
#include <string>


Human::Human(string first_name, string last_name, int age, int id)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->ID_number = id;
    return;
}

Human::~Human()
{
    this->age = 0;
    return;
}

void Human::set_first_name(string s)
{
    this->first_name = s;
    return;
}

void Human::set_last_name(string s)
{
    this->last_name = s;
    return;
}

void Human::set_age(int a)
{
    this->age = a;
    return;
}

int Human::get_age()
{
    return this->age;
}

string Human::get_first_name()
{
    return this->first_name;
}

string Human::get_last_name()
{
    return this->last_name;
}