#ifndef CHANGEPASS_DIALOG_H
#define CHANGEPASS_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "mainwindow.h"

namespace Ui {
class changePass_dialog;
}

class changePass_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit changePass_dialog(MainWindow *, int index, QWidget *parent = nullptr);
    ~changePass_dialog();

private slots:

    void on_changeButton_clicked();

    void on_cancleBotton_clicked();

private:
    Ui::changePass_dialog *ui;
    MainWindow * mainwindow;
    int role;
};

#endif // CHANGEPASS_DIALOG_H
