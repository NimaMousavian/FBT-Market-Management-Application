#include "employee_add_product_dialog.h"
#include "ui_employee_add_product_dialog.h"
#include "product.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

employee_add_product_dialog::employee_add_product_dialog(MainWindow* mw,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee_add_product_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;
    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Add Product");

    //----------------- set push buttons stylesheet -------------------

    ui->cancleButton->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:25px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    ui->pushButton->setStyleSheet(
    "*{background-color:#6570ae;"
    "border:2px solid #23338b;"
    "border-radius:25px;}"
    "*:hover{background: '#394797';}");

    //----------------- set line edits stylesheet -------------------------

    ui->name_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->category_combo->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->amount_spin->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->price_spin->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->exp_date->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
    ui->manu_le->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");

}

employee_add_product_dialog::~employee_add_product_dialog()
{
    delete ui;
}

void employee_add_product_dialog::on_pushButton_clicked()
{
    //------------ controls before add ----------

    if (ui->name_le->text().isEmpty() || ui->exp_date->text().isEmpty() || ui->manu_le->text().isEmpty() || ui->price_spin->value()==0)
        mainwindow->display_error("Please fill out required fields.");
    else
    {
        //------------ add product ----------------
        QFile f("database/stockproducts.json");
        f.open(QIODevice::ReadOnly);
        if(f.isOpen())
        {
            QByteArray b = f.readAll();
            QJsonDocument d = QJsonDocument::fromJson(b);
            QJsonObject o = d.object();
            QJsonArray p = o["Products"].toArray();
            QJsonObject r;
            r["Name"] = ui->name_le->text();
            r["Category"] = ui->category_combo->currentText();
            r["Manufacturer"] = ui->manu_le->text();
            r["Price"] = ui->price_spin->value();
            r["Expiry date"] = ui->exp_date->date().toString("dd/MM/yyyy");
            r["Amount"] = ui->amount_spin->value();
            QJsonArray product = p;
            product.append(r);
            QJsonObject v;
            v["Products"] = product;
            QJsonDocument u(v);
            QFile w("database/stockproducts.json");
            w.open(QIODevice::WriteOnly);
            w.write(u.toJson());

        }
        else
        {
            QFile z("database/stockproducts.json");
            z.open(QIODevice::WriteOnly);

            QJsonObject j;
            QJsonArray products;
            QJsonObject t;
            t["Name"] = ui->name_le->text();
            t["Category"] = ui->category_combo->currentText();
            t["Manufacturer"] = ui->manu_le->text();
            t["Price"] = ui->price_spin->value();
            t["Expiry date"] = ui->exp_date->date().toString("dd/MM/yyyy");
            t["Amount"] = ui->amount_spin->value();
            products.append(t);
            j["Products"] = products;

            QJsonDocument d(j);
            z.write(d.toJson());
        }

        mainwindow->employee_add_product_to_stock();
        this->close();
    }

}




void employee_add_product_dialog::on_cancleButton_clicked()
{
    this->close();
    return;
}



