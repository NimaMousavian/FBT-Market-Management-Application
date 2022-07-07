#include "employee_signup.h"
#include "ui_employee_signup.h"
#include "sign_up_page.h"
#include "home.h"
#include "Human.h"
#include "Employee.h"

Employee_signup::Employee_signup(MainWindow *mw ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Employee_signup)
{
    ui->setupUi(this);
    this->mainwindow = mw;
}

Employee_signup::~Employee_signup()
{
    delete ui;
}

void Employee_signup::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->close();
        mainwindow->setCentralWidget(new Sign_up_page(this->mainwindow));
    }
    return;
}


void Employee_signup::on_back_push_clicked()
{
    this->close();
    mainwindow->setCentralWidget(new Home(this->mainwindow));
    return;
}


void Employee_signup::on_sign_push_clicked()
{
    //---------------- controls before signup -----------------

    QString firstName = ui->firstNmae_le->text();
    QString lastName = ui->lastNmae_le->text();
    QString userName = ui->username_le->text();
    QString pass = ui->password_le->text();
    QString con_pass = ui->confPassword_le->text();
    int ID = ui->idNumber_spin->value();
    int age = ui->age_spin->value();

   if (firstName.isEmpty() || lastName.isEmpty() || userName.isEmpty() || pass.isEmpty() || con_pass.isEmpty() || ID == 0 || age == 1)
            mainwindow->display_error("Please fill out required fields.");

   else if (QString::compare(pass,con_pass,Qt::CaseInsensitive))
       mainwindow->display_error("password doesn't match");


    //------------------ signUp ------------------------

   else
   {
       Employee * e = new Employee(firstName.toStdString(), lastName.toStdString(), age, ID, userName.toStdString(), pass.toStdString());
       unique_ptr<Human> h2(e);
       h2->sign_up();
       this->close();
       mainwindow->employee_window();

   }


}

