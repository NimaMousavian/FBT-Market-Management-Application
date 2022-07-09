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
#include "addtocart_dialog.h"
#include "increase_credit_dialog.h"
#include "manageraddemployeedialog.h"
#include "manager_remove_employee_dialog.h"
#include "manager_edit_salary_dialog.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mkdir("database");
    mkdir("datebase/customers");

    FBTManager = new Manager("Mamad", "Admini", 31, "FBT_Admin", "1234");
    unique_ptr<Human> h4(FBTManager);
    h4->sign_up();

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

    customer_load_purchases();

    customer_increase_credit();

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
    connect(addToCartPush,&QPushButton::clicked,this,[this]{customerAddToCartDialog(customerVandFTable);});

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
    connect(addToCartPush2,&QPushButton::clicked,this,[this]{customerAddToCartDialog(customerDairyTable);});


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
    connect(addToCartPush3,&QPushButton::clicked,this,[this]{customerAddToCartDialog(customerBeverageTable);});

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
    connect(addToCartPush4,&QPushButton::clicked,this,[this]{customerAddToCartDialog(customerSnackTable);});

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
    connect(addToCartPush5,&QPushButton::clicked,this,[this]{customerAddToCartDialog(customerNoneFoodTable);});

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
    customerCartTable->setColumnCount(6);  // assign the number of columns in the table
    QStringList s6;
    s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
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

    //------------------- wallet tab --------------------

    customerCredit = new QSpinBox;
    customerCredit->setStyleSheet("font-size: 30px;");
    customerCredit->setReadOnly(true);
    customerCredit->setMaximum(10000000);
    QLabel *lable = new QLabel("your current credit in wallet is:");
    lable->setStyleSheet("font-size: 30px;");

    QPushButton *increasCredit = new QPushButton("increas credit");
    increasCredit->setStyleSheet("font-size: 12px;");
    connect(increasCredit, &QPushButton::clicked, this, &MainWindow::increaseCreditDialog);

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
    customerMaintab->addTab(customerCategoryTab, QIcon(":cash_register.png"), tr("Shop"));
    customerMaintab->addTab(cartGroup,"Cart");
    customerMaintab->addTab(customerShopHistoryToolBox,"shop History");
    customerMaintab->addTab(walletGroup, "Wallet");



    this->setCentralWidget(customerMaintab);
}

void MainWindow::employee_window()
{
    set_employee_window_ui();

    connect(employeeStockAddProductToStock,&QPushButton::clicked, this, &MainWindow::employeeAddProductToStockDialog);


    display_shop_product(employeeVandFTable, "Vegetable and Fruit");
    display_shop_product(employeeDairyTable, "Dairy");
    display_shop_product(employeeBeverageTable, "Beverage");
    display_shop_product(employeeSnackTable, "Snack");
    display_shop_product(employeeNoneFoodTable, "None-Food");

    display_stock_product(employeeStockVandFTable, "Vegetable and Fruit");
    display_stock_product(employeeStockDairyTable, "Dairy");
    display_stock_product(employeeStockBeverageTable, "Beverage");
    display_stock_product(employeeStockSnackTable, "Snack");
    display_stock_product(employeeStockNoneFoodTable, "None-Food");

    employee_load_invoices();
}

