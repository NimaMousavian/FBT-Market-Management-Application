#ifndef CUSTOMER_INVOICE_H
#define CUSTOMER_INVOICE_H

#include <QDialog>
#include "mainwindow.h"
#include <QTableWidget>
#include <QJsonArray>

namespace Ui {
class customer_invoice;
}

class customer_invoice : public QDialog
{
    Q_OBJECT

public:
    explicit customer_invoice(MainWindow*, QString name, QString cu_ID, QTableWidget * table, int credit, int discout=0, QWidget *parent = nullptr);
    ~customer_invoice();

private slots:
    void on_candel_push_clicked();

    void on_purchase_push_clicked();

private:
    Ui::customer_invoice *ui;

    MainWindow * mainwindow;
    void create_table(QTableWidget *);
    void save_invoic();
    QJsonArray create_products_json();

};

#endif // CUSTOMER_INVOICE_H
