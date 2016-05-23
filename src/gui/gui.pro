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
    userHelp/filereader.cpp \
    userHelp/helpbrowser.cpp \
    userHelp/helppage.cpp \
    userHelp/helpwindow.cpp \
    userHelp/keywordsearcher.cpp \
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
    ../graph/graphs/Vertex.cpp \
    ../egli/detail/interface/algorithms.cpp \
    ../egli/detail/interface/basics.cpp \
    ../egli/detail/interface/builtins.cpp \
    ../egli/detail/interface.cpp \
    ../egli/detail/Preprocessor.cpp \
    ../egli/detail/TemporaryName.cpp \
    ../egli/Array.cpp \
    ../egli/Data.cpp \
    ../egli/Edge.cpp \
    ../egli/Exception.cpp \
    ../egli/FunctionTable.cpp \
    ../egli/GraphWrapper.cpp \
    ../egli/Interpreter.cpp \
    ../egli/main.cpp \
    ../egli/Number.cpp \
    ../egli/Parser.cpp \
    ../egli/ProcessingUnit.cpp \
    ../egli/Statement.cpp \
    ../egli/VariableTable.cpp \
    ../egli/Vertex.cpp

HEADERS  += mainwindow.h \
    console.h \
    dialogstring.h \
    graphwindow.h \
    userHelp/filereader.h \
    userHelp/helpbrowser.h \
    userHelp/helppage.h \
    userHelp/helpwindow.h \
    userHelp/keywordsearcher.h \
    userHelp/searchBar.h \
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
    ../graph/Includes.h \
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
    ../egli/Edge.h \
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
    ../egli/Type.h \
    ../egli/VariableTable.h \
    ../egli/Vertex.h
	
FORMS    += mainwindow.ui \
    dialogstring.ui \
    graphwindow.ui

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += C:/boost_1_60_0/
LIBS += "-LC:/boost_1_60_0/stage/lib/"
