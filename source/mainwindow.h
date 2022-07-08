#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTableWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolBox>
#include <QSpinBox>
#include "product.h"
#include <QJsonObject>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void customer_window();
    void set_customer_window_ui();

    void employee_window();
    void set_employee_window_ui();

    void employee_add_product();
    void display_shop_product(QTableWidget*, QString);

    void set_customer_credit(int);
    void add_purchase_to_history(int payment, int discount, int payout);

    void employee_load_invoices();
    void customer_load_purchases();

    void set_username(QString);
private:
    Ui::MainWindow *ui;

    QString username;

    //-------------- Customer window widgets ------------
    QTabWidget * customerMaintab;
    QTabWidget * customerCategoryTab;
    QTableWidget * customerVandFTable;
    QTableWidget * customerDairyTable;
    QTableWidget * customerBeverageTable;
    QTableWidget * customerSnackTable;
    QTableWidget * customerNoneFoodTable;
    QTableWidget * customerCartTable;
    QToolBox * customerShopHistoryToolBox;
    QSpinBox * customerCredit;

    //-------------- Employee window widgets ---------------
    QTabWidget * employeeMaintab;
    QTabWidget * employeeCategoryTab;
    QTableWidget * employeeVandFTable;
    QTableWidget * employeeDairyTable;
    QTableWidget * employeeBeverageTable;
    QTableWidget * employeeSnackTable;
    QTableWidget * employeeNoneFoodTable;
    QPushButton * employeeAddProduct;
    QToolBox * employeeInvoices;


signals:
    void throw_error(QString);
    void throw_info(QString);
public slots:
    void display_error(QString);
    void display_info(QString);
    void employeeAddProductdialog();
    void customerAddToCart(QTableWidget*);
    void customerPurchase();
    void removeFromCart();
    void increase_credit();
};
#endif // MAINWINDOW_H
