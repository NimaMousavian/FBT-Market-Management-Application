#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"
#include <bits/stdc++.h>
#include <iostream>
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mkdir("database");

    connect(this, SIGNAL(throw_error), this,SLOT(display_error));

    this->setWindowTitle("Hyper Market Manager System");
    this->setCentralWidget(new Home(this));
    this->setWindowIcon(QIcon("E:\\C++_T2\\FBT_Gui\\icons\\store.png"));


    QPixmap bkgnd("E:/FBT_project/f.b.t/images/image2.jpg");
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

