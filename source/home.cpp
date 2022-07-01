#include "home.h"
#include "ui_home.h"
#include "login_page.h"
#include "sign_up_page.h"
#include <QMainWindow>

#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

#include <fstream>
using namespace std;

Home::Home(QMainWindow * mw,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    this->mainWindow = mw;


    ui->label->setAlignment(Qt::AlignCenter);

    //----------------- set icons ---------------------

    ui->exit_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/exit.png"));
    ui->exit_push->setIconSize(QSize(40,40));
    ui->about_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/about.png"));
    ui->about_push->setIconSize(QSize(40,40));
    ui->login_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/login2.png"));
    ui->login_push->setIconSize(QSize(50,50));
    ui->sign_up_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/signup.png"));
    ui->sign_up_push->setIconSize(QSize(60,60));


    //----------------- set stylesheets ---------------------

    ui->exit_push->setStyleSheet(
    "*{background-color:#f5ced2; "
    "border-radius:28px;"
    "border:2px solid #f20505;}"
    "*:hover{background: '#f2acb3';}"
    );

    ui->about_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:28px;}"
    "*:hover{background: '#aeb6f5';}"
    );

    ui->login_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:35px;}"
    "*:hover{background: '#aeb6f5';}"
    );

    ui->sign_up_push->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:35px;}"
    "*:hover{background: '#aeb6f5';}"
    );
}

Home::~Home()
{
    delete ui;
}




void Home::on_login_push_clicked()
{
    Login_page *loginPage = new Login_page(this->mainWindow);
    this->close();
    mainWindow->setCentralWidget(loginPage);
}


void Home::on_exit_push_clicked()
{
    mainWindow->close();
}


void Home::on_sign_up_push_clicked()
{
    Sign_up_page *signUpPage = new Sign_up_page(this->mainWindow);
    this->close();
    mainWindow->setCentralWidget(signUpPage);
}