void MainWindow::set_employee_window_ui()
{

/**************************************************************
 *-------------------- shop tab -------------------------------
 **************************************************************/

    //--------------- vegetable and food table ----------------
    QLineEdit * searchLe = new QLineEdit;
    searchLe->setPlaceholderText(tr("Search by Name"));
    QPushButton * searchPush = new QPushButton("Search");
    searchPush->setStyleSheet("color: red");
    QHBoxLayout * searchLayout = new QHBoxLayout;
    searchLayout->addWidget(searchLe);
    searchLayout->addWidget(searchPush);
    QPushButton * removePush = new QPushButton("Remove Product");
    QHBoxLayout * removeLayout = new QHBoxLayout;
    removeLayout->addWidget(removePush);
    removeLayout->setAlignment(Qt::AlignLeft);
    connect(removePush,&QPushButton::clicked,this,[this]{employeeRemoveProductFromShopSlt(employeeVandFTable);});

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
    l->addLayout(removeLayout);
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
    QPushButton * removePush2 = new QPushButton("Remove Product");
    QHBoxLayout * removeLayout2 = new QHBoxLayout;
    removeLayout2->addWidget(removePush2);
    removeLayout2->setAlignment(Qt::AlignLeft);
    connect(removePush2,&QPushButton::clicked,this,[this]{employeeRemoveProductFromShopSlt(employeeDairyTable);});


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
    l2->addLayout(removeLayout2);
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
    QPushButton * removePush3 = new QPushButton("Remove Product");
    QHBoxLayout * removeLayout3 = new QHBoxLayout;
    removeLayout3->addWidget(removePush3);
    removeLayout3->setAlignment(Qt::AlignLeft);
    connect(removePush3,&QPushButton::clicked,this,[this]{employeeRemoveProductFromShopSlt(employeeBeverageTable);});


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
    l3->addLayout(removeLayout3);
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
    QPushButton * removePush4 = new QPushButton("Remove Product");
    QHBoxLayout * removeLayout4 = new QHBoxLayout;
    removeLayout4->addWidget(removePush4);
    removeLayout4->setAlignment(Qt::AlignLeft);
    connect(removePush4,&QPushButton::clicked,this,[this]{employeeRemoveProductFromShopSlt(employeeSnackTable);});


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
    l4->addLayout(removeLayout4);
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
    QPushButton * removePush5 = new QPushButton("Remove Product");
    QHBoxLayout * removeLayout5 = new QHBoxLayout;
    removeLayout5->addWidget(removePush5);
    removeLayout5->setAlignment(Qt::AlignLeft);
    connect(removePush5,&QPushButton::clicked,this,[this]{employeeRemoveProductFromShopSlt(employeeNoneFoodTable);});


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
    l5->addLayout(removeLayout5);
    QGroupBox * gBox5 = new QGroupBox;
    gBox5->setLayout(l5);


    //---------------- Category tab ---------------
    employeeCategoryTab = new QTabWidget;
    employeeCategoryTab->addTab(gBox, "Vegatable and Fruit");
    employeeCategoryTab->addTab(gBox2,"Dairy");
    employeeCategoryTab->addTab(gBox3,"Beverage");
    employeeCategoryTab->addTab(gBox4,"Snack");
    employeeCategoryTab->addTab(gBox5, "None-Food");




    QHBoxLayout *hh = new QHBoxLayout;
    //hh->addWidget(employeeRemoveProductFromShop);
    QVBoxLayout *vv = new QVBoxLayout;
    hh->setAlignment(Qt::AlignLeft);
    vv->addWidget(employeeCategoryTab);
    vv->addLayout(hh);

    QGroupBox *gg = new QGroupBox;
    gg->setLayout(vv);

/**************************************************************
*-------------------- Stock tab -------------------------------
**************************************************************/

    //--------------- vegetable and food table ----------------
     QLineEdit * searchLe6 = new QLineEdit;
     searchLe6->setPlaceholderText(tr("Search by Name"));
     QPushButton * searchPush6 = new QPushButton("Search");
     searchPush6->setStyleSheet("color: red");
     QHBoxLayout * searchLayout6 = new QHBoxLayout;
     searchLayout6->addWidget(searchLe6);
     searchLayout6->addWidget(searchPush6);
     QPushButton * addToShopPush6 = new QPushButton("Add to Shop");
     QHBoxLayout * addLayout6 = new QHBoxLayout;
     addLayout6->addWidget(addToShopPush6);
     addLayout6->setAlignment(Qt::AlignLeft);
     connect(addToShopPush6,&QPushButton::clicked,this,[this]{employeeAddProductToShopSlt(employeeStockVandFTable,employeeVandFTable);});

     employeeStockVandFTable = new QTableWidget;
     employeeStockVandFTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
     employeeStockVandFTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
     employeeStockVandFTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
     employeeStockVandFTable->setColumnCount(5);  // assign the number of columns in the table
     QStringList s6;
     s6 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
     employeeStockVandFTable->setHorizontalHeaderLabels(s6);

     QVBoxLayout *l6 = new QVBoxLayout;
     l6->addLayout(searchLayout6);
     l6->addWidget(employeeStockVandFTable);
     l6->addLayout(addLayout6);
     QGroupBox * gBox6 = new QGroupBox;
     gBox6->setLayout(l6);


     //--------------- Dairy table ---------------------

     QLineEdit * searchLe7 = new QLineEdit;
     searchLe7->setPlaceholderText(tr("Search by Name"));
     QPushButton * searchPush7 = new QPushButton("Search");
     searchPush7->setStyleSheet("color: red");
     QHBoxLayout * searchLayout7 = new QHBoxLayout;
     searchLayout7->addWidget(searchLe7);
     searchLayout7->addWidget(searchPush7);
     QPushButton * addToShopPush7 = new QPushButton("Add to Shop");
     QHBoxLayout * addLayout7 = new QHBoxLayout;
     addLayout7->addWidget(addToShopPush7);
     addLayout7->setAlignment(Qt::AlignLeft);
     connect(addToShopPush7,&QPushButton::clicked,this,[this]{employeeAddProductToShopSlt(employeeStockDairyTable,employeeDairyTable);});

     employeeStockDairyTable = new QTableWidget;
     employeeStockDairyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
     employeeStockDairyTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
     employeeStockDairyTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
     employeeStockDairyTable->setColumnCount(5);  // assign the number of columns in the table
     QStringList s7;
     s7 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
     employeeStockDairyTable->setHorizontalHeaderLabels(s7);

     QVBoxLayout *l7 = new QVBoxLayout;
     l7->addLayout(searchLayout7);
     l7->addWidget(employeeStockDairyTable);
     l7->addLayout(addLayout7);
     QGroupBox * gBox7 = new QGroupBox;
     gBox7->setLayout(l7);


     //-------------- Beverage table ---------------

     QLineEdit * searchLe8 = new QLineEdit;
     searchLe8->setPlaceholderText(tr("Search by Name"));
     QPushButton * searchPush8 = new QPushButton("Search");
     searchPush8->setStyleSheet("color: red");
     QHBoxLayout * searchLayout8 = new QHBoxLayout;
     searchLayout8->addWidget(searchLe8);
     searchLayout8->addWidget(searchPush8);
     QPushButton * addToShopPush8 = new QPushButton("Add to Shop");
     QHBoxLayout * addLayout8 = new QHBoxLayout;
     addLayout8->addWidget(addToShopPush8);
     addLayout8->setAlignment(Qt::AlignLeft);
     connect(addToShopPush8,&QPushButton::clicked,this,[this]{employeeAddProductToShopSlt(employeeStockBeverageTable,employeeBeverageTable);});

     employeeStockBeverageTable = new QTableWidget;
     employeeStockBeverageTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
     employeeStockBeverageTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
     employeeStockBeverageTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
     employeeStockBeverageTable->setColumnCount(5);  // assign the number of columns in the table
     QStringList s8;
     s8 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
     employeeStockBeverageTable->setHorizontalHeaderLabels(s8);

     QVBoxLayout *l8 = new QVBoxLayout;
     l8->addLayout(searchLayout8);
     l8->addWidget(employeeStockBeverageTable);
     l8->addLayout(addLayout8);
     QGroupBox * gBox8 = new QGroupBox;
     gBox8->setLayout(l8);


     //---------------- Snack table --------------------

     QLineEdit * searchLe9 = new QLineEdit;
     searchLe9->setPlaceholderText(tr("Search by Name"));
     QPushButton * searchPush9 = new QPushButton("Search");
     searchPush9->setStyleSheet("color: red");
     QHBoxLayout * searchLayout9 = new QHBoxLayout;
     searchLayout9->addWidget(searchLe9);
     searchLayout9->addWidget(searchPush9);
     QPushButton * addToShopPush9 = new QPushButton("Add to Shop");
     QHBoxLayout * addLayout9 = new QHBoxLayout;
     addLayout9->addWidget(addToShopPush9);
     addLayout9->setAlignment(Qt::AlignLeft);
     connect(addToShopPush9,&QPushButton::clicked,this,[this]{employeeAddProductToShopSlt(employeeStockSnackTable,employeeSnackTable);});

     employeeStockSnackTable = new QTableWidget;
     employeeStockSnackTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
     employeeStockSnackTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
     employeeStockSnackTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
     employeeStockSnackTable->setColumnCount(5);  // assign the number of columns in the table
     QStringList s9;
     s9 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
     employeeStockSnackTable->setHorizontalHeaderLabels(s9);

     QVBoxLayout *l9 = new QVBoxLayout;
     l9->addLayout(searchLayout9);
     l9->addWidget(employeeStockSnackTable);
     l9->addLayout(addLayout9);
     QGroupBox * gBox9 = new QGroupBox;
     gBox9->setLayout(l9);


     //------------------- None-Food table ------------------

     QLineEdit * searchLe10 = new QLineEdit;
     searchLe10->setPlaceholderText(tr("Search by Name"));
     QPushButton * searchPush10 = new QPushButton("Search");
     searchPush10->setStyleSheet("color: red");
     QHBoxLayout * searchLayout10 = new QHBoxLayout;
     searchLayout10->addWidget(searchLe10);
     searchLayout10->addWidget(searchPush10);
     QPushButton * addToShopPush10 = new QPushButton("Add to Shop");
     QHBoxLayout * addLayout10 = new QHBoxLayout;
     addLayout10->addWidget(addToShopPush10);
     addLayout10->setAlignment(Qt::AlignLeft);
     connect(addToShopPush10,&QPushButton::clicked,this,[this]{employeeAddProductToShopSlt(employeeStockNoneFoodTable, employeeNoneFoodTable);});

     employeeStockNoneFoodTable = new QTableWidget;
     employeeStockNoneFoodTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
     employeeStockNoneFoodTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
     employeeStockNoneFoodTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
     employeeStockNoneFoodTable->setColumnCount(5);  // assign the number of columns in the table
     QStringList s10;
     s10 << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
     employeeStockNoneFoodTable->setHorizontalHeaderLabels(s10);

     QVBoxLayout *l10 = new QVBoxLayout;
     l10->addLayout(searchLayout10);
     l10->addWidget(employeeStockNoneFoodTable);
     l10->addLayout(addLayout10);
     QGroupBox * gBox10 = new QGroupBox;
     gBox10->setLayout(l10);


     //---------------- Category tab ---------------
     employeeStockCategoryTab = new QTabWidget;
     employeeStockCategoryTab->addTab(gBox6, "Vegatable and Fruit");
     employeeStockCategoryTab->addTab(gBox7,"Dairy");
     employeeStockCategoryTab->addTab(gBox8,"Beverage");
     employeeStockCategoryTab->addTab(gBox9,"Snack");
     employeeStockCategoryTab->addTab(gBox10, "None-Food");


     employeeStockAddProductToStock = new QPushButton("Add Product to Stock");
     //employeeStockAddProductToShop = new QPushButton("Add product to Shop");
     //employeeStockRemoveProductFromStock = new QPushButton("Remove Product");
     QHBoxLayout *h2 = new QHBoxLayout;
     h2->addWidget(employeeStockAddProductToStock);
     //h2->addWidget(employeeStockAddProductToShop);
     //h2->addWidget(employeeStockRemoveProductFromStock);
     h2->setAlignment(Qt::AlignLeft);
     QVBoxLayout *v2 = new QVBoxLayout;
     v2->addWidget(employeeStockCategoryTab);
     v2->addLayout(h2);

     QGroupBox *g2 = new QGroupBox;
     g2->setLayout(v2);


    //------------- Invoices ------------

    employeeInvoices = new QToolBox;

    //------------- Main tab ------------

    employeeMaintab = new QTabWidget;
    employeeMaintab->addTab(gg, "Shop Products");
    employeeMaintab->addTab(g2,"Stock");
    employeeMaintab->addTab(employeeInvoices, "Invoices");


    this->setCentralWidget(employeeMaintab);

}

