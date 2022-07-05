#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <QMessageBox>
#include <QAbstractButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>
#include <QSpinBox>
#include <QDialog>
#include "employee_add_product_dialog.h"
#include <vector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QtDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mkdir("database");

    connect(this, SIGNAL(throw_error), this,SLOT(display_error));

    this->setWindowTitle("Hyper Market Manager System");
    this->setCentralWidget(new Home(this));
    this->setWindowIcon(QIcon(":/store.png"));


    QPixmap bkgnd(":/image2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::customer_window()
{
    set_customer_window_ui();
    display_shop_product(customerVandFTable, "Vegetable and Fruit");
    display_shop_product(customerDairyTable, "Dairy");
    display_shop_product(customerBeverageTable, "Beverage");
    display_shop_product(customerSnackTable, "Snack");
    display_shop_product(customerNoneFoodTable, "None-Food");

}

void MainWindow::set_customer_window_ui()
{
    //--------------- vegetable and food table ----------------
    QLineEdit * searchLe = new QLineEdit;
    searchLe->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush = new QPushButton("Search");
    searchPush->setStyleSheet("color: red");
    QHBoxLayout * searchLayout = new QHBoxLayout;
    searchLayout->addWidget(searchLe);
    searchLayout->addWidget(searchPush);

    customerVandFTable = new QTableWidget;
    customerVandFTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerVandFTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerVandFTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerVandFTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s;
    s << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerVandFTable->setHorizontalHeaderLabels(s);

    QVBoxLayout *l = new QVBoxLayout;
    l->addLayout(searchLayout);
    l->addWidget(customerVandFTable);
    QGroupBox * gBox = new QGroupBox;
    gBox->setLayout(l);

    //--------------- Dairy table ---------------------

    QLineEdit * searchLe2 = new QLineEdit;
    searchLe2->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush2 = new QPushButton("Search");
    searchPush2->setStyleSheet("color: red");
    QHBoxLayout * searchLayout2 = new QHBoxLayout;
    searchLayout2->addWidget(searchLe2);
    searchLayout2->addWidget(searchPush2);

    customerDairyTable = new QTableWidget;
    customerDairyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerDairyTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerDairyTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerDairyTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s2;
    s2 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerDairyTable->setHorizontalHeaderLabels(s2);

    QVBoxLayout *l2 = new QVBoxLayout;
    l2->addLayout(searchLayout2);
    l2->addWidget(customerDairyTable);
    QGroupBox * gBox2 = new QGroupBox;
    gBox2->setLayout(l2);

    //-------------- Beverage table ---------------

    QLineEdit * searchLe3 = new QLineEdit;
    searchLe3->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush3 = new QPushButton("Search");
    searchPush3->setStyleSheet("color: red");
    QHBoxLayout * searchLayout3 = new QHBoxLayout;
    searchLayout3->addWidget(searchLe3);
    searchLayout3->addWidget(searchPush3);

    customerBeverageTable = new QTableWidget;
    customerBeverageTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerBeverageTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerBeverageTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerBeverageTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s3;
    s3 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerBeverageTable->setHorizontalHeaderLabels(s3);

    QVBoxLayout *l3 = new QVBoxLayout;
    l3->addLayout(searchLayout3);
    l3->addWidget(customerBeverageTable);
    QGroupBox * gBox3 = new QGroupBox;
    gBox3->setLayout(l3);

    //---------------- Snack table --------------------

    QLineEdit * searchLe4 = new QLineEdit;
    searchLe4->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush4 = new QPushButton("Search");
    searchPush4->setStyleSheet("color: red");
    QHBoxLayout * searchLayout4 = new QHBoxLayout;
    searchLayout4->addWidget(searchLe4);
    searchLayout4->addWidget(searchPush4);

    customerSnackTable = new QTableWidget;
    customerSnackTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerSnackTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerSnackTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerSnackTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s4;
    s4 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerSnackTable->setHorizontalHeaderLabels(s4);

    QVBoxLayout *l4 = new QVBoxLayout;
    l4->addLayout(searchLayout4);
    l4->addWidget(customerSnackTable);
    QGroupBox * gBox4 = new QGroupBox;
    gBox4->setLayout(l4);

    //------------------- None-Food table ------------------

    QLineEdit * searchLe5 = new QLineEdit;
    searchLe5->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush5 = new QPushButton("Search");
    searchPush5->setStyleSheet("color: red");
    QHBoxLayout * searchLayout5 = new QHBoxLayout;
    searchLayout5->addWidget(searchLe5);
    searchLayout5->addWidget(searchPush5);

    customerNoneFoodTable = new QTableWidget;
    customerNoneFoodTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerNoneFoodTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerNoneFoodTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerNoneFoodTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s5;
    s5 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerNoneFoodTable->setHorizontalHeaderLabels(s5);

    QVBoxLayout *l5 = new QVBoxLayout;
    l5->addLayout(searchLayout5);
    l5->addWidget(customerNoneFoodTable);
    QGroupBox * gBox5 = new QGroupBox;
    gBox5->setLayout(l5);

    //--------------- Category tab ----------------------

    customerCategoryTab = new QTabWidget;
    customerCategoryTab->addTab(gBox, "Vegatable and Fruit");
    customerCategoryTab->addTab(gBox2,"Dairy");
    customerCategoryTab->addTab(gBox3,"Beverage");
    customerCategoryTab->addTab(gBox4,"Snack");
    customerCategoryTab->addTab(gBox5, "None-Food");

    //--------------- Cart table --------------------

    customerCartTable = new QTableWidget;
    customerCartTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    customerCartTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    customerCartTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    customerCartTable->setColumnCount(5);  // assign the number of columns in the table
    QStringList s6;
    s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    customerCartTable->setHorizontalHeaderLabels(s6);
    //add buttons to purchase

    //------------------ Shop History ToolBox -------------

    customerShopHistoryToolBox = new QToolBox;
    // example
    QTableWidget *t = new QTableWidget(1,4);
    QPushButton *b = new QPushButton("ssss");
    customerShopHistoryToolBox->addItem(b,"purchase 1");
    customerShopHistoryToolBox->addItem(t,"purchase 2");

    //------------------- wallet tab --------------------

    customerCredit = new QSpinBox;
    customerCredit->setStyleSheet("font-size: 30px;");
    customerCredit->setReadOnly(true);
    QLabel *lable = new QLabel("your current credit in wallet is:");
    lable->setStyleSheet("font-size: 30px;");

    QPushButton *p = new QPushButton("increas credit");
    p->setStyleSheet("font-size: 20px;");

    QVBoxLayout *v = new QVBoxLayout;
    v->addWidget(lable);
    v->addWidget(customerCredit);
    v->addWidget(p);
    v->setAlignment(Qt::AlignTop);

    QGroupBox *walletGroup = new QGroupBox;
    walletGroup->setLayout(v);



    //----------------- Main Tab --------------------

    customerMaintab = new QTabWidget;
    customerMaintab->setIconSize(QSize(24, 24));
    customerMaintab->addTab(customerCategoryTab, QIcon("E:/FBT_project/f.b.t/icons/cash_register.png"), tr("Shop"));
    customerMaintab->addTab(customerCartTable,"Cart");
    customerMaintab->addTab(customerShopHistoryToolBox,"shop History");
    customerMaintab->addTab(walletGroup, "Wallet");



    this->setCentralWidget(customerMaintab);
}

void MainWindow::employee_window()
{
    set_employee_window_ui();

    connect(employeeAddProduct,&QPushButton::clicked, this, &MainWindow::employeeAddProductdialog);

    display_shop_product(employeeVandFTable, "Vegetable and Fruit");
    display_shop_product(employeeDairyTable, "Dairy");
    display_shop_product(employeeBeverageTable, "Beverage");
    display_shop_product(employeeSnackTable, "Snack");
    display_shop_product(employeeNoneFoodTable, "None-Food");
}

void MainWindow::set_employee_window_ui()
{
    //--------------- vegetable and food table ----------------
    QLineEdit * searchLe = new QLineEdit;
    searchLe->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush = new QPushButton("Search");
    searchPush->setStyleSheet("color: red");
    QHBoxLayout * searchLayout = new QHBoxLayout;
    searchLayout->addWidget(searchLe);
    searchLayout->addWidget(searchPush);

    employeeVandFTable = new QTableWidget;
    employeeVandFTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeVandFTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeVandFTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeVandFTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s;
    s << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    employeeVandFTable->setHorizontalHeaderLabels(s);

    QVBoxLayout *l = new QVBoxLayout;
    l->addLayout(searchLayout);
    l->addWidget(employeeVandFTable);
    QGroupBox * gBox = new QGroupBox;
    gBox->setLayout(l);


    //--------------- Dairy table ---------------------

    QLineEdit * searchLe2 = new QLineEdit;
    searchLe2->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush2 = new QPushButton("Search");
    searchPush2->setStyleSheet("color: red");
    QHBoxLayout * searchLayout2 = new QHBoxLayout;
    searchLayout2->addWidget(searchLe2);
    searchLayout2->addWidget(searchPush2);

    employeeDairyTable = new QTableWidget;
    employeeDairyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeDairyTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeDairyTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeDairyTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s2;
    s2 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    employeeDairyTable->setHorizontalHeaderLabels(s2);

    QVBoxLayout *l2 = new QVBoxLayout;
    l2->addLayout(searchLayout2);
    l2->addWidget(employeeDairyTable);
    QGroupBox * gBox2 = new QGroupBox;
    gBox2->setLayout(l2);


    //-------------- Beverage table ---------------

    QLineEdit * searchLe3 = new QLineEdit;
    searchLe3->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush3 = new QPushButton("Search");
    searchPush3->setStyleSheet("color: red");
    QHBoxLayout * searchLayout3 = new QHBoxLayout;
    searchLayout3->addWidget(searchLe3);
    searchLayout3->addWidget(searchPush3);

    employeeBeverageTable = new QTableWidget;
    employeeBeverageTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeBeverageTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeBeverageTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeBeverageTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s3;
    s3 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    employeeBeverageTable->setHorizontalHeaderLabels(s3);

    QVBoxLayout *l3 = new QVBoxLayout;
    l3->addLayout(searchLayout3);
    l3->addWidget(employeeBeverageTable);
    QGroupBox * gBox3 = new QGroupBox;
    gBox3->setLayout(l3);


    //---------------- Snack table --------------------

    QLineEdit * searchLe4 = new QLineEdit;
    searchLe4->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush4 = new QPushButton("Search");
    searchPush4->setStyleSheet("color: red");
    QHBoxLayout * searchLayout4 = new QHBoxLayout;
    searchLayout4->addWidget(searchLe4);
    searchLayout4->addWidget(searchPush4);

    employeeSnackTable = new QTableWidget;
    employeeSnackTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeSnackTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeSnackTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeSnackTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s4;
    s4 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    employeeSnackTable->setHorizontalHeaderLabels(s4);

    QVBoxLayout *l4 = new QVBoxLayout;
    l4->addLayout(searchLayout4);
    l4->addWidget(employeeSnackTable);
    QGroupBox * gBox4 = new QGroupBox;
    gBox4->setLayout(l4);


    //------------------- None-Food table ------------------

    QLineEdit * searchLe5 = new QLineEdit;
    searchLe5->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush5 = new QPushButton("Search");
    searchPush5->setStyleSheet("color: red");
    QHBoxLayout * searchLayout5 = new QHBoxLayout;
    searchLayout5->addWidget(searchLe5);
    searchLayout5->addWidget(searchPush5);

    employeeNoneFoodTable = new QTableWidget;
    employeeNoneFoodTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeNoneFoodTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeNoneFoodTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeNoneFoodTable->setColumnCount(4);  // assign the number of columns in the table
    QStringList s5;
    s5 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    employeeNoneFoodTable->setHorizontalHeaderLabels(s5);

    QVBoxLayout *l5 = new QVBoxLayout;
    l5->addLayout(searchLayout5);
    l5->addWidget(employeeNoneFoodTable);
    QGroupBox * gBox5 = new QGroupBox;
    gBox5->setLayout(l5);


    //---------------- Category tab ---------------
    employeeCategoryTab = new QTabWidget;
    employeeCategoryTab->addTab(gBox, "Vegatable and Fruit");
    employeeCategoryTab->addTab(gBox2,"Dairy");
    employeeCategoryTab->addTab(gBox3,"Beverage");
    employeeCategoryTab->addTab(gBox4,"Snack");
    employeeCategoryTab->addTab(gBox5, "None-Food");


    employeeAddProduct = new QPushButton("Add Product");
    QPushButton *removeProduct = new QPushButton("Remove Product");
    QHBoxLayout *hh = new QHBoxLayout;
    hh->addWidget(employeeAddProduct);
    hh->addWidget(removeProduct);
    hh->setAlignment(Qt::AlignLeft);
    QVBoxLayout *vv = new QVBoxLayout;
    vv->addWidget(employeeCategoryTab);
    vv->addLayout(hh);

    QGroupBox *gg = new QGroupBox;
    gg->setLayout(vv);


    //------------- Main tab ------------
    employeeMaintab = new QTabWidget;
    employeeMaintab->addTab(gg, "Shop Products");


    this->setCentralWidget(employeeMaintab);

}

void MainWindow::employee_add_product()
{
    QFile f("database/shopproducts.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    foreach (QJsonValue x, o["Products"].toArray())
    {
        if(x["Category"].toString() == "Vegetable and Fruit")
            display_shop_product(employeeVandFTable, "Vegetable and Fruit");
        else if(x["Category"].toString() == "Dairy")
            display_shop_product(employeeDairyTable, "Dairy");
        else if(x["Category"].toString() == "Beverage")
            display_shop_product(employeeBeverageTable, "Beverage");
        else if(x["Category"].toString() == "Snack")
            display_shop_product(employeeSnackTable, "Snack");
        else if(x["Category"].toString() == "None-Food")
            display_shop_product(employeeNoneFoodTable, "None-Food");
    }


}

void MainWindow::display_shop_product(QTableWidget *table, QString category)
{
    QFile f("database/shopproducts.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    int counter=0;
    vector<Product> vec;

    foreach (QJsonValue x, o["Products"].toArray())
    {
        if(x["Category"].toString() == category)
            counter++;
    }
    table->setRowCount(counter);
    counter = 0;
    foreach (QJsonValue x, o["Products"].toArray())
    {
        if(x["Category"].toString() == category)
        {
            table->setItem(counter, 0, new QTableWidgetItem(x["Name"].toString()));
            table->setItem(counter, 1, new QTableWidgetItem(x["Manufacturer"].toString()));
            table->setItem(counter, 2, new QTableWidgetItem(QString::number(x["Price"].toInt())));
            table->setItem(counter, 3, new QTableWidgetItem(x["Expiry date"].toString()));
            counter++;
        }
    }
}

void MainWindow::display_error(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Critical, "Error", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon("E:/FBT_project/f.b.t/icons/ok.png"));
    box->setMinimumWidth(300);
    box->show();
    connect(box,&QMessageBox::buttonClicked,box,&QMessageBox::deleteLater, Qt::QueuedConnection);
    return;
}

void MainWindow::display_info(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Information, "Error", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon("E:/FBT_project/f.b.t/icons/ok.png"));
    box->setFixedSize(QSize(300,200));
    box->show();
    connect(box,&QMessageBox::buttonClicked,box,&QMessageBox::deleteLater, Qt::QueuedConnection);
    return;
}

void MainWindow::employeeAddProductdialog()
{
    employee_add_product_dialog *dialog = new employee_add_product_dialog(this);
    dialog->show();
}

