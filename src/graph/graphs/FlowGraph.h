//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_FLOWGRAPH_H
#define GRAPH_FLOWGRAPH_H


#include "DiGraph.h"

class FlowGraph : public DiGraph
{
public:
    // TODO constructeurs

    virtual IGraph::Edges getEdges(Vertex *v1, Vertex *v2) const override;

    virtual IGraph *emptyClone() const override;
};


#endif //GRAPH_FLOWGRAPH_H