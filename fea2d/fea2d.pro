#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:58:45
#
#-------------------------------------------------

!include("../fea2d.pri") { error("Failed to include ../fea2d.pri") }

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fea2d
TEMPLATE = app


SOURCES += main.cpp\
    Document.cpp \
    Visualizer2d.cpp \
    MainWindow.cpp

HEADERS  += \
    Document.h \
    Visualizer2d.h \
    MainWindow.h

FORMS    += mainwindow.ui

LIBS += -lmeshgen2d -lsolver2d
