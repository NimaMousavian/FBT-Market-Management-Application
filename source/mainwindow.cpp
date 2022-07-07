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
#include <QModelIndexList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "customer_invoice.h"

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
    palette.setBrush(QPalette::Background, bkgnd);
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
    searchPush->setStyleSheet("color: red;");
    QHBoxLayout * searchLayout = new QHBoxLayout;
    searchLayout->addWidget(searchLe);
    searchLayout->addWidget(searchPush);
    QPushButton * addToCartPush = new QPushButton("Add to cart");
    QHBoxLayout * addLayout = new QHBoxLayout;
    addLayout->addWidget(addToCartPush);
    addLayout->setAlignment(Qt::AlignLeft);
    connect(addToCartPush,&QPushButton::clicked,this,[this]{customerAddToCart(customerVandFTable);});

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
    l->addLayout(addLayout);
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
    QPushButton * addToCartPush2 = new QPushButton("Add to cart");
    QHBoxLayout * addLayout2 = new QHBoxLayout;
    addLayout2->addWidget(addToCartPush2);
    addLayout2->setAlignment(Qt::AlignLeft);
    connect(addToCartPush2,&QPushButton::clicked,this,[this]{customerAddToCart(customerDairyTable);});


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
    l2->addLayout(addLayout2);
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
    QPushButton * addToCartPush3 = new QPushButton("Add to cart");
    QHBoxLayout * addLayout3 = new QHBoxLayout;
    addLayout3->addWidget(addToCartPush3);
    addLayout3->setAlignment(Qt::AlignLeft);
    connect(addToCartPush3,&QPushButton::clicked,this,[this]{customerAddToCart(customerBeverageTable);});

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
    l3->addLayout(addLayout3);
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
    QPushButton * addToCartPush4 = new QPushButton("Add to cart");
    QHBoxLayout * addLayout4 = new QHBoxLayout;
    addLayout4->addWidget(addToCartPush4);
    addLayout4->setAlignment(Qt::AlignLeft);
    connect(addToCartPush4,&QPushButton::clicked,this,[this]{customerAddToCart(customerSnackTable);});

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
    l4->addLayout(addLayout4);
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
    QPushButton * addToCartPush5 = new QPushButton("Add to cart");
    QHBoxLayout * addLayout5 = new QHBoxLayout;
    addLayout5->addWidget(addToCartPush5);
    addLayout5->setAlignment(Qt::AlignLeft);
    connect(addToCartPush5,&QPushButton::clicked,this,[this]{customerAddToCart(customerNoneFoodTable);});

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
    l5->addLayout(addLayout5);
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

    QPushButton * pur = new QPushButton("Purchase");
    QPushButton * removProduct = new QPushButton("Remove from Cart");
    QHBoxLayout * purchaseLayout = new QHBoxLayout;
    purchaseLayout->addWidget(pur);
    purchaseLayout->addWidget(removProduct);
    purchaseLayout->setAlignment(Qt::AlignLeft);
    connect(pur,&QPushButton::clicked, this, [this]{customerPurchase();});
    connect(removProduct,&QPushButton::clicked, this, [this]{removeFromCart();});
    QVBoxLayout * cl = new QVBoxLayout;
    cl->addWidget(customerCartTable);
    cl->addLayout(purchaseLayout);
    QGroupBox * cartGroup = new QGroupBox;
    cartGroup->setLayout(cl);

    //------------------ Shop History ToolBox -------------

    customerShopHistoryToolBox = new QToolBox;
    // example
//    QTableWidget *t = new QTableWidget(1,4);
//    QPushButton *b = new QPushButton("ssss");
//    customerShopHistoryToolBox->addItem(b,"purchase 1");
//    customerShopHistoryToolBox->addItem(t,"purchase 2");

    //------------------- wallet tab --------------------

    customerCredit = new QSpinBox;
    customerCredit->setStyleSheet("font-size: 30px;");
    customerCredit->setReadOnly(true);
    customerCredit->setMaximum(10000000);
    QLabel *lable = new QLabel("your current credit in wallet is:");
    lable->setStyleSheet("font-size: 30px;");

    QPushButton *increasCredit = new QPushButton("increas credit");
    increasCredit->setStyleSheet("font-size: 12px;");
    QHBoxLayout * icLayout = new QHBoxLayout;
    icLayout->addWidget(increasCredit);
    icLayout->setAlignment(Qt::AlignLeft);

    QVBoxLayout *v = new QVBoxLayout;
    v->addWidget(lable);
    v->addWidget(customerCredit);
    v->addLayout(icLayout);
    v->setAlignment(Qt::AlignTop);

    QGroupBox *walletGroup = new QGroupBox;
    walletGroup->setLayout(v);



    //----------------- Main Tab --------------------

    customerMaintab = new QTabWidget;
    customerMaintab->setIconSize(QSize(24, 24));
    customerMaintab->addTab(customerCategoryTab, QIcon("E:/FBT_project/f.b.t/icons/cash_register.png"), tr("Shop"));
    customerMaintab->addTab(cartGroup,"Cart");
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

