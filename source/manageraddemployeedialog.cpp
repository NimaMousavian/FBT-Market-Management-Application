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
}

managerAddEmployeeDialog::~managerAddEmployeeDialog()
{
    delete ui;
}

void managerAddEmployeeDialog::on_pushButton_clicked()
{

    Employee * e = new Employee(ui->fname_le->text().toStdString(), ui->lname_le->text().toStdString(), ui->ageSpinBox->value(), ui->usrname_le->text().toStdString(), ui->pass_le->text().toStdString());
    unique_ptr<Human> h3(e);
    h3->sign_up();
    this->close();
    mainwindow->manager_window();
    mainwindow->display_info("Employee Added.");

}

void managerAddEmployeeDialog::on_pushButton_2_clicked()
{
    this->close();
}

