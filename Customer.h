#pragma once

#include <string>
using namespace std;

class Customer
{
private:
    int customer_ID;
    string city;
    string address;
    int phone_number;
public:
    Customer(int, string, string, int);

    void set_customer_id(int);
    void set_city(string);
    void set_address(string);
    void set_phone_number(int);

    int get_customer_id();
    string get_city();
    string get_address();
    int get_phone_number();
};