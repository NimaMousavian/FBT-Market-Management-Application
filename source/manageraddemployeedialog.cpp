#include "manageraddemployeedialog.h"
#include "ui_manageraddemployeedialog.h"
#include "mainwindow.h"
#include "memory"

managerAddEmployeeDialog::managerAddEmployeeDialog(MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerAddEmployeeDialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Add Employee");

    //----------------- set push buttons stylesheet -------------------

    ui->pushButton->setStyleSheet(
    "*{background-color:#6570ae;"
    "border:2px solid #23338b;"
    "border-radius:25px;}"
    "*:hover{background: '#394797';}");

    ui->pushButton_2->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:25px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    //----------------- set line edits stylesheet -------------------------
    ui->fname_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->lname_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->ageSpinBox->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->usrname_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->pass_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");


}

managerAddEmployeeDialog::~managerAddEmployeeDialog()
{
    delete ui;
}

void managerAddEmployeeDialog::on_pushButton_clicked()
{
    if (ui->fname_le->text().isEmpty() || ui->lname_le->text().isEmpty() || ui->usrname_le->text().isEmpty() || ui->pass_le->text().isEmpty() || ui->ageSpinBox->value() == 0)
        mainwindow->display_error("Please fill out required fields.");
    else if (ui->pass_le->text().count() < 8)
        mainwindow->display_error("Password must have at least 8 characters.");
    else
    {
        Employee * e = new Employee(ui->fname_le->text().toStdString(), ui->lname_le->text().toStdString(), ui->ageSpinBox->value(), ui->usrname_le->text().toStdString(), ui->pass_le->text().toStdString());
        unique_ptr<Human> h3(e);
        h3->sign_up();
        this->close();
        mainwindow->manager_window();
        mainwindow->display_info("Employee Added.");
    }

}

void managerAddEmployeeDialog::on_pushButton_2_clicked()
{
    this->close();
}

