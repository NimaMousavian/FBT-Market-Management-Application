#include "login_page.h"
#include "ui_login_page.h"
#include "home.h"

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

