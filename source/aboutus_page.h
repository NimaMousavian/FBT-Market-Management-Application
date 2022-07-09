#ifndef ABOUTUS_PAGE_H
#define ABOUTUS_PAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <string>
#include "mainwindow.h"


namespace Ui {
class aboutUs_page;
}

class aboutUs_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboutUs_page(MainWindow *,QWidget *parent = nullptr);
    ~aboutUs_page();

private slots:
    void on_backBotton_clicked();

private:
    Ui::aboutUs_page *ui;
    MainWindow *mainwindow;
};

#endif // ABOUTUS_PAGE_H
