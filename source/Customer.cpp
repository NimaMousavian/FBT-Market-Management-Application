#include "Customer.h"

Customer::Customer(string f_name, string l_name, int a, int id, int cu_id, string city, string address, int phone)
    :Human(f_name, l_name, a, id)
{
    this->customer_ID = cu_id;
    this->city = city;
    this->address = address;
    this->phone_number = phone;
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

void Customer::set_phone_number(int p)
{
    this->phone_number = p;
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
int Customer::get_phone_number()
{
    return this->phone_number;
}
