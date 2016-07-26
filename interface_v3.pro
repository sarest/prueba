QT       += core gui xml sql

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
    items/circuit.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    functions.h \
    items/path.h \
    items/rail.h \
    items/intersection.h \
    items/signal.h \
    files.h \
    myqgraphicsview.h \
    items/road.h \
    items/circuit.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    resources.qrc
