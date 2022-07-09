#ifndef MANAGER_H
#define MANAGER_H

#include "Human.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
using namespace std;

class Manager : public Human
{
public:
    Manager(string fname, string lname, int a, string user, string pass);
    virtual void sign_up();

private:
    string username;
    string password;
};

#endif // MANAGER_H
