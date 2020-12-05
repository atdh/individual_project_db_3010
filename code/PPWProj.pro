TEMPLATE = subdirs
CONFIG+=ordered

SUBDIRS = \
    src \
    app

app.depends = src

#SUBDIRS = \
#    src \
#    tests

#tests.depends = src

#SUBDIRS = \
#    src \
#    qt_tests

#qt_tests.depends = src

OTHER_FILES += \
    defaults.pri
