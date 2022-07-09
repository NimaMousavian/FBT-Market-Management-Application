#include "aboutus_page.h"
#include "ui_aboutus_page.h"
#include "home.h"
#include <string.h>

aboutUs_page::aboutUs_page(MainWindow *mw,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboutUs_page)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    //----------------- set push buttons stylesheet -------------------

    ui->backBotton->setStyleSheet(
    "*{background-color:#fcde73;"
    "border:2px solid #fad037;"
    "border-radius:25px;}"
    "*:hover{background: '#fbd95f';}");

}

aboutUs_page::~aboutUs_page()
{
    delete ui;
}

void aboutUs_page::on_backBotton_clicked()
{
    this->close();
    mainwindow->setCentralWidget(new Home(this->mainwindow));
    mainwindow->setMinimumSize(QSize(1000,725));
}

