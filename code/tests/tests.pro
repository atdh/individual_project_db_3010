TEMPLATE = app

include(../defaults.pri)

CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp

LIBS += -L../src -lmyapp
