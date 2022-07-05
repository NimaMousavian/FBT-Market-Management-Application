#ifndef EMPLOYEE_ADD_PRODUCT_DIALOG_H
#define EMPLOYEE_ADD_PRODUCT_DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class employee_add_product_dialog;
}

class employee_add_product_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit employee_add_product_dialog(MainWindow * ,QWidget *parent = nullptr);
    ~employee_add_product_dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::employee_add_product_dialog *ui;
    MainWindow *mainwindow;
};

#endif // EMPLOYEE_ADD_PRODUCT_DIALOG_H
