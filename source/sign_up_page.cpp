#include "sign_up_page.h"
#include "ui_sign_up_page.h"
#include "home.h"
#include "Employee.h"
#include "Customer.h"
#include "mainwindow.h"
#include "employee_signup.h"
#include <memory>

Sign_up_page::Sign_up_page(MainWindow *mw,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sign_up_page)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    //----------------- set push buttons icons ------------------

    ui->back_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/go back.png"));
    ui->sign_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/signup.png"));
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
    ui->idNumber_spin->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->city_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
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
    //-------------- controls befor signUp -------------------------


    //-------------- signing up --------------------------
    try
    {
        //Employee em(ui->firstNmae_le->text().toStdString(), ui->lastNmae_le->text().toStdString(), ui->age_spin->value(), ui->idNumber_spin->value(), "role");
        //Customer * cu = new Customer(ui->firstNmae_le->text().toStdString(), ui->lastNmae_le->text().toStdString(), ui->age_spin->value(), ui->idNumber_spin->value(), ui->username_le->text().toStdString(), ui->password_le->text().toStdString(),ui->phoneNumber_le->text().toStdString(), ui->city_le->text().toStdString(), ui->address_te->toPlainText().toStdString());
//        shared_ptr<Customer> b;
//        b->set_username(ui->username_le->text().toStdString());
//        shared_ptr<Human> user = static_pointer_cast<Customer> (b);
        //mainwindow->display_error("signup");
        this->close();
        mainwindow->customer_window();

        //b->sign_up();
        //user.operator=(shared_ptr<Customer> (cu));
        //user->sign_up();
//            Human * u = cu;
//            u->sign_up();
    }
    catch(...)
    {
        mainwindow->display_error("unknown error");

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

