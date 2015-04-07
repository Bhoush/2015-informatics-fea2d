#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T12:58:45
#
#-------------------------------------------------

!include("../fea2d.pri") { error("Failed to include ../fea2d.pri") }

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fea2d
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

LIBS += -lmeshgen2d -lsolver2d -lvisualizer2d
