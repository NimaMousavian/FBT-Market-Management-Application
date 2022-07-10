#include "customer_invoice.h"
#include "ui_customer_invoice.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

customer_invoice::customer_invoice(MainWindow * mw, QString name, QString cu_ID, QTableWidget *table, int credit, int discout, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer_invoice)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/store.png"));
    this->mainwindow = mw;

    ui->name_le->setText(name);
    ui->name_le->setReadOnly(true);
    ui->id_le->setText(cu_ID);
    ui->id_le->setReadOnly(true);
    ui->payment_spin->setReadOnly(true);
    ui->discount_spin->setValue(discout);
    ui->discount_spin->setReadOnly(true);
    ui->credit_spin->setValue(credit);
    ui->credit_spin->setReadOnly(true);
    create_table(table);
    ui->payout_spin->setReadOnly(true);
    ui->payout_spin->setValue((ui->payment_spin->value()) - (ui->discount_spin->value()));
    //----------------- set push buttons stylesheet -------------------

    ui->candel_push->setStyleSheet(
    "*{background-color:#fcde73;"
    "border:2px solid #fad037;"
    "border-radius:25px;}"
    "*:hover{background: '#fbcf34';}");

    ui->purchase_push->setStyleSheet(
    "*{background-color:#2c9f9f;"
    "border:2px solid #117676;"
    "border-radius:25px;}"
    "*:hover{background: '#138585';}");

    //----------------- set line edits stylesheet -------------------------

    ui->name_le->setStyleSheet("background-color:#d0f2f0; border:2px solid #3850a8; border-radius:12px;");
    ui->id_le->setStyleSheet("background-color:#d0f2f0; border:2px solid #3850a8; border-radius:12px;");
    ui->products_table->setStyleSheet("background-color:#d0f2f0; border:2px solid #3850a8; border-radius:12px;");
    ui->credit_spin->setStyleSheet("background-color:#f9add0; border:2px solid #ec3580; border-radius:12px;");
    ui->discount_spin->setStyleSheet("background-color:#f9add0; border:2px solid #ec3580; border-radius:12px;");
    ui->payment_spin->setStyleSheet("background-color:#f9add0; border:2px solid #ec3580; border-radius:12px;");
    ui->payout_spin->setStyleSheet("background-color:#f9add0; border:2px solid #ec3580; border-radius:12px;");

    this->setWindowTitle("Receipt");
}

customer_invoice::~customer_invoice()
{
    delete ui;
}

void customer_invoice::create_table(QTableWidget * other)
{
    int py=0;
    ui->products_table->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    ui->products_table->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    ui->products_table->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    ui->products_table->setColumnCount(6);  // assign the number of columns in the table
    QStringList s6;
    s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
    ui->products_table->setHorizontalHeaderLabels(s6);

    ui->products_table->setRowCount(other->rowCount());

    for (int i=0; i<other->rowCount(); i++)
    {
        ui->products_table->setItem(i,0, new QTableWidgetItem(other->item(i,0)->text()));
        ui->products_table->setItem(i,1, new QTableWidgetItem(other->item(i,1)->text()));
        ui->products_table->setItem(i,2, new QTableWidgetItem(other->item(i,2)->text()));
        ui->products_table->setItem(i,3, new QTableWidgetItem(other->item(i,3)->text()));
        ui->products_table->setItem(i,4, new QTableWidgetItem(other->item(i,4)->text()));
        ui->products_table->setItem(i,5, new QTableWidgetItem(other->item(i,5)->text()));
        py += (other->item(i,3)->text().toInt() * other->item(i,5)->text().toInt());
    }
    ui->payment_spin->setValue(py);
}

void customer_invoice::save_invoic()
{
    QFile f("database/invoices.json");
    f.open(QIODevice::ReadOnly);
    if(f.isOpen())
    {
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray p = o["Invoices"].toArray();
        QJsonObject r;
        r["Customer Name"] = ui->name_le->text();
        r["Customer ID"] = ui->id_le->text().toInt();
        r["Products"] = create_products_json();
        r["Payment"] = ui->payment_spin->value();
        r["Discount"] = ui->discount_spin->value();
        r["Payout"] = ui->payout_spin->value();
        QJsonArray invoices = p;
        invoices.append(r);
        QJsonObject v;
        v["Invoices"] = invoices;
        QJsonDocument u(v);
        QFile w("database/invoices.json");
        w.open(QIODevice::WriteOnly);
        w.write(u.toJson());

    }
    else
    {
        QFile z("database/invoices.json");
        z.open(QIODevice::WriteOnly);

        QJsonObject j;
        QJsonArray invoices;
        QJsonObject t;
        t["Customer Name"] = ui->name_le->text();
        t["Customer ID"] = ui->id_le->text();
        t["Products"] = create_products_json();
        t["Payment"] = ui->payment_spin->value();
        t["Discount"] = ui->discount_spin->value();
        t["Payout"] = ui->payout_spin->value();
        invoices.append(t);
        j["Invoices"] = invoices;

        QJsonDocument d(j);
        z.write(d.toJson());
    }

}

QJsonArray customer_invoice::create_products_json()
{
    QJsonArray result;
    for (int i=0; i<ui->products_table->rowCount(); i++)
    {
        QJsonObject j;
        j["Name"] = ui->products_table->item(i,0)->text();
        j["Category"] = ui->products_table->item(i,1)->text();
        j["Manufacturer"] = ui->products_table->item(i,2)->text();
        j["Price"] = ui->products_table->item(i,3)->text().toInt();
        j["Expiry date"] = ui->products_table->item(i,4)->text();
        j["Amount"] = ui->products_table->item(i,5)->text().toInt();
        result.append(j);
    }
    return result;
}

void customer_invoice::on_candel_push_clicked()
{
    this->close();
    return;
}


void customer_invoice::on_purchase_push_clicked()
{
    if (ui->credit_spin->value() >= ui->payout_spin->value() )
    {
        save_invoic();
        mainwindow->customer_increase_credit(- ui->payout_spin->value());
        mainwindow->display_info("your purchase succesfully don.");
        mainwindow->add_purchase_to_history(ui->payment_spin->value(), ui->discount_spin->value(), ui->payout_spin->value());
        this->close();
    }
    else
    {
        mainwindow->display_error("you don't have enough credit to purchase!\nPlease increase your credit.");
    }
    return;
}

