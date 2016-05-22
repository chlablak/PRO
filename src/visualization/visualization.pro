#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T15:19:34
#
#-------------------------------------------------

QT       += core gui svg

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visualization
TEMPLATE = app

SOURCES += main.cpp \
    view/GraphView.cpp \
    view/GraphScene.cpp \
    view/VertexItem.cpp \
    view/EdgeItem.cpp \
    view/DiEdgeItem.cpp \
    view/FlowEdgeItem.cpp \
    view/GraphItemFactory.cpp \
    view/DiGraphItemFactory.cpp \
    view/FlowGraphItemFactory.cpp \
    view/items/ArrowItem.cpp \
    GraphWidget.cpp \
    GraphExporter.cpp \
    ../graph/graphs/DiEdge.cpp \
    ../graph/graphs/DiEdgeCommon.cpp \
    ../graph/graphs/DiGraph.cpp \
    ../graph/graphs/Edge.cpp \
    ../graph/graphs/EdgeCommon.cpp \
    ../graph/graphs/FlowEdge.cpp \
    ../graph/graphs/FlowGraph.cpp \
    ../graph/graphs/Graph.cpp \
    ../graph/graphs/GraphCommon.cpp \
    ../graph/graphs/Vertex.cpp \
    ../graph/algorithms/ConnectedComponent.cpp

HEADERS  += \
    Constants.h \
    view/GraphView.h \
    view/GraphScene.h \
    view/VertexItem.h \
    view/EdgeItem.h \
    view/DiEdgeItem.h \
    view/FlowEdgeItem.h \
    view/AbstractGraphItemFactory.h \
    view/GraphItemFactory.h \
    view/DiGraphItemFactory.h \
    view/FlowGraphItemFactory.h \
    view/items/ArrowItem.h \
    GraphWidget.h \
    GraphExporter.h \
    ../graph/Includes.h \
    ../graph/graphs/DiEdge.h \
    ../graph/graphs/DiEdgeCommon.h \
    ../graph/graphs/DiGraph.h \
    ../graph/graphs/DiGraphCommon.h \
    ../graph/graphs/DiGraphCommon.hpp \
    ../graph/graphs/Edge.h \
    ../graph/graphs/EdgeCommon.h \
    ../graph/graphs/FlowEdge.h \
    ../graph/graphs/FlowGraph.h \
    ../graph/graphs/Graph.h \
    ../graph/graphs/GraphCommon.h \
    ../graph/graphs/IEdge.h \
    ../graph/graphs/IGraph.h \
    ../graph/graphs/Vertex.h \
    ../graph/algorithms/ConnectedComponent.h
