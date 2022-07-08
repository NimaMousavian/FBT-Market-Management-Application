#ifndef MANAGER_H
#define MANAGER_H

#include "Human.h"
#include <iostream>
using namespace std;

class Manager : public Human
{
public:
    Manager(string fname, string lname, int a, string user, string pass);
private:
    string username;
    string password;
};

#endif // MANAGER_H
