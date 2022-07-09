#include "Manager.h"
using namespace std;

Manager::Manager(string f_name, string l_name, int a, string user, string pass)
    :Human(f_name, l_name, a)
{
    this->username = user;
    this->password = pass;
}

void Manager::sign_up()
{
    QFile managerFile("database/manager.json");
    QJsonObject managerObj = { {"first name", QString::fromStdString(Human::get_first_name())},
                               {"last name", QString::fromStdString(Human::get_last_name())},
                               {"age", Human::get_age()},
                               {"user name", QString::fromStdString(this->username)},
                               {"password", QString::fromStdString(this->password)} };
    managerFile.open(QIODevice::WriteOnly);
    managerFile.write(QJsonDocument(managerObj).toJson());
    managerFile.close();
    return;
}


