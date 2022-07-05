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

    if (ui->username_le->text().isEmpty() || ui->firstNmae_le->text().isEmpty() || ui->lastNmae_le->text().isEmpty() || ui->confPassword_le->text().isEmpty() || ui->password_le->text().isEmpty() || ui->idNumber_spin->value()==0 || ui->age_spin->value()==1)
            mainwindow->display_error("Please fill out required fields.");

        else
        {
            QString pass=ui->password_le->text();
            QString con_pass=ui->confPassword_le->text();
            if (QString::compare(pass,con_pass,Qt::CaseInsensitive))
                mainwindow->display_error("password doesn't match");
        }

    //------------------ signUp ------------------------
    Employee *em = new Employee(ui->firstNmae_le->text().toStdString(), ui->lastNmae_le->text().toStdString(), ui->age_spin->value(), ui->idNumber_spin->value(), ui->username_le->text().toStdString(),ui->password_le->text().toStdString());
    Human *h = em;
    h->sign_up();


}

