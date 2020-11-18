QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databasebst.cpp \
    deletedialog.cpp \
    dialogfactory.cpp \
    getdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mydialog.cpp \
    postdialog.cpp \
    putdialog.cpp

HEADERS += \
    databasebst.h \
    deletedialog.h \
    dialogfactory.h \
    getdialog.h \
    mainwindow.h \
    mydialog.h \
    postdialog.h \
    putdialog.h

FORMS += \
    deletedialog.ui \
    getdialog.ui \
    mainwindow.ui \
    postdialog.ui \
    putdialog.ui

RESOURCES += \
    storage.txt \
    data.txt

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
