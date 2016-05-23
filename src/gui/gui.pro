#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T14:43:30
#
#-------------------------------------------------

QT       += core gui svg

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    dialogstring.cpp \
    graphwindow.cpp \
    userHelp/browserpane.cpp \
    userHelp/buttonpane.cpp \
    userHelp/filereader.cpp \
    userHelp/helppage.cpp \
    userHelp/keywordsearcher.cpp \
    userHelp/mainbrowser.cpp \
    userHelp/navigationmenu.cpp \
    userHelp/navigationpane.cpp \
    userHelp/searchbar.cpp \
    ../visualization/view/GraphView.cpp \
    ../visualization/view/GraphScene.cpp \
    ../visualization/view/VertexItem.cpp \
    ../visualization/view/EdgeItem.cpp \
    ../visualization/view/DiEdgeItem.cpp \
    ../visualization/view/FlowEdgeItem.cpp \
    ../visualization/view/GraphItemFactory.cpp \
    ../visualization/view/DiGraphItemFactory.cpp \
    ../visualization/view/FlowGraphItemFactory.cpp \
    ../visualization/view/items/ArrowItem.cpp \
    ../visualization/view/GraphSceneManager.cpp \
    ../visualization/GraphWidget.cpp \
    ../visualization/GraphExporter.cpp \
    ../graph/algorithms/ConnectedComponent.cpp \
    ../graph/graphs/DiEdge.cpp \
    ../graph/graphs/DiGraph.cpp \
    ../graph/graphs/Edge.cpp \
    ../graph/graphs/FlowEdge.cpp \
    ../graph/graphs/FlowGraph.cpp \
    ../graph/graphs/Graph.cpp \
    ../graph/graphs/GraphCommon.cpp \
    ../graph/graphs/Vertex.cpp \
    ../graph/graphs/DiEdgeCommon.cpp \
    ../graph/graphs/EdgeCommon.cpp \
    userHelp/helpmainlayout.cpp \
    userHelp/helpwindow.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    graphwindow.h \
    userHelp/browserpane.h \
    userHelp/buttonpane.h \
    userHelp/filereader.h \
    userHelp/helppage.h \
    userHelp/keywordsearcher.h \
    userHelp/mainbrowser.h \
    userHelp/navigationmenu.h \
    userHelp/navigationpane.h \
    userHelp/searchbar.h \
    ui_dialogstring.h \
    ui_graphwindow.h \
    ui_mainwindow.h \
    ../visualization/Constants.h \
    ../visualization/view/GraphView.h \
    ../visualization/view/GraphScene.h \
    ../visualization/view/VertexItem.h \
    ../visualization/view/EdgeItem.h \
    ../visualization/view/DiEdgeItem.h \
    ../visualization/view/FlowEdgeItem.h \
    ../visualization/view/AbstractGraphItemFactory.h \
    ../visualization/view/GraphItemFactory.h \
    ../visualization/view/DiGraphItemFactory.h \
    ../visualization/view/FlowGraphItemFactory.h \
    ../visualization/view/items/ArrowItem.h \
    ../visualization/view/GraphSceneManager.h \
    ../visualization/GraphWidget.h \
    ../visualization/GraphExporter.h \
    ../utility/Hash.h \
    ../graph/algorithms/ConnectedComponent.h \
    ../graph/graphs/DiEdge.h \
    ../graph/graphs/DiGraph.h \
    ../graph/graphs/Edge.h \
    ../graph/graphs/FlowEdge.h \
    ../graph/graphs/FlowGraph.h \
    ../graph/graphs/Graph.h \
    ../graph/graphs/GraphCommon.h \
    ../graph/graphs/IEdge.h \
    ../graph/graphs/IGraph.h \
    ../graph/graphs/Vertex.h \
    ../graph/Includes.h \
    ../graph/graphs/DiEdgeCommon.h \
    ../graph/graphs/DiGraphCommon.h \
    ../graph/graphs/DiGraphCommon.hpp \
    ../graph/graphs/EdgeCommon.h \
    userHelp/helpmainlayout.h \
    userHelp/helpwindow.h
	
FORMS    += mainwindow.ui \
    dialogstring.ui \
    graphwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
