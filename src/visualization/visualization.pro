#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T15:19:34
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visualization
TEMPLATE = app

SOURCES += main.cpp \
    view/GraphView.cpp \
    view/GraphScene.cpp \
    view/VertexItem.cpp \
    view/EdgeItem.cpp \
    GraphWidget.cpp \
    igraph/IEdge.cpp \
    igraph/IGraph.cpp \
    igraph/IVertex.cpp \
    GraphExporter.cpp

HEADERS  += \
    Constants.h \
    view/GraphView.h \
    view/GraphScene.h \
    view/VertexItem.h \
    view/EdgeItem.h \
    GraphWidget.h \
    igraph/IEdge.h \
    igraph/IGraph.h \
    igraph/IVertex.h \
    GraphExporter.h
