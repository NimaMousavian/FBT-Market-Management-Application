QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    Employee.cpp \
    Human.cpp \
    home.cpp \
    login_page.cpp \
    main.cpp \
    mainwindow.cpp \
    sign_up_page.cpp

HEADERS += \
    Customer.h \
    Employee.h \
    Human.h \
    home.h \
    login_page.h \
    mainwindow.h \
    sign_up_page.h

FORMS += \
    home.ui \
    login_page.ui \
    mainwindow.ui \
    sign_up_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
