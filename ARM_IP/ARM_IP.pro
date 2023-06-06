QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    del_prod.cpp \
    login_password.cpp \
    main.cpp \
    new_item.cpp \
    pie.cpp \
    registr.cpp \
    seller.cpp \
    shopper.cpp

HEADERS += \
    del_prod.h \
    login_password.h \
    new_item.h \
    pie.h \
    registr.h \
    seller.h \
    shopper.h

FORMS += \
    del_prod.ui \
    login_password.ui \
    new_item.ui \
    registr.ui \
    seller.ui \
    shopper.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
