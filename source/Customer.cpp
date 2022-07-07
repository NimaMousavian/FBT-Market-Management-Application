#include "Customer.h"
#include <QJsonArray>
using namespace std;

Customer::Customer(string f_name, string l_name, string _username, string _password, string _phone, string _address, int a, int id)
    :Human(f_name, l_name, a)
{
    this->address = _address;
    this->phoneNumber = _phone;
    this->userName = _username;
    this->password = _password;
    this->customerID = id;
    this->wallet = 0;
    return;
}




void Customer::set_address(string a)
{
    this->address = a;
    return;
}

void Customer::set_phone_number(string p)
{
    this->phoneNumber = p;
    return;
}

void Customer::set_username(string u)
{
    this->userName = u;
    return;
}

void Customer::set_customer_id(int i)
{
    this->customerID = i;
    return;
}

void Customer::set_wallet(double w)
{
    this->wallet = w;
    return;
}


string Customer::get_address()
{
    return this->address;
}
string Customer::get_phone_number()
{
    return this->phoneNumber;
}

int Customer::get_customer_id()
{
    return this->customerID;
}

double Customer::get_wallet()
{
    return this->wallet;
}

void Customer::sign_up()
{
    QFile customersFile("database/customers.json");

    QJsonObject customersObj;
    if (customersFile.open(QIODevice::ReadOnly))
    {
        customersObj = (QJsonDocument::fromJson( customersFile.readAll() )).object();
        customersFile.close();
    }
    //QJsonArray purchases;
    QJsonObject newCustomerInfo = { {"fist name", QString::fromStdString(Human::get_first_name())},
                                    {"last name", QString::fromStdString(Human::get_last_name())},
                                    {"user name", QString::fromStdString(this->userName)},
                                    {"password", QString::fromStdString(this->password)},
                                    {"customer ID", this->customerID},
                                    {"age", Human::get_age()},
                                    {"address", QString::fromStdString(this->address)},
                                    {"phone number", QString::fromStdString(this->phoneNumber)},
                                    {"wallet", this->wallet }};


    customersObj[QString::fromStdString(this->userName)] = newCustomerInfo;
    QJsonDocument customersDuc(customersObj);
    customersFile.open(QIODevice::WriteOnly);
    customersFile.write(customersDuc.toJson());
    customersFile.close();
    return;

}
