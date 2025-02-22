#include "login_page.h"
#include "ui_login_page.h"
#include "home.h"
#include <string.h>


Login_page::Login_page(MainWindow *mw,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_page)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    //----------------- set push buttons icons ------------------

//    ui->back_push->setIcon(QIcon(":/go back.png"));
//    ui->login_push->setIcon(QIcon(":/login2.png"));
//    ui->login_push->setIconSize(QSize(90,90));

    //----------------- set push buttons stylesheet -------------------

    ui->back_push->setStyleSheet(
    "*{background-color:#fcde73;"
    "border:2px solid #fad037;"
    "border-radius:25px;}"
    "*:hover{background: '#fbd95f';}");

    ui->login_push->setStyleSheet(
    "*{background-color:#f889cc;"
    "border:2px solid #e82970;"
    "border-radius:25px;}"
    "*:hover{background: '#c66ea3';}");

    //----------------- set line edits stylesheet -------------------------

    ui->username_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->password_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->comboBox->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");

    ui->password_le->setEchoMode(QLineEdit::Password);
}

Login_page::~Login_page()
{
    delete ui;
}

void Login_page::on_back_push_clicked()
{
    this->close();
    mainwindow->setCentralWidget(new Home(this->mainwindow));
    mainwindow->setMinimumSize(QSize(1000,725));
}


void Login_page::on_login_push_clicked()
{
    if (ui->comboBox->currentIndex() == 0)  // customer login
     {
         QFile customersFile("database/customers.json");

         QJsonObject customersObj;
         if (customersFile.open(QIODevice::ReadOnly))
         {
             customersObj = (QJsonDocument::fromJson( customersFile.readAll() )).object();
             customersFile.close();
             if ( (customersObj[ui->username_le->text()].toObject())["user name"] == ui->username_le->text())
             {
                 if ((customersObj[ui->username_le->text()].toObject())["password"] == ui->password_le->text())
                 {
                     this->close();
                     mainwindow->set_username(ui->username_le->text());
                     mainwindow->customer_window();
                 }
                 else
                     mainwindow->display_error("Incorrect Password.");
             }
             else
                 mainwindow->display_error("Incorrect Username");
         }

         else
             mainwindow->display_error("Please sing up first.");
     }


    else if (ui->comboBox->currentIndex() == 1)   // employee logtiin
     {
         QFile employeesFile("database/employee.json");

         QJsonObject employeesObj;
         if (employeesFile.open(QIODevice::ReadOnly))
         {
             employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
             employeesFile.close();

             int flag = 0;
             foreach(QJsonValue x, employeesObj["Employees"].toArray() )
             {
                    if (x["user name"] == ui->username_le->text())
                    {
                        flag = 1;
                        if (x["password"] == ui->password_le->text())
                        {
                            this->close();
                            mainwindow->set_username(ui->username_le->text());
                            mainwindow->employee_window();
                        }
                        else
                            mainwindow->display_error("Incorrect Password");
                        break;
                    }
             }
             if (flag == 0)
                 mainwindow->display_error("Incorrect Username");

         }

         else
             mainwindow->display_error("Please sign up first.");
     }

    else // manager login
        {
            QFile managerFile("database/manager.json");
            managerFile.open(QIODevice::ReadOnly);
            QJsonDocument managerObj = QJsonDocument::fromJson( managerFile.readAll() );
            if (ui->username_le->text() == managerObj["user name"].toString() && ui->password_le->text() == managerObj["password"].toString())
            {
                this->close();
                mainwindow->manager_window();
            }
            else
                mainwindow->display_error("You are not manager!");

        }
}



