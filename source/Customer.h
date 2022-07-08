#pragma once

#include "Human.h"
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <memory>
#include <QFile>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

using namespace std;

class Customer : public Human
{
private:
    string address;
    string phoneNumber;
    string userName;
    string password;
    int customerID;
    double wallet;
public:
    Customer(string, string, string, string, string, string, int);

    void set_address(string);
    void set_phone_number(string);
    void set_username(string);
    void set_customer_id(int i);
    void set_wallet(double);

    string get_address();
    string get_phone_number();
    int get_customer_id();
    double get_wallet();

    virtual void sign_up();
};
