#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T14:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    dialogstring.cpp \
    graphwindow.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    graphwindow.h

FORMS    += mainwindow.ui \
    dialogstring.ui \
    graphwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
