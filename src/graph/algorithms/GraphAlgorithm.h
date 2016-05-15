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
    static IGraph* bfs(Graph *g, Vertex *from, vector<int> *distances);
    static IGraph* bfs(DiGraph *g, Vertex *from, vector<int> *distances);
    static IGraph* bfs(FlowGraph *g, Vertex *from, vector<int> *distances);


};


#endif //GRAPH_GRAPHALGORITHM_H
