#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"
#include <QMessageBox>
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::display_error(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Critical, "Error", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon("E:/FBT_project/f.b.t/icons/ok.png"));
    box->show();
    connect(box,&QMessageBox::buttonClicked,box,&QMessageBox::deleteLater, Qt::QueuedConnection);
    return;
}

void MainWindow::display_info(QString msg)
{
    QMessageBox * box = new QMessageBox(QMessageBox::Information, "Error", msg, QMessageBox::Ok);
    box->button(QMessageBox::Ok)->setIcon(QIcon("E:/FBT_project/f.b.t/icons/ok.png"));
    box->show();
    connect(box,&QMessageBox::buttonClicked,box,&QMessageBox::deleteLater, Qt::QueuedConnection);
    return;
}

