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

    //----------------- set push buttons stylesheet -------------------

    ui->back_push->setStyleSheet(
    "*{background-color:#fcde73;"
    "border:2px solid #fad037;"
    "border-radius:25px;}"
    "*:hover{background: '#fbd95f';}");

    ui->sign_push->setStyleSheet(
    "*{background-color:#f3bcbd;"
    "border:2px solid #aa8283;"
    "border-radius:25px;}"
    "*:hover{background: '#c29496';}");

    //----------------- set line edits stylesheet -------------------------

    ui->firstNmae_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->lastNmae_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->age_spin->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->username_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->password_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->confPassword_le->setStyleSheet("background-color:#91c3c1; border:2px solid #0e5b56; border-radius:12px;");
    ui->comboBox_2->setStyleSheet("background-color:#f3bcbd; border:2px solid #aa8283; border-radius:12px;");

    ui->password_le->setEchoMode(QLineEdit::Password);
    ui->confPassword_le->setEchoMode(QLineEdit::Password);
}

Employee_signup::~Employee_signup()
{
    delete ui;
}

void Employee_signup::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 1)
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
    int age = ui->age_spin->value();

   if (firstName.isEmpty() || lastName.isEmpty() || userName.isEmpty() || pass.isEmpty() || con_pass.isEmpty() || age == 1)
            mainwindow->display_error("Please fill out required fields.");

   else if (pass.count() < 8)
       mainwindow->display_error("Password must have at least 8 characters.");

   else if (QString::compare(pass,con_pass,Qt::CaseInsensitive))
       mainwindow->display_error("password doesn't match");


    //------------------ signUp ------------------------

   else
   {
       Employee * e = new Employee(firstName.toStdString(), lastName.toStdString(), age, userName.toStdString(), pass.toStdString());
       unique_ptr<Human> h2(e);
       h2->sign_up();
       this->close();
       mainwindow->set_username(userName);
       mainwindow->employee_window();
       mainwindow->display_info("Your ID Number in FBT Market is "+QString::number(e->get_employee_ID()));

   }
}

