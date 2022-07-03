#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"
#include <QMessageBox>
#include <QAbstractButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    QLineEdit * search_le = new QLineEdit;
    search_le->setPlaceholderText(tr("Search by Name"));



    QTableWidget * table = new QTableWidget;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);  // disable in-place editing
    table->setSelectionBehavior(QAbstractItemView::SelectRows);  // only rows can be selected, not columns or sells
    table->setSelectionMode(QAbstractItemView::SingleSelection);  // disable selection of multiple rows
    table->setColumnCount(4);  // assign the number of columns in the table
    QStringList s;
    s << tr("Name") << tr("Manufacturer") << tr("Price") << tr("Expiry Date") ;
    table->setHorizontalHeaderLabels(s);

    QVBoxLayout *l = new QVBoxLayout;
    l->addWidget(search_le);
    l->addWidget(table);
    QGroupBox * gBox = new QGroupBox;
    gBox->setLayout(l);

    QTableWidget * table2 = new QTableWidget;
    QTableWidget * table3 = new QTableWidget;
    QTableWidget * table4 = new QTableWidget;
    QTableWidget * table5 = new QTableWidget;

    QGroupBox * gBox2 = new QGroupBox;
    QVBoxLayout *l2 = new QVBoxLayout;
    l2->addWidget(search_le);
    l2->addWidget(table2);
    gBox2->setLayout(l2);

    QTabWidget *category = new QTabWidget;
    category->addTab(gBox, "Vegatable and Fruit");
    category->addTab(gBox2,"Dairy");
    category->addTab(table3,"Beverage");
    category->addTab(table4,"Snack");
    category->addTab(table5, "None-Food");

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->setIconSize(QSize(24, 24));
    tabWidget->addTab(category, QIcon("E:/FBT_project/f.b.t/icons/cash_register.png"), tr("Shop"));
//    tabWidget->addTab(,"Cart");
//    tabWidget->addTab(,"shop History");
//    tabWidget->addTab(, "Wallet");



    this->setCentralWidget(tabWidget);
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

