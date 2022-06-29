#pragma once

#include <string>
using namespace std;

class Human
{
private:
    string first_name;
    string last_name;
    int age;
    int ID_number;
public:
    Human(string first_name, string last_name, int age, int id);
    ~Human();

    void set_first_name(string);
    void set_last_name(string);
    void set_age(int);

    int get_age();
    string get_first_name();
    string get_last_name();

};