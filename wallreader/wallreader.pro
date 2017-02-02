#-------------------------------------------------
#
# Project created by QtCreator 2017-01-29T22:26:03
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wallreader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        interface.cpp \
    login.cpp \
    mismatch.cpp \
    vkpost.cpp \
    ../qt-json/json.cpp \
    ../ibpp/tests/C++/firebird.cpp \
    vkapi.cpp \
    firecontrol.cpp

HEADERS  += interface.h \
    login.h \
    mismatch.h \
    vkpost.h \
    ../qt-json/json.h \
    ../ibpp/tests/C++/firebird.h \
    vkapi.h \
    firecontrol.h

FORMS    += interface.ui \
    login.ui \
    mismatch.ui
