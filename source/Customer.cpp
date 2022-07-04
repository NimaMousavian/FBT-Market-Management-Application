#include "Customer.h"
#include <fstream>

#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include <random>
#include <time.h>
using namespace std;

Customer::Customer(string f_name, string l_name, int a, int id, string _username, string _password, string phone, string city, string address)
    :Human(f_name, l_name, a, id)
{
    srand(time(0));
    this->customer_ID = rand()%1000;
    this->city = city;
    this->address = address;
    this->phone_number = phone;
    this->username = _username;
    this->password = _password;
    return;
}

void Customer::set_customer_id(int i)
{
    this->customer_ID = i;
    return;
}
void Customer::set_city(string c)
{
    this->city = c;
    return;
}

void Customer::set_address(string a)
{
    this->address = a;
    return;
}

void Customer::set_phone_number(string p)
{
    this->phone_number = p;
    return;
}

void Customer::set_username(string u)
{
    this->username = u;
    return;
}

int Customer::get_customer_id()
{
    return this->customer_ID;
}

string Customer::get_city()
{
    return this->city;
}

string Customer::get_address()
{
    return this->address;
}
string Customer::get_phone_number()
{
    return this->phone_number;
}

void Customer::sign_up()
{
    string path = "database/customers.dat";
    ofstream file;
    file.open(path, ios::app | ios::binary);
    if (file)
    {
        file.write((char*)this, sizeof (Customer));
    }
    else
    {
        //error: file can not be opened!
    }
    file.close();
}
