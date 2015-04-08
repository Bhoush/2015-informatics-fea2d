#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:56:33
#
#-------------------------------------------------

!include("../fea2d.pri") { error("Failed to include ../fea2d.pri") }

QT       -= gui

TARGET = solver2d
TEMPLATE = lib

DEFINES += SOLVER2D_LIBRARY

SOURCES += \
    Solver2d.cpp

HEADERS +=\
        solver2d_global.h \
    Solver2d.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
