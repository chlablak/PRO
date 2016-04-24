//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_FLOWGRAPH_H
#define GRAPH_FLOWGRAPH_H


#include "DiGraph.h"

class FlowGraph : public DiGraph {

public:
    FlowGraph(const vector<Vertex> &vertices, const vector<Edge> &edges)
            : DiGraph(vertices, edges) { }
};


#endif //GRAPH_FLOWGRAPH_H
