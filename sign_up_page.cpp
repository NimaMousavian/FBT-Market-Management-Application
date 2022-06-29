#include "sign_up_page.h"
#include "ui_sign_up_page.h"
#include "home.h"
#include "Employee.h"
#include "Customer.h"
#include <memory>

Sign_up_page::Sign_up_page(QMainWindow *mw,QWidget *parent) :
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
}

Sign_up_page::~Sign_up_page()
{
    delete ui;
}

void Sign_up_page::on_sign_push_clicked()
{
    //-------------- controls befor signUp -------------------------


    //-------------- signing up --------------------------
    Employee em(ui->firstNmae_le->text().toStdString(), ui->lastNmae_le->text().toStdString(), ui->age_spin->value(), ui->idNumber_spin->value(), "role");

    shared_ptr<Human> user;
    user.operator=(make_shared<Employee>(ui->firstNmae_le->text().toStdString(), ui->lastNmae_le->text().toStdString(), ui->age_spin->value(), ui->idNumber_spin->value(), "role"));

}


void Sign_up_page::on_back_push_clicked()
{
    this->close();
    mainwindow->setCentralWidget(new Home(this->mainwindow));
    return;
}

