#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T15:19:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visualization
TEMPLATE = app


SOURCES += main.cpp\
    graphscene.cpp \
    vertexitem.cpp

HEADERS  += \
    graphscene.h \
    iedge.h \
    igraph.h \
    ivertex.h \
    vertexitem.h