void MainWindow::manager_window()
{
    set_manager_window_ui();
    connect(addEmp,&QPushButton::clicked, this, &MainWindow::managerAddEmployeedialog);
    connect(removeEmp,&QPushButton::clicked, this, &MainWindow::managerRemoveEmployeeDialog);
    connect(editSalary,&QPushButton::clicked, this, &MainWindow::managerEditSalaryDialog);
}

void MainWindow::set_manager_window_ui()
{


    //------------------------------------------------
    //----------------- Employees Tab ----------------
    //------------------------------------------------

    employeeTable = new QTableWidget;
    employeeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    employeeTable->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    employeeTable->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    employeeTable->setColumnCount(7);
    QStringList tablehead;
    tablehead << tr("First Name") << tr("Last Name") << tr("UserName") << tr("Age") << tr("Password") << tr("Employee ID") << tr("Salary");
    employeeTable->setHorizontalHeaderLabels(tablehead);
    display_employees(employeeTable);

    addEmp = new QPushButton("Add Employee");
    removeEmp = new QPushButton("Remove Employees");
    editSalary = new QPushButton("Edit Salaries");
    editPushbuttons = new QHBoxLayout;
    editPushbuttons->addWidget(addEmp);
    editPushbuttons->addWidget(removeEmp);
    editPushbuttons->addWidget(editSalary);
    editPushbuttons->setAlignment(Qt::AlignHCenter);

    employeeslayout = new QVBoxLayout;
    employeeslayout->addLayout(editPushbuttons);
    employeeslayout->addWidget(employeeTable);
    QGroupBox * empGroup = new QGroupBox;
    empGroup->setLayout(employeeslayout);


    this->setCentralWidget(empGroup);
}
void MainWindow::display_employees(QTableWidget *table)
{
    QFile employeesFile("database/employee.json");

    QJsonObject employeesObj;
    if (employeesFile.open(QIODevice::ReadOnly))
    {
        employeesObj = (QJsonDocument::fromJson( employeesFile.readAll() )).object();
        employeesFile.close();
    }

    int counter=0;

    foreach (QJsonValue x, employeesObj["Employees"].toArray())
    {
        if(x["age"] != 1)
            counter++;
    }
    table->setRowCount(counter);
    counter = 0;
    foreach (QJsonValue x, employeesObj["Employees"].toArray())
    {
        table->setItem(counter, 0, new QTableWidgetItem(x["first name"].toString()));
        table->setItem(counter, 1, new QTableWidgetItem(x["last name"].toString()));
        table->setItem(counter, 2, new QTableWidgetItem(x["user name"].toString()));
        table->setItem(counter, 3, new QTableWidgetItem(QString::number(x["age"].toInt())));
        table->setItem(counter, 4, new QTableWidgetItem(x["password"].toString()));
        table->setItem(counter, 5, new QTableWidgetItem(QString::number(x["ID number"].toInt())));
        table->setItem(counter, 6, new QTableWidgetItem(QString::number(x["salary"].toInt())));

        counter++;
    }
}


