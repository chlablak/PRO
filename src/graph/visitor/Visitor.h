//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VISITOR_H
#define GRAPH_VISITOR_H


#include "../graphs/IGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/FlowGraph.h"
#include "../graphs/DiGraph.h"

class Visitor {
public:
    virtual IGraph visitGraph(Graph& g) = 0;
    virtual IGraph visitDiGraph(DiGraph& g) = 0;
    virtual IGraph visitFlowGraph(FlowGraph& g) = 0;
};


#endif //GRAPH_VISITOR_H
