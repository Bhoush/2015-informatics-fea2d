#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:57:49
#
#-------------------------------------------------

!include("../fea2d.pri") { error("Failed to include ../fea2d.pri") }

QT       -= gui

TARGET = visualizer2d
TEMPLATE = lib

DEFINES += VISUALIZER2D_LIBRARY

SOURCES += visualizer2d.cpp

HEADERS += visualizer2d.h\
        visualizer2d_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
