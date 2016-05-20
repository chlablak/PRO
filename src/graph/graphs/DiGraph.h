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

    DiGraph(vector<Vertex*> &vertices, vector<DiEdge*> &edges)
            : DiGraphCommon(vertices, edges) { }

    DiGraph(const DiGraph& dg);

    virtual ~DiGraph() { }

    virtual bool isSimple() const override;

    virtual bool isConnected() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual Edges edgeList() const override;

    virtual void addEdge(IEdge *e) override;

    virtual void removeEdge(IEdge *e) override;

    virtual void removeVertex(Vertex *v) override;

    virtual DiGraph *clone() const override {
        return new DiGraph(*this);
    }

    virtual list<IEdge*> getEdges(Vertex *v1, Vertex *v2) const override;

    virtual IGraph *emptyClone() const override;

    virtual void assignEdge(IEdge *e) override;

    virtual void accept(Visitor *v, Vertex *from) override;

    virtual size_t E() const override;

    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;


};


#endif //GRAPH_DIGRAPH_H
