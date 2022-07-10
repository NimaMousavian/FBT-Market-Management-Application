#include "changepass_dialog.h"
#include "ui_changepass_dialog.h"

changePass_dialog::changePass_dialog(MainWindow * mw, int index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePass_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;
    this->role = index;
    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Change password");

    //----------------- set push buttons stylesheet -------------------

    ui->cancleBotton->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:12px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    ui->changeButton->setStyleSheet(
    "*{background-color:#91c3c1;"
    "border:2px solid #0e5b56;"
    "border-radius:12px;}"
    "*:hover{background: '#568c89';}");

    //----------------- set line edits stylesheet -------------------------

    ui->currentpass_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->newpass_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");

    ui->currentpass_le->setEchoMode(QLineEdit::Password);
    ui->newpass_le->setEchoMode(QLineEdit::Password);
}

changePass_dialog::~changePass_dialog()
{
    delete ui;
}




void changePass_dialog::on_changeButton_clicked()
{
    if (this->role == 0) // customer
    {
        QFile customersFile("database/customers.json");

        QJsonObject customersObj;
        QJsonObject newCustomersObj;
        if (customersFile.open(QIODevice::ReadOnly))
        {
            customersObj = (QJsonDocument::fromJson( customersFile.readAll() )).object();
            customersFile.close();
            if ( (customersObj[mainwindow->get_username()].toObject())["user name"] == mainwindow->get_username())
            {
                if (ui->newpass_le->text().isEmpty())
                    mainwindow->display_error("Please create a new Password");
                else
                {
                    if ( (customersObj[mainwindow->get_username()].toObject())["password"] == ui->currentpass_le->text())
                    {
                        if (ui->newpass_le->text().count() < 8)
                        {
                            mainwindow->display_error("Password must have at least 8 characters.");
                        }
                        else
                        {
                            newCustomersObj = customersObj;
                            QJsonObject thisUser = customersObj[mainwindow->get_username()].toObject();

                            QJsonObject thisUserNew = { {"first name", thisUser["first name"].toString()},
                                                        {"last name", thisUser["last name"].toString()},
                                                        {"user name", thisUser["user name"].toString()},
                                                        {"password", ui->newpass_le->text()},
                                                        {"customer ID", thisUser["customer ID"].toInt()},
                                                        {"age", thisUser["age"].toInt()},
                                                        {"address", thisUser["address"].toString()},
                                                        {"phone number", thisUser["phone number"].toString()},
                                                        {"wallet", thisUser["wallet"].toInt()}};

                            newCustomersObj[mainwindow->get_username()] = thisUserNew;

                            customersFile.open(QIODevice::WriteOnly);
                            customersFile.write(QJsonDocument (newCustomersObj).toJson());
                            customersFile.close();
                            this->close();
                            mainwindow->display_info("Password Changed.");
                        }
                    }
                    else
                    {
                        mainwindow->display_error("Incorrect Password");
                    }
                }
            }
        }
    }

    else if (this->role == 1)   // employee
    {
        QJsonArray resultArr;
        QJsonObject resultObj;
        QJsonObject changedPass;
        QFile employeesFile("database/employee.json");

        QJsonObject employeesObj;
        if (employeesFile.open(QIODevice::ReadOnly))
        {
            employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
            employeesFile.close();

            foreach(QJsonValue x, employeesObj["Employees"].toArray() )
            {

                if (x["user name"] == mainwindow->get_username())
                    changedPass = x.toObject();

                else
                    resultArr.append(x);
            }


            if (changedPass["password"] == ui->currentpass_le->text())
            {
                if (ui->newpass_le->text().count() < 8)
                {
                    mainwindow->display_error("Password must have at least 8 characters.");
                }
                else
                {
                    changedPass["password"] = ui->newpass_le->text();
                    resultArr.append(changedPass);
                    resultObj["Employees"] = resultArr;
                    employeesFile.open(QIODevice::WriteOnly);
                    employeesFile.write(QJsonDocument(resultObj).toJson());
                    employeesFile.close();
                    this->close();
                    mainwindow->display_info("Password Changed.");
                }
            }
            else
            {
                mainwindow->display_error("Incorrect Password.");
            }


        }
    }

    else if(this->role == 2)  // manager
    {
        QFile managerFile("database/manager.json");
        managerFile.open(QIODevice::ReadOnly);
        QJsonObject managerObj= (QJsonDocument::fromJson( managerFile.readAll() )).object();
        managerFile.close();
        if (ui->currentpass_le->text() == managerObj["password"].toString())
        {
            if (ui->newpass_le->text().count() >= 8)
            {
                QJsonObject newManagerObj = { {"first name", managerObj["first name"].toString()},
                                              {"last name", managerObj["last name"].toString()},
                                              {"age", managerObj["age"].toInt()},
                                              {"user name", managerObj["user name"].toString()},
                                              {"password", ui->newpass_le->text()}};

                managerFile.open(QIODevice::WriteOnly);
                managerFile.write(QJsonDocument(newManagerObj).toJson());
                managerFile.close();
                this->close();
                mainwindow->display_info("Password Changed.");
            }
            else
            {
                mainwindow->display_error("Password must have at least 8 characters.");
            }
        }
        else
        {
            mainwindow->display_error("Incorrent Password.");
        }
    }
}


void changePass_dialog::on_cancleBotton_clicked()
{
    this->close();
}

