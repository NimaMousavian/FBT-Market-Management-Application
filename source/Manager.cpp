#include "Manager.h"
using namespace std;

Manager::Manager(string f_name, string l_name, int a, string user, string pass)
    :Human(f_name, l_name, a)
{
    this->username = user;
    this->password = pass;
}
