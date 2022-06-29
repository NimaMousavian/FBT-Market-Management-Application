#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

private:
    QMainWindow * mainWindow;
public:
    explicit Home(QMainWindow*, QWidget *parent = nullptr);
    ~Home();

    void set_mainwindow(QMainWindow*);

private slots:

    void on_login_push_clicked();

    void on_exit_push_clicked();

    void on_sign_up_push_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
