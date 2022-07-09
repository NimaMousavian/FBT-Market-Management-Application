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
#include "Manager.h"


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

    void employee_add_product_to_stock();
    void display_shop_product(QTableWidget*, QString);
    void display_stock_product(QTableWidget*, QString);


    void manager_window();
    void set_manager_window_ui();

    void display_employees(QTableWidget *);

    void customer_increase_credit(int a =0);
    void add_purchase_to_history(int payment, int discount, int payout);

    void employee_load_invoices();
    void customer_load_purchases();

    void customer_add_to_cart(QString, QString, QString, QString, QString, QString);

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
    QHBoxLayout * hh;
    QSpinBox * customerCredit;

    //-------------- Employee window widgets ---------------
    QTabWidget * employeeMaintab;
    QTabWidget * employeeCategoryTab;
    QTableWidget * employeeVandFTable;
    QTableWidget * employeeDairyTable;
    QTableWidget * employeeBeverageTable;
    QTableWidget * employeeSnackTable;
    QTableWidget * employeeNoneFoodTable;
    QTabWidget * employeeStockCategoryTab;
    QTableWidget * employeeStockVandFTable;
    QTableWidget * employeeStockDairyTable;
    QTableWidget * employeeStockBeverageTable;
    QTableWidget * employeeStockSnackTable;
    QTableWidget * employeeStockNoneFoodTable;
    QPushButton * employeeStockAddProductToStock;
    QPushButton * employeeStockAddProductToShop;
    QPushButton * employeeStockRemoveProductFromStock;
    QToolBox * employeeInvoices;

    //------------- Manager window widgets -----------------
    QTabWidget * managerTab;
    QTabWidget * shopTab;
    QTableWidget * employeeTable;
    QTableWidget * manageshop;
    QTableWidget * managestock;
    QTableWidget * manageinvoices;
    QPushButton * addEmp;
    QPushButton * removeEmp;
    QPushButton * editSalary;
    QHBoxLayout * editPushbuttons;
    QVBoxLayout * employeeslayout;

    Manager * FBTManager;

signals:
    void throw_error(QString);
    void throw_info(QString);
public slots:
    void display_error(QString);
    void display_info(QString);
    void employeeAddProductToStockDialog();
    void employeeAddProductToShopSlt(QTableWidget*, QTableWidget*);
    void employeeRemoveProductFromStockSlt();
    void employeeRemoveProductFromShopSlt(QTableWidget*);
    void customerAddToCartDialog(QTableWidget*);
    void customerPurchase();
    void removeFromCart();
    void increaseCreditDialog();
    void managerAddEmployeedialog();
    void managerRemoveEmployeeDialog();
    void managerEditSalaryDialog();
};
#endif // MAINWINDOW_H
