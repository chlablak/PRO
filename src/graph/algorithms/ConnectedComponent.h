//
// Created by sebri on 08.05.2016.
//

#ifndef GRAPH_CONNECTEDCOMPONENT_H
#define GRAPH_CONNECTEDCOMPONENT_H


#include "../visitor/Visitor.h"

class ConnectedComponent : public Visitor {
private:
    // Table containing the number of the connected component associated
    // for each vertex of the graph
    vector<size_t> cc;
public:
    ~ConnectedComponent();
    virtual Graph* visitGraph(Graph& g, const Vertex& v);
    virtual DiGraph* visitDiGraph(DiGraph& g, const Vertex& v);
    virtual FlowGraph* visitFlowGraph(FlowGraph& g, const Vertex& v);
};


#endif //GRAPH_CONNECTEDCOMPONENT_H
