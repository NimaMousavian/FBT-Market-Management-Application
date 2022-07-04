#pragma once

#include "Human.h"
#include <string>
using namespace std;

class Customer : public Human
{
private:
    int customer_ID;
    string city;
    string address;
    string phone_number;
    string username;
    string password;
    double wallet;
public:
    Customer(string, string, int, int, string _username, string _password, string , string city = "", string address = "");

    void set_customer_id(int);
    void set_city(string);
    void set_address(string);
    void set_phone_number(string);
    void set_username(string);
    void set_wallet(double);

    int get_customer_id();
    string get_city();
    string get_address();
    string get_phone_number();
    double get_wallet();

    virtual void sign_up();
};
