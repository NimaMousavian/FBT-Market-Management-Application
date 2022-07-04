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
private:
    Ui::MainWindow *ui;

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

signals:
    void throw_error(QString);
    void throw_info(QString);
public slots:
    void display_error(QString);
    void display_info(QString);
};
#endif // MAINWINDOW_H
