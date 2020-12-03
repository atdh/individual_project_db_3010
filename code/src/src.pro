QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle

include(../defaults.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = lib

TARGET = myapp

SOURCES += \
    clickablelabel.cpp \
    databasebst.cpp \
    dbwindow.cpp \
    deletedialog.cpp \
    deleteuserdialog.cpp \
    dialogfactory.cpp \
    getdialog.cpp \
    logininterface.cpp \
    loginwindow.cpp \
    mydialog.cpp \
    passworddialog.cpp \
    postdialog.cpp \
    putdialog.cpp

HEADERS += \
    clickablelabel.h \
    databasebst.h \
    dbwindow.h \
    deletedialog.h \
    deleteuserdialog.h \
    dialogfactory.h \
    getdialog.h \
    logininterface.h \
    loginwindow.h \
    mydialog.h \
    passworddialog.h \
    postdialog.h \
    putdialog.h

FORMS += \
    dbwindow.ui \
    deletedialog.ui \
    deleteuserdialog.ui \
    getdialog.ui \
    loginwindow.ui \
    passworddialog.ui \
    postdialog.ui \
    putdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
