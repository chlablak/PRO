#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T14:43:30
#
#-------------------------------------------------

QT       += core gui svg

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
    userHelp/helpwindow.cpp \
    userHelp/keywordsearcher.cpp \
    userHelp/mainbrowser.cpp \
    userHelp/navigationmenu.cpp \
    userHelp/navigationpane.cpp \
    userHelp/searchbar.cpp \
    ../visualization/view/DiEdgeItem.cpp \
    ../visualization/view/DiGraphItemFactory.cpp \
    ../visualization/view/EdgeItem.cpp \
    ../visualization/view/FlowEdgeItem.cpp \
    ../visualization/view/FlowGraphItemFactory.cpp \
    ../visualization/view/GraphItemFactory.cpp \
    ../visualization/view/GraphScene.cpp \
    ../visualization/view/GraphView.cpp \
    ../visualization/view/VertexItem.cpp \
    ../visualization/GraphExporter.cpp \
    ../visualization/graphwidget.cpp \
    ../graph/algorithms/ConnectedComponent.cpp \
    ../graph/graphs/DiEdge.cpp \
    ../graph/graphs/DiGraph.cpp \
    ../graph/graphs/Edge.cpp \
    ../graph/graphs/FlowEdge.cpp \
    ../graph/graphs/FlowGraph.cpp \
    ../graph/graphs/Graph.cpp \
    ../graph/graphs/GraphCommon.cpp \
    ../graph/graphs/IEdge.cpp \
    ../graph/graphs/Vertex.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    graphwindow.h \
    userHelp/browserpane.h \
    userHelp/buttonpane.h \
    userHelp/filereader.h \
    userHelp/helppage.h \
    userHelp/helpwindow.h \
    userHelp/keywordsearcher.h \
    userHelp/mainbrowser.h \
    userHelp/navigationmenu.h \
    userHelp/navigationpane.h \
    userHelp/searchbar.h \
    ui_dialogstring.h \
    ui_graphwindow.h \
    ui_mainwindow.h \
    ../visualization/view/AbstractGraphItemFactory.h \
    ../visualization/view/DiEdgeItem.h \
    ../visualization/view/DiGraphItemFactory.h \
    ../visualization/view/EdgeItem.h \
    ../visualization/view/FlowEdgeItem.h \
    ../visualization/view/FlowGraphItemFactory.h \
    ../visualization/view/GraphItemFactory.h \
    ../visualization/view/GraphScene.h \
    ../visualization/view/GraphView.h \
    ../visualization/view/VertexItem.h \
    ../visualization/constants.h \
    ../visualization/GraphExporter.h \
    ../visualization/graphwidget.h \
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
    ../graph/Includes.h
	
FORMS    += mainwindow.ui \
    dialogstring.ui \
    graphwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
