//
// Created by sebri on 15.05.2016.
//

#ifndef GRAPH_GRAPHALGORITHM_H
#define GRAPH_GRAPHALGORITHM_H


#include "../graphs/IGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

class GraphAlgorithm
{
public:
    static IGraph* bfs(IGraph *g, Vertex *from, vector<double>& distances);
    static IGraph* dfs(IGraph *g, Vertex *from, vector<double>& dfsnum);
    static vector<double> connectedComponent(IGraph *g);
    static vector<double> stronglyConnectedComponent(IGraph *g);
    static IGraph* kruskal(IGraph *g);
    static IGraph* prim(IGraph *g, Vertex *from = nullptr);
    static IGraph* copyToGraph(IGraph *g);
    static IGraph* copyToDiGraph(IGraph *g);
    static IGraph* copyToFlowGraph(IGraph *g);
    static IGraph* bellmanFord(IGraph *g, Vertex *from, vector<double>& distances);
    static IGraph* dijkstra(IGraph *g, Vertex *from, vector<double>& distances);
    static IGraph* detectCycle(IGraph *g);
    static vector<double> topoloqicalSort(IGraph* g);
};


#endif //GRAPH_GRAPHALGORITHM_H
