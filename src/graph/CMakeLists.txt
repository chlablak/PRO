cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graphs/GraphCommon.h graphs/Vertex.cpp graphs/Vertex.h
        graphs/IEdge.h graphs/IEdge.cpp graphs/Edge.cpp graphs/Edge.h
        graphs/GraphCommon.cpp graphs/GraphCommon.h
        graphs/FlowEdge.h graphs/FlowEdge.cpp
        graphs/Graph.cpp graphs/Graph.h graphs/DiGraph.cpp graphs/DiGraph.h
        graphs/FlowGraph.cpp graphs/FlowGraph.h
        graphs/DiEdge.cpp graphs/DiEdge.h visitor/Visitor.h
        algorithms/BFS.cpp algorithms/BFS.h algorithms/DFS.cpp algorithms/DFS.h
        algorithms/ConnectedComponent.cpp algorithms/ConnectedComponent.h graphs/IGraph.h)
add_executable(graph ${SOURCE_FILES})