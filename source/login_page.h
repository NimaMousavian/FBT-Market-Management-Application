#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QWidget>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <string>
#include "mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class Login_page;
}

class Login_page : public QWidget
{
    Q_OBJECT

public:
    explicit Login_page(MainWindow *,QWidget *parent = nullptr);
    ~Login_page();

private slots:
    void on_back_push_clicked();

    void on_login_push_clicked();

<<<<<<< HEAD
    void on_comboBox_currentIndexChanged(int index);

=======
>>>>>>> 33e84d1c574e221dfda4ed7a89ff1a0f54971905
private:
    Ui::Login_page *ui;
    MainWindow *mainwindow;
};

#endif // LOGIN_PAGE_H
