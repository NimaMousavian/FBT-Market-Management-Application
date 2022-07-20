QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_FILE += Resource.rc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    Employee.cpp \
    Human.cpp \
    aboutus_page.cpp \
    addtocart_dialog.cpp \
    Manager.cpp \
    changepass_dialog.cpp \
    customer_invoice.cpp \
    employee_add_product_dialog.cpp \
    employee_signup.cpp \
    home.cpp \
    increase_credit_dialog.cpp \
    login_page.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_edit_salary_dialog.cpp \
    manager_remove_employee_dialog.cpp \
    manageraddemployeedialog.cpp \
    product.cpp \
    sign_up_page.cpp
HEADERS += \
    Customer.h \
    Employee.h \
    Human.h \
    aboutus_page.h \
    addtocart_dialog.h \
    Manager.h \
    changepass_dialog.h \
    customer_invoice.h \
    employee_add_product_dialog.h \
    employee_signup.h \
    home.h \
    increase_credit_dialog.h \
    login_page.h \
    mainwindow.h \
    manager_edit_salary_dialog.h \
    manager_remove_employee_dialog.h \
    manageraddemployeedialog.h \
    product.h \
    sign_up_page.h
FORMS += \
    aboutus_page.ui \
    addtocart_dialog.ui \
    changepass_dialog.ui \
    customer_invoice.ui \
    employee_add_product_dialog.ui \
    employee_signup.ui \
    home.ui \
    increase_credit_dialog.ui \
    login_page.ui \
    mainwindow.ui \
    manager_edit_salary_dialog.ui \
    manager_remove_employee_dialog.ui \
    manageraddemployeedialog.ui \
    sign_up_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../icons/icons.qrc \
    ../images/images.qrc

DISTFILES += \
    ../icons/about.png \
    ../icons/add.png \
    ../icons/barcode.png \
    ../icons/barcode_scanner.png \
    ../icons/cancel.png \
    ../icons/cash_register.png \
    ../icons/category.png \
    ../icons/clear.png \
    ../icons/delivery.png \
    ../icons/dollar.png \
    ../icons/download.png \
    ../icons/edit.png \
    ../icons/english.png \
    ../icons/exit.png \
    ../icons/export.png \
    ../icons/file.png \
    ../icons/forgot_password.png \
    ../icons/go back.png \
    ../icons/help.png \
    ../icons/import.png \
    ../icons/language.png \
    ../icons/login.png \
    ../icons/login2.png \
    ../icons/manual.png \
    ../icons/nepali.png \
    ../icons/ok.png \
    ../icons/password.png \
    ../icons/pos.png \
    ../icons/print.png \
    ../icons/product.png \
    ../icons/receipt.png \
    ../icons/remove.png \
    ../icons/sales.png \
    ../icons/search.png \
    ../icons/signup.png \
    ../icons/store.png \
    ../icons/support.png \
    ../icons/trolley.png \
    ../icons/user_add.png \
    ../icons/user_edit.png \
    ../icons/user_menu.png \
    ../icons/user_ok.png \
    ../icons/user_remove.png \
    ../icons/users.png \
    ../icons/warehouse.png
