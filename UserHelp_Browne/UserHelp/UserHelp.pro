#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T15:04:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UserHelp
TEMPLATE = app


SOURCES += main.cpp \
    helpwindow.cpp \
    helpbrowser.cpp \
    searchbar.cpp \
    keywordsearcher.cpp \
    helppage.cpp \
    filereader.cpp

HEADERS  += \
    helpwindow.h \
    searchbar.h \
    helpbrowser.h \
    keywordsearcher.h \
    helppage.h \
    filereader.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++0x