void MainWindow::employee_add_product_to_stock()
{
    QFile f("database/stockproducts.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    foreach (QJsonValue x, o["Products"].toArray())
    {
        if(x["Category"].toString() == "Vegetable and Fruit")
            display_stock_product(employeeStockVandFTable, "Vegetable and Fruit");
        else if(x["Category"].toString() == "Dairy")
            display_stock_product(employeeStockDairyTable, "Dairy");
        else if(x["Category"].toString() == "Beverage")
            display_stock_product(employeeStockBeverageTable, "Beverage");
        else if(x["Category"].toString() == "Snack")
            display_stock_product(employeeStockSnackTable, "Snack");
        else if(x["Category"].toString() == "None-Food")
            display_stock_product(employeeStockNoneFoodTable, "None-Food");
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

void MainWindow::display_stock_product(QTableWidget * table, QString category)
{
    QFile f("database/stockproducts.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    int counter=0;

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
            table->setItem(counter, 4, new QTableWidgetItem(QString::number(x["Amount"].toInt())));
            counter++;
        }
    }
}

void MainWindow::customer_increase_credit(int a)
{
    //------------writing in file-------------
    QFile f("database/customers.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    QJsonObject other = o[this->username].toObject();
    QJsonObject j =  { {"first name", other["first name"].toString()},
                       {"last name", other["last name"].toString()},
                       {"user name", other["user name"].toString()},
                       {"password", other["password"].toString()},
                       {"customer ID", other["customer ID"].toInt()},
                       {"age", other["age"].toInt()},
                       {"address", other["address"].toString()},
                       {"phone number", other["phone number"].toString()},
                       {"wallet", a + other["wallet"].toInt()}};

    QJsonObject  tmp = o;
    tmp[this->username] = j;

    QJsonDocument u(tmp);
    QFile w("database/customers.json");
    w.open(QIODevice::WriteOnly);
    w.write(u.toJson());

    this->customerCredit->setValue(j["wallet"].toInt());

    if (a>0)
        display_info("your credit successfully increased.");

    return;
}

void MainWindow::add_purchase_to_history(int payment, int discount, int payout)
{
    QJsonObject purchaseJson;
    purchaseJson["payment"] = payment;
    purchaseJson["discount"] = discount;
    purchaseJson["payout"] = payout;
    QJsonArray productsArray;

    QTableWidget * purchase = new QTableWidget;
    purchase->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    purchase->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    purchase->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    purchase->setColumnCount(6);  // assign the number of columns in the table
    QStringList s6;
    s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
    purchase->setHorizontalHeaderLabels(s6);

    purchase->setRowCount(customerCartTable->rowCount());
    for (int i=0; i<customerCartTable->rowCount(); i++)
    {
        QJsonObject productJson;
        purchase->setItem(i,0, new QTableWidgetItem(customerCartTable->item(i,0)->text()));
        productJson["name"] = customerCartTable->item(i,0)->text();
        purchase->setItem(i,1, new QTableWidgetItem(customerCartTable->item(i,1)->text()));
        productJson["category"] = customerCartTable->item(i,1)->text();
        purchase->setItem(i,2, new QTableWidgetItem(customerCartTable->item(i,2)->text()));
        productJson["manufacturer"] = customerCartTable->item(i,2)->text();
        purchase->setItem(i,3, new QTableWidgetItem(customerCartTable->item(i,3)->text()));
        productJson["price"] = customerCartTable->item(i,3)->text().toInt();
        purchase->setItem(i,4, new QTableWidgetItem(customerCartTable->item(i,4)->text()));
        productJson["expiry date"] = customerCartTable->item(i,4)->text();
        purchase->setItem(i,5, new QTableWidgetItem(customerCartTable->item(i,5)->text()));
        productJson["amount"] = customerCartTable->item(i,5)->text().toInt();
        productsArray.append(productJson);
    }

    purchaseJson["products"] = productsArray;

    //-----------writing in file--------
    QString path = "database/customers/" + this->username +".json";

    QFile f(path);
    f.open(QIODevice::ReadOnly);
    if(f.isOpen())
    {
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray p = o["purchases"].toArray();
        QJsonArray invoices = p;
        invoices.append(purchaseJson);
        QJsonObject v;
        v["purchases"] = invoices;
        QJsonDocument u(v);
        QFile w(path);
        w.open(QIODevice::WriteOnly);
        w.write(u.toJson());
        w.close();
    }
    else
    {
        QFile z(path);
        z.open(QIODevice::WriteOnly);

        QJsonObject j;
        QJsonArray purchaseArray;
        purchaseArray.append(purchaseJson);
        j["purchases"] = purchaseArray;

        QJsonDocument d(j);
        z.write(d.toJson());
        z.close();
    }
    //-----------------------------------

    QLabel * paymentLabel = new QLabel("Payment: ");
    QSpinBox * paymentSpin = new QSpinBox;
    paymentSpin->setReadOnly(true);
    paymentSpin->setStyleSheet("font-size: 15px;");
    paymentSpin->setMaximum(10000000);
    paymentSpin->setValue(payment);
    QHBoxLayout * paymentLayout = new QHBoxLayout;
    paymentLayout->addWidget(paymentLabel);
    paymentLayout->addWidget(paymentSpin);
    paymentLayout->setAlignment(Qt::AlignLeft);

    QLabel * discountLabel = new QLabel("Discount: ");
    QSpinBox * discountSpin = new QSpinBox;
    discountSpin->setReadOnly(true);
    discountSpin->setStyleSheet("font-size: 15px;");
    discountSpin->setMaximum(10000000);
    discountSpin->setValue(discount);
    QHBoxLayout * discountLayout = new QHBoxLayout;
    discountLayout->addWidget(discountLabel);
    discountLayout->addWidget(discountSpin);
    discountLayout->setAlignment(Qt::AlignLeft);

    QLabel * payoutLabel = new QLabel("Payout: ");
    QSpinBox * payoutSpin = new QSpinBox;
    payoutSpin->setReadOnly(true);
    payoutSpin->setStyleSheet("font-size: 15px;");
    payoutSpin->setMaximum(10000000);
    payoutSpin->setValue(payout);
    QHBoxLayout * payoutLayout = new QHBoxLayout;
    payoutLayout->addWidget(payoutLabel);
    payoutLayout->addWidget(payoutSpin);
    payoutLayout->setAlignment(Qt::AlignLeft);

    QVBoxLayout * l = new QVBoxLayout;
    l->addWidget(purchase);
    l->addLayout(paymentLayout);
    l->addLayout(discountLayout);
    l->addLayout(payoutLayout);
    QGroupBox * g = new QGroupBox;
    g->setLayout(l);
    customerShopHistoryToolBox->insertItem(customerShopHistoryToolBox->count(),g, "Purchase " + QString::number(customerShopHistoryToolBox->count()+1));

    customerCartTable->clear();
    customerCartTable->setRowCount(0);
    QStringList s;
    s << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
    customerCartTable->setHorizontalHeaderLabels(s);
}

void MainWindow::employee_load_invoices()
{
    QFile f("database/invoices.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    int counter=0;

    foreach (QJsonValue x, o["Invoices"].toArray())
    {
        QLabel * nameLabel = new QLabel("Customer Name: ");
        QLineEdit * nameLe = new QLineEdit(x["Customer Name"].toString());
        nameLe->setReadOnly(true);
        nameLe->setStyleSheet("font-size: 15px;");
        QHBoxLayout * nameLayout = new QHBoxLayout;
        nameLayout->addWidget(nameLabel);
        nameLayout->addWidget(nameLe);
        nameLayout->setAlignment(Qt::AlignLeft);

        QLabel * idLabel = new QLabel("Customer ID: ");
        QLineEdit * idLe = new QLineEdit(QString::number(x["Customer ID"].toInt()));
        idLe->setReadOnly(true);
        idLe->setStyleSheet("font-size: 15px;");
        QHBoxLayout * idLayout = new QHBoxLayout;
        idLayout->addWidget(idLabel);
        idLayout->addWidget(idLe);
        idLayout->setAlignment(Qt::AlignLeft);

        QLabel * paymentLabel = new QLabel("Payment: ");
        QSpinBox * paymentSpin = new QSpinBox;
        paymentSpin->setReadOnly(true);
        paymentSpin->setStyleSheet("font-size: 15px;");
        paymentSpin->setMaximum(10000000);
        paymentSpin->setValue(x["Payment"].toInt());
        QHBoxLayout * paymentLayout = new QHBoxLayout;
        paymentLayout->addWidget(paymentLabel);
        paymentLayout->addWidget(paymentSpin);
        paymentLayout->setAlignment(Qt::AlignLeft);

        QLabel * discountLabel = new QLabel("Discount: ");
        QSpinBox * discountSpin = new QSpinBox;
        discountSpin->setReadOnly(true);
        discountSpin->setStyleSheet("font-size: 15px;");
        discountSpin->setMaximum(10000000);
        discountSpin->setValue(x["Discount"].toInt());
        QHBoxLayout * discountLayout = new QHBoxLayout;
        discountLayout->addWidget(discountLabel);
        discountLayout->addWidget(discountSpin);
        discountLayout->setAlignment(Qt::AlignLeft);

        QLabel * payoutLabel = new QLabel("Payout: ");
        QSpinBox * payoutSpin = new QSpinBox;
        payoutSpin->setReadOnly(true);
        payoutSpin->setStyleSheet("font-size: 15px;");
        payoutSpin->setMaximum(10000000);
        payoutSpin->setValue(x["Payout"].toInt());
        QHBoxLayout * payoutLayout = new QHBoxLayout;
        payoutLayout->addWidget(payoutLabel);
        payoutLayout->addWidget(payoutSpin);
        payoutLayout->setAlignment(Qt::AlignLeft);


        QTableWidget * product = new QTableWidget;
        product->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
        product->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
        product->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
        product->setColumnCount(5);  // assign the number of columns in the table
        QStringList s6;
        s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
        product->setHorizontalHeaderLabels(s6);

        foreach (QJsonValue y, x["Products"].toArray())
        {
            product->insertRow(product->rowCount());
            product->setItem(product->rowCount()-1,0, new QTableWidgetItem(y["Name"].toString()));
            product->setItem(product->rowCount()-1,1, new QTableWidgetItem(y["Category"].toString()));
            product->setItem(product->rowCount()-1,2, new QTableWidgetItem(y["Manufacturer"].toString()));
            product->setItem(product->rowCount()-1,3, new QTableWidgetItem(QString::number(y["Price"].toInt())));
            product->setItem(product->rowCount()-1,4, new QTableWidgetItem(y["Expiry date"].toString()));
        }

        QVBoxLayout * l = new QVBoxLayout;
        l->addLayout(nameLayout);
        l->addLayout(idLayout);
        l->addWidget(product);
        l->addLayout(paymentLayout);
        l->addLayout(discountLayout);
        l->addLayout(payoutLayout);
        QGroupBox * g = new QGroupBox;
        g->setLayout(l);

        employeeInvoices->insertItem(employeeInvoices->count(), g, "Invoice " + QString::number(employeeInvoices->count()+1));

        counter++;
    }
}

void MainWindow::customer_load_purchases()
{
    QString path = "database/customers/" + this->username + ".json";
    QFile f(path);
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();

    foreach (QJsonValue x, o["purchases"].toArray())
    {
        QLabel * paymentLabel = new QLabel("Payment: ");
        QSpinBox * paymentSpin = new QSpinBox;
        paymentSpin->setReadOnly(true);
        paymentSpin->setStyleSheet("font-size: 15px;");
        paymentSpin->setMaximum(10000000);
        paymentSpin->setValue(x["payment"].toInt());
        QHBoxLayout * paymentLayout = new QHBoxLayout;
        paymentLayout->addWidget(paymentLabel);
        paymentLayout->addWidget(paymentSpin);
        paymentLayout->setAlignment(Qt::AlignLeft);

        QLabel * discountLabel = new QLabel("Discount: ");
        QSpinBox * discountSpin = new QSpinBox;
        discountSpin->setReadOnly(true);
        discountSpin->setStyleSheet("font-size: 15px;");
        discountSpin->setMaximum(10000000);
        discountSpin->setValue(x["discount"].toInt());
        QHBoxLayout * discountLayout = new QHBoxLayout;
        discountLayout->addWidget(discountLabel);
        discountLayout->addWidget(discountSpin);
        discountLayout->setAlignment(Qt::AlignLeft);

        QLabel * payoutLabel = new QLabel("Payout: ");
        QSpinBox * payoutSpin = new QSpinBox;
        payoutSpin->setReadOnly(true);
        payoutSpin->setStyleSheet("font-size: 15px;");
        payoutSpin->setMaximum(10000000);
        payoutSpin->setValue(x["payout"].toInt());
        QHBoxLayout * payoutLayout = new QHBoxLayout;
        payoutLayout->addWidget(payoutLabel);
        payoutLayout->addWidget(payoutSpin);
        payoutLayout->setAlignment(Qt::AlignLeft);


        QTableWidget * purchase = new QTableWidget;
        purchase->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
        purchase->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
        purchase->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
        purchase->setColumnCount(6);  // assign the number of columns in the table
        QStringList s6;
        s6 << tr("Name") << tr("Category") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") << tr("Amount");
        purchase->setHorizontalHeaderLabels(s6);

        foreach (QJsonValue y, x["products"].toArray())
        {
            purchase->insertRow(purchase->rowCount());
            purchase->setItem(purchase->rowCount()-1,0, new QTableWidgetItem(y["name"].toString()));
            purchase->setItem(purchase->rowCount()-1,1, new QTableWidgetItem(y["category"].toString()));
            purchase->setItem(purchase->rowCount()-1,2, new QTableWidgetItem(y["manufacturer"].toString()));
            purchase->setItem(purchase->rowCount()-1,3, new QTableWidgetItem(QString::number(y["price"].toInt())));
            purchase->setItem(purchase->rowCount()-1,4, new QTableWidgetItem(y["expiry date"].toString()));
            purchase->setItem(purchase->rowCount()-1,5, new QTableWidgetItem(QString::number(y["amount"].toInt())));
        }

        QVBoxLayout * l = new QVBoxLayout;
        l->addWidget(purchase);
        l->addLayout(paymentLayout);
        l->addLayout(discountLayout);
        l->addLayout(payoutLayout);
        QGroupBox * g = new QGroupBox;
        g->setLayout(l);
        customerShopHistoryToolBox->insertItem(customerShopHistoryToolBox->count(),g, "Purchase " + QString::number(customerShopHistoryToolBox->count()+1));
    }
}

void MainWindow::customer_add_to_cart(QString name, QString category, QString manu, QString price, QString exp_date, QString amount)
{
    customerCartTable->insertRow(customerCartTable->rowCount());
    customerCartTable->setItem(customerCartTable->rowCount()-1,0, new QTableWidgetItem(name));
    customerCartTable->setItem(customerCartTable->rowCount()-1,1, new QTableWidgetItem(category));
    customerCartTable->setItem(customerCartTable->rowCount()-1,2, new QTableWidgetItem(manu));
    customerCartTable->setItem(customerCartTable->rowCount()-1,3, new QTableWidgetItem(price));
    customerCartTable->setItem(customerCartTable->rowCount()-1,4, new QTableWidgetItem(exp_date));
    customerCartTable->setItem(customerCartTable->rowCount()-1,5, new QTableWidgetItem(amount));

    display_shop_product(customerVandFTable, "Vegetable and Fruit");
    display_shop_product(customerDairyTable, "Dairy");
    display_shop_product(customerBeverageTable, "Beverage");
    display_shop_product(customerSnackTable, "Snack");
    display_shop_product(customerNoneFoodTable, "None-Food");

    display_info("product seccessfully added to cart.");
}

void MainWindow::set_username(QString u)
{
    this->username = u;
    return;
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

void MainWindow::employeeAddProductToStockDialog()
{
    employee_add_product_dialog *dialog = new employee_add_product_dialog(this);
    dialog->show();
}

void MainWindow::employeeAddProductToShopSlt(QTableWidget* sourceTable, QTableWidget* destTable)
{
    QString category;
    if (sourceTable == employeeStockVandFTable)
        category = "Vegetable and Fruit";
    else if (sourceTable == employeeStockDairyTable)
        category = "Dairy";
    else if (sourceTable == employeeStockBeverageTable)
        category = "Beverage";
    else if (sourceTable == employeeStockSnackTable)
        category = "Snack";
    else if (sourceTable == employeeStockNoneFoodTable)
        category = "None-Food";

    QItemSelectionModel  *s = sourceTable->selectionModel();
    QModelIndexList  selectedRows = s->selectedRows();


    if (selectedRows.size() > 0)
    {
        //---------- checking product exits in shop ---------------
        int row = selectedRows.first().row();
        QFile check("database/shopproducts.json");
        check.open(QIODevice::ReadOnly);
        if(check.isOpen())
        {
            QByteArray bb = check.readAll();
            QJsonDocument dd = QJsonDocument::fromJson(bb);
            QJsonObject oo = dd.object();
            QJsonArray pp = oo["Products"].toArray();

            foreach (QJsonValue x, pp)
            {
                if(x["Name"].toString() == sourceTable->item(row,0)->text() && x["Manufacturer"].toString() == sourceTable->item(row,1)->text())
                {
                    this->display_error("this product already exist in shop!");
                    sourceTable->clearSelection();
                    return;
                }
            }
        }
        check.close();
        if(sourceTable->item(row,4)->text().toInt() == 0)
        {
            display_error("this product dosen't exist in stock!");
            return;
        }
//        sourceTable->setItem(row,4, new QTableWidgetItem(QString::number(sourceTable->item(row,4)->text().toInt()-1)));
//        //-------------- decreas amount of product in stock------------------
//        QFile f3("database/stockproducts.json");
//        f3.open(QIODevice::ReadOnly);
//        QByteArray b3 = f3.readAll();
//        QJsonDocument d3 = QJsonDocument::fromJson(b3);
//        QJsonObject o3 = d3.object();
//        QJsonArray p3 = o3["Products"].toArray();
//        QJsonArray result;

//        foreach(QJsonValue x, p3)
//        {
//            if(x["Name"].toString() == sourceTable->item(row,0)->text() && x["Manufacturer"].toString() == sourceTable->item(row,1)->text())
//            {
//                int i = x["Amount"].toInt();
//                i -= 1;
//                QJsonObject j;
//                j["Name"] = x["Name"].toString();
//                j["Category"] = x["Category"].toString();
//                j["Manufacturer"] = x["Manufacturer"].toString();
//                j["Price"] = x["Price"].toInt();
//                j["Expiry date"] = x["Expiry date"].toString();
//                j["Amount"] = i;
//                result.append(j);
//            }
//            else
//            {
//                result.append(x.toObject());
//            }
//        }
//        QJsonObject v3;
//        v3["Products"] = result;
//        QJsonDocument u3(v3);
//        QFile w3("database/stockproducts.json");
//        w3.open(QIODevice::WriteOnly);
//        w3.write(u3.toJson());


        destTable->insertRow(destTable->rowCount());
        destTable->setItem(destTable->rowCount()-1, 0, new QTableWidgetItem(sourceTable->item(row,0)->text()));
        destTable->setItem(destTable->rowCount()-1, 1, new QTableWidgetItem(sourceTable->item(row,1)->text()));
        destTable->setItem(destTable->rowCount()-1, 2, new QTableWidgetItem(sourceTable->item(row,2)->text()));
        destTable->setItem(destTable->rowCount()-1, 3, new QTableWidgetItem(sourceTable->item(row,3)->text()));
        sourceTable->clearSelection();

        display_info("product succefully added to shop.");

        //---------- writing to shop products file------------------

        QJsonObject r;
        r["Name"] = sourceTable->item(row,0)->text();
        r["Category"] = category;
        r["Manufacturer"] = sourceTable->item(row,1)->text();
        r["Price"] = sourceTable->item(row,2)->text().toInt();
        r["Expiry date"] = sourceTable->item(row,3)->text();

        QFile f("database/shopproducts.json");
        f.open(QIODevice::ReadOnly);
        if(f.isOpen())
        {
            QByteArray b = f.readAll();
            QJsonDocument d = QJsonDocument::fromJson(b);
            QJsonObject o = d.object();
            QJsonArray p = o["Products"].toArray();

            QJsonArray product = p;
            product.append(r);
            QJsonObject v;
            v["Products"] = product;
            QJsonDocument u(v);
            QFile w("database/shopproducts.json");
            w.open(QIODevice::WriteOnly);
            w.write(u.toJson());

        }
        else
        {
            QFile z("database/shopproducts.json");
            z.open(QIODevice::WriteOnly);

            QJsonObject j;
            QJsonArray products;
            products.append(r);
            j["Products"] = products;

            QJsonDocument d(j);
            z.write(d.toJson());
        }
    }
    else
    {
        display_info("Please select a product.");
    }

}

void MainWindow::employeeRemoveProductFromStockSlt()
{

}

void MainWindow::employeeRemoveProductFromShopSlt(QTableWidget* sourceTabel)
{

    QItemSelectionModel  *s = sourceTabel->selectionModel();
    QModelIndexList  selectedRows = s->selectedRows();
    if (selectedRows.size() > 0)
    {
        QString name = sourceTabel->item(selectedRows.first().row(),0)->text();
        QString manu =  sourceTabel->item(selectedRows.first().row(),1)->text();
        sourceTabel->removeRow(selectedRows.first().row());
        //------------remove from file------------

        QFile f("database/shopproducts.json");
        f.open(QIODevice::ReadOnly);
        if(f.isOpen())
        {
            QByteArray b = f.readAll();
            QJsonDocument d = QJsonDocument::fromJson(b);
            QJsonObject o = d.object();
            QJsonArray p = o["Products"].toArray();
            QJsonArray result;

            foreach(QJsonValue x, p)
            {
                if(x["Name"].toString() != name && x["Manufacturer"].toString() != manu)
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

        display_info("product succefully removed.");
    }
    else
    {
        this->display_info("Please select a product!");
    }
    sourceTabel->clearSelection();
    return;
}

void MainWindow::customerAddToCartDialog(QTableWidget* sourceTable)
{


    QString category;
    if (sourceTable == customerVandFTable)
        category = "Vegetable and Fruit";
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
        QString name = sourceTable->item(selectedRows.first().row(),0)->text();
        QString manu = sourceTable->item(selectedRows.first().row(),1)->text();
        QString price = sourceTable->item(selectedRows.first().row(),2)->text();
        QString exp_date = sourceTable->item(selectedRows.first().row(),3)->text();

        addtocart_dialog *dialog = new addtocart_dialog(name,category, manu, price, exp_date, this);
        dialog->show();

//        int row = selectedRows.first().row();
//        QString name = sourceTable->item(row, 0)->text();
//        QString manufacturer = sourceTable->item(row, 1)->text();
//        QString price = sourceTable->item(row, 2)->text();
//        QString expDate = sourceTable->item(row, 3)->text();
//        customerCartTable->insertRow(customerCartTable->rowCount());
//        customerCartTable->setItem(customerCartTable->rowCount()-1,0, new QTableWidgetItem(name));
//        customerCartTable->setItem(customerCartTable->rowCount()-1,1, new QTableWidgetItem(category));
//        customerCartTable->setItem(customerCartTable->rowCount()-1,2, new QTableWidgetItem(manufacturer));
//        customerCartTable->setItem(customerCartTable->rowCount()-1,3, new QTableWidgetItem(price));
//        customerCartTable->setItem(customerCartTable->rowCount()-1,4, new QTableWidgetItem(expDate));
        sourceTable->clearSelection();
//        display_info("product succefully added to cart.");
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
        QFile f("database/customers.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonObject j = o[this->username].toObject();

        QString name = j["first name"].toString() + " " + j["last name"].toString();

        customer_invoice * invoic = new customer_invoice(this, name, QString::number(j["customer ID"].toInt()), customerCartTable, customerCredit->value());
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
        int row = selectedRows.first().row();


        //-------------- add product to stock, file ----------------
        QFile f("database/stockproducts.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray p = o["Products"].toArray();
        QJsonArray result;
        int flag =0;

        foreach (QJsonValue x, p)
        {
            if (x["Name"].toString() == customerCartTable->item(row,0)->text() && x["Manufacturer"].toString() == customerCartTable->item(row,2)->text())
            {
                flag = 1;
                QJsonObject j;
                j["Name"] = x["Name"].toString();
                j["Category"] = x["Category"].toString();
                j["Manufacturer"] = x["Manufacturer"].toString();
                j["Piece"] = x["Price"].toInt();
                j["Expiry date"] = x["Expiry date"].toString();
                int i = x["Amount"].toInt();
                j["Amount"] = i + customerCartTable->item(row,5)->text().toInt();
                result.append(j);
            }
            else
            {
                result.append(x.toObject());
            }
        }

        if (flag == 0)
        {
            QJsonObject r;
            r["Name"] = customerCartTable->item(row,0)->text();
            r["Category"] = customerCartTable->item(row,1)->text();
            r["Manufacturer"] = customerCartTable->item(row,2)->text();
            r["Price"] = customerCartTable->item(row,3)->text().toInt();
            r["Expiry date"] = customerCartTable->item(row,4)->text();
            r["Amount"] = customerCartTable->item(row,5)->text().toInt();
            result.append(r);
        }


        QJsonObject v;
        v["Products"] = result;
        QJsonDocument u(v);
        QFile w("database/stockproducts.json");
        w.open(QIODevice::WriteOnly);
        w.write(u.toJson());
        //-------------------------------------------------------

        customerCartTable->removeRow(row);
        display_info("product succefully removed from cart.");
    }
    else
    {
        this->display_info("Please select a product!");
    }
    customerCartTable->clearSelection();
    return;
}

void MainWindow::increaseCreditDialog()
{
    increase_credit_dialog * dialog = new increase_credit_dialog(this);
    dialog->show();
}

void MainWindow::managerAddEmployeedialog()
{
    managerAddEmployeeDialog * dialog = new managerAddEmployeeDialog(this);
    dialog->show();
}

void MainWindow::managerRemoveEmployeeDialog()
{
    manager_remove_employee_dialog * dialog = new manager_remove_employee_dialog(this);
    dialog->show();
}

void MainWindow::managerEditSalaryDialog()
{
    manager_edit_salary_dialog * dialog = new manager_edit_salary_dialog(this);
    dialog->show();
}

