#include "sign_up_page.h"
#include "ui_sign_up_page.h"
#include "home.h"
#include "Customer.h"
#include "mainwindow.h"
#include "employee_signup.h"



Sign_up_page::Sign_up_page(MainWindow *mw,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_up_page)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    //----------------- set push buttons icons ------------------

    ui->back_push->setIcon(QIcon(":/go back.png"));
    ui->sign_push->setIcon(QIcon(":/signup.png"));
    ui->sign_push->setIconSize(QSize(90,90));

    //----------------- set push buttons stylesheet -------------------

    ui->back_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:15px;}"
    "*:hover{background: '#aeb6f5';}");

    ui->sign_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:35px;}"
    "*:hover{background: '#aeb6f5';}");

    //----------------- set line edits stylesheet -------------------------

    ui->firstNmae_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->lastNmae_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->age_spin->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->address_te->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->phoneNumber_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->username_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->password_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->confPassword_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");

    ui->password_le->setEchoMode(QLineEdit::Password);
    ui->confPassword_le->setEchoMode(QLineEdit::Password);
}

Sign_up_page::~Sign_up_page()
{
    delete ui;
}

void Sign_up_page::on_sign_push_clicked()
{
    //-------------- controls before signUp -------------------------

    QString firstName = ui->firstNmae_le->text();
    QString lastName = ui->lastNmae_le->text();
    QString userName = ui->username_le->text();
    QString pass = ui->password_le->text();
    QString con_pass = ui->confPassword_le->text();
    int age = ui->age_spin->value();
    QString address = ui->address_te->toPlainText();
    QString phoneNumber = ui->phoneNumber_le->text();

    if (firstName.isEmpty() || lastName.isEmpty() || userName.isEmpty() || pass.isEmpty() || con_pass.isEmpty() || age == 1  || address.isEmpty() || phoneNumber.isEmpty())
            mainwindow->display_error("Please fill out required fields.");

    else if (QString::compare(pass,con_pass,Qt::CaseInsensitive))
        mainwindow->display_error("password doesn't match");



    //-------------- signing up --------------------------

    else
    {


        Customer* c = new Customer(firstName.toStdString(), lastName.toStdString(), userName.toStdString(), pass.toStdString(), phoneNumber.toStdString(), address.toStdString(), age);
        unique_ptr<Human> h1(c);
        h1->sign_up();
        mainwindow->set_username(userName);
        this->close();
        mainwindow->customer_window();
        mainwindow->display_info("Your ID Number in FBT Market is "+QString::number(c->get_customer_id()));

    }
}


void Sign_up_page::on_back_push_clicked()
{
    this->close();
    mainwindow->setCentralWidget(new Home(this->mainwindow));
    return;
}


void Sign_up_page::on_comboBox_currentIndexChanged(int index)
{
    if (index == 1)
    {
        this->close();
        mainwindow->setCentralWidget(new Employee_signup(this->mainwindow));
    }
    return;
}

