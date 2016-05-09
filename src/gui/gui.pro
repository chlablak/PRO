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
    userHelp/filereader.cpp \
    userHelp/helpbrowser.cpp \
    userHelp/helppage.cpp \
    userHelp/helpwindow.cpp \
    userHelp/keywordsearcher.cpp \
    userHelp/searchbar.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    userHelp/filereader.h \
    userHelp/helpbrowser.h \
    userHelp/helppage.h \
    userHelp/helpwindow.h \
    userHelp/keywordsearcher.h \
    userHelp/searchBar.h

FORMS    += mainwindow.ui \
    dialogstring.ui

QMAKE_CXXFLAGS += -std=c++0x
