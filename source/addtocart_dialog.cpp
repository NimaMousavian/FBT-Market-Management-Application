#include "addtocart_dialog.h"
#include "ui_addtocart_dialog.h"
#include "mainwindow.h"
#include <QTableWidgetItem>

addtocart_dialog::addtocart_dialog(QString name, QString manu, QString price, QString exp_date, MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtocart_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    ui->product_table->setItem(0,0, new QTableWidgetItem(name));
    ui->product_table->setItem(0,1, new QTableWidgetItem(manu));
    ui->product_table->setItem(0,2, new QTableWidgetItem(price));
    ui->product_table->setItem(0,3, new QTableWidgetItem(exp_date));

    //----------------- set push buttons icons ------------------

    ui->addButton->setIcon(QIcon(":/add.png"));
    ui->discardBotton->setIcon(QIcon(":/cancel.png"));

    //----------------- set push buttons stylesheet -------------------

    ui->addButton->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:15px;}"
    "*:hover{background: '#aeb6f5';}");

    ui->discardBotton->setStyleSheet(
    "*{background-color:#ced5f5;"
    "border:2px solid #0530f2;"
    "border-radius:15px;}"
    "*:hover{background: '#aeb6f5';}");

    //----------------- set line edits stylesheet -------------------------
    ui->amountSpinBox->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
}

addtocart_dialog::~addtocart_dialog()
{
    delete ui;
}

void addtocart_dialog::on_addButton_clicked()
{

}


void addtocart_dialog::on_discardBotton_clicked()
{
    this->close();
    return;
}

