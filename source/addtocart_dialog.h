#ifndef ADDTOCART_DIALOG_H
#define ADDTOCART_DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class addtocart_dialog;
}

class addtocart_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addtocart_dialog(QString, QString, QString, QString, MainWindow* mw, QWidget *parent = nullptr);
    ~addtocart_dialog();

private slots:
    void on_addButton_clicked();

    void on_discardBotton_clicked();

private:
    Ui::addtocart_dialog *ui;

    MainWindow * mainwindow;
};

#endif // ADDTOCART_DIALOG_H
