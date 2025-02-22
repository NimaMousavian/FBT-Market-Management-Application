#include "addtocart_dialog.h"
#include "ui_addtocart_dialog.h"
#include "mainwindow.h"
#include <QTableWidgetItem>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

addtocart_dialog::addtocart_dialog(QString name, QString category, QString manu, QString price, QString exp_date, MainWindow * mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtocart_dialog)
{
    ui->setupUi(this);
    this->mainwindow = mw;

    this->setWindowIcon(QIcon(":/store.png"));
    this->setWindowTitle("Add to cart");

    ui->product_table->setItem(0,0, new QTableWidgetItem(name));
    ui->product_table->setItem(0,1, new QTableWidgetItem(category));
    ui->product_table->setItem(0,2, new QTableWidgetItem(manu));
    ui->product_table->setItem(0,3, new QTableWidgetItem(price));
    ui->product_table->setItem(0,4, new QTableWidgetItem(exp_date));

    //----------------- set push buttons icons ------------------

    ui->addButton->setIcon(QIcon(":/add.png"));
    ui->discardBotton->setIcon(QIcon(":/cancel.png"));

    //----------------- set push buttons stylesheet -------------------

    ui->addButton->setStyleSheet(
    "*{background-color:#91c3c1;"
    "border:2px solid #0e5b56;"
    "border-radius:12px;}"
    "*:hover{background: '#568c89';}");

    ui->discardBotton->setStyleSheet(
    "*{background-color:#f1a2a2; "
    "border-radius:12px;"
    "border:2px solid #e24544;}"
    "*:hover{background: '#eb7d7c';}");

    //----------------- set line edits stylesheet -------------------------
    ui->amountSpinBox->setStyleSheet("background-color:#a1cfcd; border:2px solid #0e5b56; border-radius:12px;");
}

addtocart_dialog::~addtocart_dialog()
{
    delete ui;
}


void addtocart_dialog::if_product_one()
{
    QFile f("database/shopproducts.json");
    f.open(QIODevice::ReadOnly);
    if(f.isOpen())
    {
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray p = o["Products"].toArray();
        QJsonArray result;

        foreach (QJsonValue x, p)
        {
            if(x["Name"].toString() != ui->product_table->item(0,0)->text() && x["Manufacturer"].toString() != ui->product_table->item(0,1)->text())
            {
                result.append(x.toObject());
            }
        }

        QJsonObject v;
        v["Products"] = result;
        QJsonDocument u(v);
        QFile w("database/shopproducts.json");
        w.open(QIODevice::WriteOnly);
        w.write(u.toJson());
    }
}

void addtocart_dialog::on_addButton_clicked()
{
    QFile f("database/stockproducts.json");
    f.open(QIODevice::ReadOnly);
    if(f.isOpen())
    {
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray p = o["Products"].toArray();
        QJsonArray result;

        foreach (QJsonValue x, p)
        {
            if(x["Name"].toString() == ui->product_table->item(0,0)->text() && x["Manufacturer"].toString() == ui->product_table->item(0,2)->text())
            {
                if (x["Amount"].toInt() < ui->amountSpinBox->value())
                {
                    mainwindow->display_error("this amount of this product doesn't exist in store stock!");
                    return;
                }
                else
                {
                    int i = x["Amount"].toInt();
                    if(i - ui->amountSpinBox->value() != 0)
                    {
                        i -= ui->amountSpinBox->value();
                        QJsonObject j;
                        j["Name"] = x["Name"].toString();
                        j["Category"] = x["Category"].toString();
                        j["Manufacturer"] = x["Manufacturer"].toString();
                        j["Price"] = x["Price"].toInt();
                        j["Expiry date"] = x["Expiry date"].toString();
                        j["Amount"] = i;
                        result.append(j);
                    }
                    else
                    {
                        if_product_one();
                    }
                }
            }
            else
            {
                result.append(x.toObject());
            }
        }

        QJsonObject v;
        v["Products"] = result;
        QJsonDocument u(v);
        QFile w("database/stockproducts.json");
        w.open(QIODevice::WriteOnly);
        w.write(u.toJson());

        mainwindow->customer_add_to_cart(ui->product_table->item(0,0)->text(), ui->product_table->item(0,1)->text(), ui->product_table->item(0,2)->text(), ui->product_table->item(0,3)->text(), ui->product_table->item(0,4)->text(), QString::number(ui->amountSpinBox->value()));
        this->close();
    }
}



void addtocart_dialog::on_discardBotton_clicked()
{
    this->close();
    return;
}

