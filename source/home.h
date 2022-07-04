#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

private:
    MainWindow * mainWindow;
public:
    explicit Home(MainWindow*, QWidget *parent = nullptr);
    ~Home();


private slots:

    void on_login_push_clicked();

    void on_exit_push_clicked();

    void on_sign_up_push_clicked();

    void on_about_push_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
