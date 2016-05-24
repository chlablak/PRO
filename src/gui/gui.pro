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
    ../userHelp/browserpane.cpp \
    ../userHelp/buttonpane.cpp \
    ../userHelp/filereader.cpp \
    ../userHelp/helppage.cpp \
    ../userHelp/keywordsearcher.cpp \
    ../userHelp/mainbrowser.cpp \
    ../userHelp/navigationmenu.cpp \
    ../userHelp/navigationpane.cpp \
    ../userHelp/searchbar.cpp \
    ../userHelp/helpmainlayout.cpp \
    ../userHelp/helpwindow.cpp \
    ../visualization/view/items/ArrowItem.cpp \
    ../visualization/view/AbstractGraphItemFactory.cpp \
    ../visualization/view/GraphView.cpp \
    ../visualization/view/GraphScene.cpp \
    ../visualization/view/VertexItem.cpp \
    ../visualization/view/EdgeItem.cpp \
    ../visualization/view/DiEdgeItem.cpp \
    ../visualization/view/DiGraphItemFactory.cpp \
    ../visualization/view/FlowEdgeItem.cpp \
    ../visualization/view/FlowGraphItemFactory.cpp \
    ../visualization/view/GraphItemFactory.cpp \
    ../visualization/view/GraphSceneManager.cpp \
    ../visualization/GraphExporter.cpp \
    ../visualization/GraphWidget.cpp \
    ../graph/algorithms/BellmanFordSP.cpp \
    ../graph/algorithms/BFS.cpp \
    ../graph/algorithms/ConnectedComponent.cpp \
    ../graph/algorithms/CopyToDiGraph.cpp \
    ../graph/algorithms/CopyToFlowGraph.cpp \
    ../graph/algorithms/CopyToGraph.cpp \
    ../graph/algorithms/DFS.cpp \
    ../graph/algorithms/DijkstraSP.cpp \
    ../graph/algorithms/GraphAlgorithm.cpp \
    ../graph/algorithms/Kruskal.cpp \
    ../graph/algorithms/Prim.cpp \
    ../graph/algorithms/SCCTarjan.cpp \
    ../graph/algorithms/UnionFind.cpp \
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
    ../egli/detail/interface/algorithms.cpp \
    ../egli/detail/interface/basics.cpp \
    ../egli/detail/interface/builtins.cpp \
    ../egli/detail/interface.cpp \
    ../egli/detail/Preprocessor.cpp \
    ../egli/detail/TemporaryName.cpp \
    ../egli/Array.cpp \
    ../egli/Data.cpp \
    ../egli/Exception.cpp \
    ../egli/FunctionTable.cpp \
    ../egli/GraphWrapper.cpp \
    ../egli/Interpreter.cpp \
    ../egli/Number.cpp \
    ../egli/Parser.cpp \
    ../egli/ProcessingUnit.cpp \
    ../egli/Statement.cpp \
    ../egli/TEdge.cpp \
    ../egli/toString.cpp \
    ../egli/TVertex.cpp \
    ../egli/VariableTable.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    graphwindow.h \
    ../userHelp/browserpane.h \
    ../userHelp/buttonpane.h \
    ../userHelp/filereader.h \
    ../userHelp/helppage.h \
    ../userHelp/keywordsearcher.h \
    ../userHelp/mainbrowser.h \
    ../userHelp/navigationmenu.h \
    ../userHelp/navigationpane.h \
    ../userHelp/searchbar.h \
    ../userHelp/helpmainlayout.h \
    ../userHelp/helpwindow.h \
    ui_dialogstring.h \
    ui_graphwindow.h \
    ui_mainwindow.h \
    ../visualization/view/items/ArrowItem.h \
    ../visualization/view/AbstractGraphItemFactory.h \
    ../visualization/view/DiEdgeItem.h \
    ../visualization/view/DiGraphItemFactory.h \
    ../visualization/view/EdgeItem.h \
    ../visualization/view/FlowEdgeItem.h \
    ../visualization/view/FlowGraphItemFactory.h \
    ../visualization/view/GraphItemFactory.h \
    ../visualization/view/GraphScene.h \
    ../visualization/view/GraphSceneManager.h \
    ../visualization/view/GraphView.h \
    ../visualization/view/VertexItem.h \
    ../visualization/Constants.h \
    ../visualization/GraphExporter.h \
    ../visualization/GraphWidget.h \
    ../graph/algorithms/BellmanFordSP.h \
    ../graph/algorithms/BFS.h \
    ../graph/algorithms/ConnectedComponent.h \
    ../graph/algorithms/CopyToDiGraph.h \
    ../graph/algorithms/CopyToFlowGraph.h \
    ../graph/algorithms/CopyToGraph.h \
    ../graph/algorithms/DFS.h \
    ../graph/algorithms/DijkstraSP.h \
    ../graph/algorithms/GraphAlgorithm.h \
    ../graph/algorithms/Kruskal.h \
    ../graph/algorithms/Prim.h \
    ../graph/algorithms/SCCTarjan.h \
    ../graph/algorithms/UnionFind.h \
    ../graph/algorithms/Visitor.h \
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
    ../graph/Includes.h \
    ../utility/dictionary/Node.h \
    ../utility/dictionary/TST.h \
    ../utility/dictionary/TST_implem.h \
    ../utility/Global.h \
    ../utility/Hash.h \
    ../utility/Optional.h \
    ../egli/detail/interface/algorithms.h \
    ../egli/detail/interface/basics.h \
    ../egli/detail/interface/builtins.h \
    ../egli/detail/EnumValue.h \
    ../egli/detail/FunctionImpl.h \
    ../egli/detail/Grammar.h \
    ../egli/detail/interface.h \
    ../egli/detail/Preprocessor.h \
    ../egli/detail/RealType.h \
    ../egli/detail/TemporaryName.h \
    ../egli/Array.h \
    ../egli/Data.h \
    ../egli/egli.h \
    ../egli/Exception.h \
    ../egli/Function.h \
    ../egli/FunctionTable.h \
    ../egli/GraphWrapper.h \
    ../egli/Interpreter.h \
    ../egli/Number.h \
    ../egli/Parser.h \
    ../egli/ProcessingUnit.h \
    ../egli/Statement.h \
    ../egli/TEdge.h \
    ../egli/toString.h \
    ../egli/TVertex.h \
    ../egli/Type.h \
    ../egli/VariableTable.h
	
FORMS    += mainwindow.ui \
    dialogstring.ui \
    graphwindow.ui

QMAKE_CXXFLAGS += -std=c++0x -fpermissive

INCLUDEPATH += "C:/Program Files/boost/boost_1_60_0/"
