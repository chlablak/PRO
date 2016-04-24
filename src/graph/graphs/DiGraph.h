//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_DIGRAPH_H
#define GRAPH_DIGRAPH_H


#include "GraphCommon.h"

class DiGraph : public GraphCommon {

public:
    DiGraph(const vector<Vertex> &vertices, const vector<Edge> &edges)
            : GraphCommon(vertices, edges) { }

    bool isSimple() const;
    bool isConnected() const;
    bool isStronglyConnected() const;
    bool isDirected() const;
};


#endif //GRAPH_DIGRAPH_H
