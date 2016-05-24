cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

set(SOURCE_FILES main.cpp graphs/GraphCommon.h graphs/Vertex.cpp graphs/Vertex.h
        graphs/IEdge.h graphs/Edge.cpp graphs/Edge.h
        graphs/GraphCommon.cpp graphs/GraphCommon.h
        graphs/FlowEdge.h graphs/FlowEdge.cpp
        graphs/Graph.cpp graphs/Graph.h graphs/DiGraph.cpp graphs/DiGraph.h
        graphs/FlowGraph.cpp graphs/FlowGraph.h
        graphs/DiEdge.cpp graphs/DiEdge.h algorithms/Visitor.h
        algorithms/BFS.cpp algorithms/BFS.h algorithms/DFS.cpp algorithms/DFS.h
        algorithms/ConnectedComponent.cpp algorithms/ConnectedComponent.h
        graphs/IGraph.h includes.h algorithms/GraphAlgorithm.cpp
        algorithms/GraphAlgorithm.h algorithms/Kruskal.cpp algorithms/Kruskal.h
        algorithms/Prim.cpp algorithms/Prim.h algorithms/UnionFind.cpp
        algorithms/UnionFind.h algorithms/DijkstraSP.cpp algorithms/DijkstraSP.h
        algorithms/CopyToGraph.cpp algorithms/CopyToGraph.h
        algorithms/CopyToDiGraph.cpp algorithms/CopyToDiGraph.h
        algorithms/CopyToFlowGraph.cpp algorithms/CopyToFlowGraph.h
        graphs/DiEdgeCommon.h graphs/DiEdgeCommon.cpp graphs/DiGraphCommon.h
        algorithms/TopologicalSort.h algorithms/TopologicalSort.cpp
        algorithms/DetectedCycle.h algorithms/DetectedCycle.cpp
        graphs/DiGraphCommon.hpp graphs/EdgeCommon.cpp graphs/EdgeCommon.h tests/TestGraph.h tests/TestDiGraph.h tests/TestFlowGraph.h algorithms/SCCTarjan.cpp algorithms/SCCTarjan.h algorithms/BellmanFordSP.cpp algorithms/BellmanFordSP.h)
add_executable(graph ${SOURCE_FILES})