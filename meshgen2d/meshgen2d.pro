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

SOURCES += \
    NodeGenerator.cpp \
    MeshGen2d.cpp \
    ElementGenerator.cpp

HEADERS +=\
        meshgen2d_global.h \
    MeshGen2d.h \
    NodeGenerator.h \
    ElementGenerator.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
