QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../defaults.pri)

CONFIG   -= app_bundle

TEMPLATE = app
 
SOURCES += main.cpp
 
LIBS += -L../src -lmyapp

RESOURCES += \
    storage.txt \
    data.txt \
    person.png \
    home.png \
    authentication.txt
