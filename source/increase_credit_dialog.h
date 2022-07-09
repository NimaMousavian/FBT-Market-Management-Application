#ifndef INCREASE_CREDIT_DIALOG_H
#define INCREASE_CREDIT_DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class increase_credit_dialog;
}

class increase_credit_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit increase_credit_dialog(MainWindow *, QWidget *parent = nullptr);
    ~increase_credit_dialog();

private slots:
    void on_payButton_clicked();

    void on_discardBotton_clicked();

private:
    Ui::increase_credit_dialog *ui;
    MainWindow * mainwindow;
};

#endif // INCREASE_CREDIT_DIALOG_H
