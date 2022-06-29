#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hyper Market Manager System");
    this->setCentralWidget(new Home(this));
    this->setWindowIcon(QIcon("E:\\C++_T2\\FBT_Gui\\icons\\store.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

