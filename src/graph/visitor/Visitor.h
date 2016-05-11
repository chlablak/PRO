//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VISITOR_H
#define GRAPH_VISITOR_H

#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

class Visitor {
public:
    Visitor();
    virtual ~Visitor() = 0;
    //virtual Graph& visitGraph(Graph& g) = 0;
    virtual Graph* visitGraph(Graph& g, const Vertex& v) = 0;
    //virtual DiGraph& visitDiGraph(DiGraph& g) = 0;
    virtual DiGraph* visitDiGraph(DiGraph& g, const Vertex& v) = 0;
    //virtual FlowGraph& visitFlowGraph(FlowGraph& g) = 0;
    virtual FlowGraph* visitFlowGraph(FlowGraph& g, const Vertex& v) = 0;
};


#endif //GRAPH_VISITOR_H
