#include "increase_credit_dialog.h"
#include "ui_increase_credit_dialog.h"
#include "mainwindow.h"

increase_credit_dialog::increase_credit_dialog(MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::increase_credit_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    //----------------- set push buttons icons ------------------

    ui->payButton->setIcon(QIcon(":/pay.png"));
    ui->discardBotton->setIcon(QIcon(":/don'tPay.png"));

    //----------------- set push buttons stylesheet -------------------

    ui->payButton->setStyleSheet(
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
    ui->cardName_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->cardNo_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->dateEdit->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");
    ui->cvv_le->setStyleSheet("background-color:#e6e8fc; border:2px solid #828ff5; border-radius:10px;");


}

increase_credit_dialog::~increase_credit_dialog()
{
    delete ui;
}


void increase_credit_dialog::on_payButton_clicked()
{
    //------------controls before pay-----------
    if (ui->cardName_le->text().isEmpty() || ui->cardNo_le->text().isEmpty() || ui->cvv_le->text().isEmpty())
    {
        mainwindow->display_error("Please fill out required fields.");
    }
    else
    {

    //-------------------pay operation------------
        mainwindow->customer_increase_credit(ui->amountSpinBox->value());
        this->close();
    }
}


void increase_credit_dialog::on_discardBotton_clicked()
{
    this->close();
}

