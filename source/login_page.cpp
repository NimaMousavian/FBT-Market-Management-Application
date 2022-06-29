#include "login_page.h"
#include "ui_login_page.h"
#include "home.h"

Login_page::Login_page(QMainWindow *mw,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login_page)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    ui->back_push->setIcon(QIcon("E:/C++_T2/FBT_Gui/icons/go back.png"));
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

