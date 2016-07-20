#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T08:37:35
#
#-------------------------------------------------

QT       += core gui\
        xml\
        sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface_v3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    functions.cpp \
    items/path.cpp \
    items/rail.cpp \
    items/intersection.cpp \
    items/signal.cpp \
    files.cpp \
    myqgraphicsview.cpp \
    items/road.cpp \
    items/circuit.cpp

HEADERS  += mainwindow.h \
    functions.h \
    items/path.h \
    items/rail.h \
    items/intersection.h \
    items/signal.h \
    files.h \
    myqgraphicsview.h \
    items/road.h \
    items/circuit.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
