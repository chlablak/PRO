//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <vector>
#include "IGraph.h"
#include "Edge.h"

class Graph : public IGraph<Edge>
{

public:
    Graph() : IGraph() { }
    Graph(const Graph &g);
    Graph(vector<Vertex*> &vertices) : IGraph(vertices) { }
    Graph(vector<Vertex*> &vertices, vector<Edge*> &edges);

    ~Graph();

    virtual bool isSimple() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual void addEdge(Edge *e) override;

    virtual void removeVertex(Vertex *vertex) override;

    virtual void removeEdge(Edge *edge) override;

    virtual bool isConnected() const override;

    virtual size_t E() const override;

    virtual IGraph<Edge>::Edges edgeList() const override;

    virtual Edge* getEdge(Vertex *either, Vertex *other) const override;

    virtual Graph *clone() const override;

    virtual void assignEdge(Edge *e) override;

    virtual Graph* accept(Visitor *v, Vertex *from) override {
        return v->visit(this, from);
    }




//    virtual void accept(Visitor *v, Vertex *from) override {
//        v->visit(this, from);
//    }
};


#endif //GRAPH_GRAPH_H
