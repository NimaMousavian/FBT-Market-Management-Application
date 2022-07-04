#ifndef EMPLOYEE_SIGNUP_H
#define EMPLOYEE_SIGNUP_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class Employee_signup;
}

class Employee_signup : public QWidget
{
    Q_OBJECT

public:
    explicit Employee_signup(MainWindow *mainwindow,QWidget *parent = nullptr);
    ~Employee_signup();

private slots:
    void on_comboBox_2_currentIndexChanged(int index);

    void on_back_push_clicked();

    void on_sign_push_clicked();

private:
    Ui::Employee_signup *ui;
    MainWindow * mainwindow;
};

#endif // EMPLOYEE_SIGNUP_H
