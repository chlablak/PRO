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

    virtual bool isSimple() const;
    virtual bool isConnected() const;
    virtual bool isStronglyConnected() const;
    virtual bool isDirected() const;
    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_DIGRAPH_H
