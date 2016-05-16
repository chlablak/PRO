//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <vector>
#include "GraphCommon.h"
#include "Edge.h"

class Graph : public GraphCommon<Edge>
{
public:
    Graph() : GraphCommon() { }
    Graph(const Graph &g);
    Graph(vector<Vertex*> &vertices) : GraphCommon(vertices) { }
    Graph(vector<Vertex*> &vertices, vector<Edge*> &edges);

    ~Graph();

    virtual bool isSimple() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual void addEdge(IEdge *e) override;

    virtual void removeVertex(Vertex *v) override;

    virtual void removeEdge(IEdge *e) override;

    virtual bool isConnected() const override;

    virtual size_t E() const override;

    virtual GraphCommon<Edge>::Edges edgeList() const override;

    virtual Edge* getEdge(Vertex *either, Vertex *other) const override;

    virtual Graph* clone() const override;

    virtual Graph *emptyClone() const override;

    virtual void assignEdge(IEdge *e);

    template<typename Func>
    void forEachAdjacentVertex(Vertex *v, Func f) {
        for(IEdge *e : _adjacentList.at(v->id()) ) {
            f(e->other(v));
        }
    }

    virtual void accept(Visitor *v, Vertex *from) override;
};


#endif //GRAPH_GRAPH_H
