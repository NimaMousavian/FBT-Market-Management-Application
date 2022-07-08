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

    ui->back_push->setIcon(QIcon(":/go back.png"));
    ui->login_push->setIcon(QIcon(":/login2.png"));
    ui->login_push->setIconSize(QSize(90,90));

    //----------------- set push buttons stylesheet -------------------

    ui->back_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:15px;}"
    "*:hover{background: '#aeb6f5';}");

    ui->login_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:35px;}"
    "*:hover{background: '#aeb6f5';}");

    //----------------- set line edits stylesheet -------------------------

    ui->username_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->password_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->comboBox->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
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
<<<<<<< HEAD


}





=======
    if (ui->comboBox->currentIndex() == 0)  // customer login
     {
         QFile customersFile("database/customers.json");

         QJsonObject customersObj;
         if (customersFile.open(QIODevice::ReadOnly))
         {
             customersObj = (QJsonDocument::fromJson( customersFile.readAll() )).object();
             customersFile.close();
             if ( customersObj[ui->username_le->text()] != NULL)
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

             if ( employeesObj[ui->username_le->text()] != NULL)
             {
                 if ((employeesObj[ui->username_le->text()].toObject())["password"] == ui->password_le->text())
                 {
                     this->close();
                     mainwindow->employee_window();
                 }
                 else
                     mainwindow->display_error("Incorrect Password");
             }
             else
                 mainwindow->display_error("Incorrect Username");
         }

         else
             mainwindow->display_error("Please sign up first.");
     }

    else // manager login
    {
        if (QString::compare(ui->username_le->text(), "FBT_Admin") && QString::compare(ui->password_le->text(), "1234"))
        {
            this->close();
//            mainwindow->manager_window();
        }

    }
}

>>>>>>> 33e84d1c574e221dfda4ed7a89ff1a0f54971905
