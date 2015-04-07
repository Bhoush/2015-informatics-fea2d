#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:54:58
#
#-------------------------------------------------

!include("../fea2d.pri") { error("Failed to include ../fea2d.pri") }

QT       -= gui

TARGET = meshgen2d
TEMPLATE = lib

DEFINES += MESHGEN2D_LIBRARY

SOURCES += meshgen2d.cpp

HEADERS += meshgen2d.h\
        meshgen2d_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
