TEMPLATE = app

QT += widgets testlib

include(../defaults.pri)

CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += qt_tests.cpp

RESOURCES += \
    authentication.txt

LIBS += -L../src -lmyapp
