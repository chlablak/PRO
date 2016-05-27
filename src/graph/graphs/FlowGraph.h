//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_FLOWGRAPH_H
#define GRAPH_FLOWGRAPH_H

#include "DiGraphCommon.h"
#include "FlowEdge.h"

class FlowGraph : public DiGraphCommon<FlowEdge>
{
public:
    FlowGraph() : DiGraphCommon() { }

    FlowGraph(vector<Vertex *> &vertices) : DiGraphCommon(vertices) { }

    FlowGraph(vector<Vertex*> &vertices, vector<IEdge*> &edges)
    : DiGraphCommon(vertices, edges) { }

    FlowGraph(const FlowGraph& dg);

    virtual ~FlowGraph() { }

    virtual FlowGraph *clone() const override;

    virtual IGraph *emptyClone() const override;

    virtual bool hasPositiveCapacity() const;

    // Visitor
    virtual void accept(Visitor *v, Vertex *from, Vertex *to) override;

    // Factory method
    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;
};


#endif //GRAPH_FLOWGRAPH_H