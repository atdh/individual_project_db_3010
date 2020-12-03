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

OTHER_FILES += \
    defaults.pri
