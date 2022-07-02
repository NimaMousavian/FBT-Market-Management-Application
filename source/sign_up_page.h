#ifndef SIGN_UP_PAGE_H
#define SIGN_UP_PAGE_H

#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Sign_up_page;
}

class Sign_up_page : public QWidget
{
    Q_OBJECT

public:
    explicit Sign_up_page(MainWindow *,QWidget *parent = nullptr);
    ~Sign_up_page();

private slots:
    void on_sign_push_clicked();

    void on_back_push_clicked();

private:
    Ui::Sign_up_page *ui;
    MainWindow *mainwindow;
};

#endif // SIGN_UP_PAGE_H