void MainWindow::set_customer_credit(int a)
{
    this->customerCredit->setValue(a);
    return;
}

void MainWindow::add_purchase_to_history()
{
    QTableWidget * purchase = new QTableWidget;
    purchase->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    purchase->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    purchase->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    purchase->setColumnCount(5);  // assign the number of columns in the table
    QStringList s6;
    s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    purchase->setHorizontalHeaderLabels(s6);

    purchase->setRowCount(customerCartTable->rowCount());
    for (int i=0; i<customerCartTable->rowCount(); i++)
    {
        purchase->setItem(i,0, new QTableWidgetItem(customerCartTable->item(i,0)->text()));
        purchase->setItem(i,1, new QTableWidgetItem(customerCartTable->item(i,1)->text()));
        purchase->setItem(i,2, new QTableWidgetItem(customerCartTable->item(i,2)->text()));
        purchase->setItem(i,3, new QTableWidgetItem(customerCartTable->item(i,3)->text()));
        purchase->setItem(i,4, new QTableWidgetItem(customerCartTable->item(i,4)->text()));
    }

    QVBoxLayout * l = new QVBoxLayout;
    l->addWidget(purchase);
    QGroupBox * g = new QGroupBox;
    g->setLayout(l);
    customerShopHistoryToolBox->addItem(g, "purchase 1");
}

void MainWindow::display_error(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Critical, "Error", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon(":/ok.png"));
    box->setWindowIcon(QIcon(":/store.png"));
    box->setMinimumWidth(300);
    box->show();
    connect(box,&QMessageBox::buttonClicked,box,&QMessageBox::deleteLater, Qt::QueuedConnection);
    return;
}

void MainWindow::display_info(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Information, "Information", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon(":/ok.png"));
    box->setWindowIcon(QIcon(":/store.png"));
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

void MainWindow::customerAddToCart(QTableWidget* sourceTable)
{
    QString category;
    if (sourceTable == customerVandFTable)
        category = "Vagetable and Fruit";
    else if (sourceTable == customerDairyTable)
        category = "Dairy";
    else if (sourceTable == customerBeverageTable)
        category = "Beverage";
    else if (sourceTable == customerSnackTable)
        category = "Snack";
    else if (sourceTable == customerNoneFoodTable)
        category = "None-Food";

    QItemSelectionModel  *s = sourceTable->selectionModel();
    QModelIndexList  selectedRows = s->selectedRows();
    if (selectedRows.size() > 0)
    {
        int row = selectedRows.first().row();
        QString name = sourceTable->item(row, 0)->text();
        QString manufacturer = sourceTable->item(row, 1)->text();
        QString price = sourceTable->item(row, 2)->text();
        QString expDate = sourceTable->item(row, 3)->text();
        customerCartTable->insertRow(customerCartTable->rowCount());
        customerCartTable->setItem(customerCartTable->rowCount()-1,0, new QTableWidgetItem(name));
        customerCartTable->setItem(customerCartTable->rowCount()-1,1, new QTableWidgetItem(category));
        customerCartTable->setItem(customerCartTable->rowCount()-1,2, new QTableWidgetItem(manufacturer));
        customerCartTable->setItem(customerCartTable->rowCount()-1,3, new QTableWidgetItem(price));
        customerCartTable->setItem(customerCartTable->rowCount()-1,4, new QTableWidgetItem(expDate));
        sourceTable->clearSelection();
        display_info("product succefully added to cart.");
    }
    else
    {
        this->display_info("Please select a product!");
    }
    return;
}

void MainWindow::customerPurchase()
{
    if (customerCartTable->rowCount() == 0)
    {
        display_error("your cart is empty!");
    }
    else
    {
        customer_invoice * invoic = new customer_invoice(this,"sajad", "8766", customerCartTable, 100000, 3000);
        invoic->show();
    }
    return;
}

void MainWindow::removeFromCart()
{
    QItemSelectionModel  *s = customerCartTable->selectionModel();
    QModelIndexList  selectedRows = s->selectedRows();
    if (selectedRows.size() > 0)
    {
        customerCartTable->removeRow(selectedRows.first().row());
        display_info("product succefully removed from cart.");
    }
    else
    {
        this->display_info("Please select a product!");
    }
    customerCartTable->clearSelection();
    return;
}

