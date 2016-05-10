cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graphs/IGraph.h graphs/Vertex.cpp graphs/Vertex.h
        graphs/CommonEdge.h graphs/CommonEdge.cpp graphs/Edge.cpp graphs/Edge.h graphs/IGraph.cpp graphs/IGraph.h
        graphs/WeightedEdge.h graphs/WeightedEdge.cpp graphs/WeightedDiEdge.h graphs/WeightedDiEdge.cpp graphs/FlowEdge.h graphs/FlowEdge.cpp
        graphs/Graph.cpp graphs/Graph.h graphs/DiGraph.cpp graphs/DiGraph.h
        graphs/FlowGraph.cpp graphs/FlowGraph.h factory/VertexFactory.cpp
        graphs/DiEdge.cpp graphs/DiEdge.h
        factory/DiEdgeFactory.h factory/DiEdgeFactory.cpp
        factory/VertexFactory.h factory/EdgeFactory.cpp factory/EdgeFactory.h
        factory/GraphFactory.cpp factory/GraphFactory.h visitor/Visitor.h algorithms/BFS.cpp algorithms/BFS.h algorithms/DFS.cpp algorithms/DFS.h algorithms/ConnectedComponent.cpp algorithms/ConnectedComponent.h)
add_executable(graph ${SOURCE_FILES})