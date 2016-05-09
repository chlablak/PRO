//
// Created by sebri on 01.05.2016.
//

#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H


#include "../visitor/Visitor.h"

class BFS : public Visitor {
    ~BFS();
    Graph& visitGraph(Graph& g, const Vertex& v);
    DiGraph& visitDiGraph(DiGraph& g, const Vertex& v);
    FlowGraph& visitFlowGraph(FlowGraph& g, const Vertex& v);
};


#endif //GRAPH_BFS_H
