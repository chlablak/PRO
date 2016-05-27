//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_DIGRAPH_H
#define GRAPH_DIGRAPH_H

#include "GraphCommon.h"
#include "DiEdge.h"
#include "DiGraphCommon.h"

class DiGraph : public DiGraphCommon<DiEdge>
{

public:

    DiGraph() : DiGraphCommon() { }

    DiGraph(vector<Vertex *> &vertices) : DiGraphCommon(vertices) { }

    DiGraph(vector<Vertex*> &vertices, vector<IEdge*> &edges)
            : DiGraphCommon(vertices, edges) { }

    DiGraph(const DiGraph& dg);

    virtual ~DiGraph() { }

    virtual DiGraph *clone() const override;

    virtual IGraph *emptyClone() const override;

    // Visitor
    virtual void accept(Visitor *v, Vertex *from, Vertex *to) override;

    // Factory method
    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;
};


#endif //GRAPH_DIGRAPH_H
