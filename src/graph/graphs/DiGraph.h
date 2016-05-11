//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_DIGRAPH_H
#define GRAPH_DIGRAPH_H

#include "IGraph.h"
#include "DiEdge.h"

class DiGraph : public IGraph<DiEdge>
{

public:
    DiGraph(vector<Vertex*> &vertices, vector<DiEdge*> &edges);

    ~DiGraph();

    virtual bool isSimple() const override;

    virtual bool isConnected() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual Edges edgeList() const override;

    virtual void addEdge(DiEdge *e) override;

    virtual void removeEdge(DiEdge *edge) override;

    virtual void removeVertex(Vertex *vertex) override;

    virtual size_t E() const override;
};


#endif //GRAPH_DIGRAPH_H
