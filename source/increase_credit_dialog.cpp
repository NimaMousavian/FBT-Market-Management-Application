#include "increase_credit_dialog.h"
#include "ui_increase_credit_dialog.h"
#include "mainwindow.h"

increase_credit_dialog::increase_credit_dialog(MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::increase_credit_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Increase Credit");

    //----------------- set push buttons icons ------------------

//    ui->payButton->setIcon(QIcon(":/pay.png"));
//    ui->discardBotton->setIcon(QIcon(":/don'tPay.png"));

    //----------------- set push buttons stylesheet -------------------

    ui->payButton->setStyleSheet(
    "*{background-color:#6570ae;"
    "border:2px solid #23338b;"
    "border-radius:25px;}"
    "*:hover{background: '#394797';}");

    ui->discardBotton->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:25px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    //----------------- set line edits stylesheet -------------------------
    ui->amountSpinBox->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->cardName_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->cardNo_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->dateEdit->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->cvv_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");


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

