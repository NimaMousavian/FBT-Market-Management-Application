QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    Employee.cpp \
    Human.cpp \
    customer_invoice.cpp \
    employee_add_product_dialog.cpp \
    employee_signup.cpp \
    home.cpp \
    login_page.cpp \
    main.cpp \
    mainwindow.cpp \
    product.cpp \
    sign_up_page.cpp

HEADERS += \
    Customer.h \
    Employee.h \
    Human.h \
    customer_invoice.h \
    employee_add_product_dialog.h \
    employee_signup.h \
    home.h \
    login_page.h \
    mainwindow.h \
    product.h \
    sign_up_page.h

FORMS += \
    customer_invoice.ui \
    employee_add_product_dialog.ui \
    employee_signup.ui \
    home.ui \
    login_page.ui \
    mainwindow.ui \
    sign_up_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../icons/icon.qrc \
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
