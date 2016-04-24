cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graphs/IGraph.h graphs/Vertex.cpp graphs/Vertex.h
        graphs/Edge.cpp graphs/Edge.h graphs/GraphCommon.cpp graphs/GraphCommon.h
        graphs/Graph.cpp graphs/Graph.h graphs/DiGraph.cpp graphs/DiGraph.h
        graphs/FlowGraph.cpp graphs/FlowGraph.h factory/VertexFactory.cpp
        factory/VertexFactory.h factory/EdgeFactory.cpp factory/EdgeFactory.h
        factory/GraphFactory.cpp factory/GraphFactory.h visitor/Visitor.h)
add_executable(graph ${SOURCE_FILES})