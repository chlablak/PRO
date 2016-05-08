//
// Created by sebri on 18.04.2016.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <list>
#include <vector>
#include "Edge.h"

class Visitor;

class IGraph {
public:

    typedef list<Edge *> edges;
    typedef list<Vertex *> vertices;

    virtual ~IGraph() { }

    virtual bool isNull() const = 0;

    virtual bool isEmpty() const = 0;

    virtual bool isSimple() const = 0;

    virtual bool isConnected() const = 0;

    virtual bool isStronglyConnected() const = 0;

    virtual bool isDirected() const = 0;

    virtual bool isNegativeWeighted() const = 0;

    virtual bool isPlanar() const = 0;
    virtual vertices vertexList() const = 0;
    virtual edges edgeList() const = 0;

    // Return the number of vertex
    virtual int V() const = 0;

    virtual IGraph::edges adjacentEdges(const Vertex* vertex) const = 0;
    virtual vector<edges> adjacentList() const = 0;

    virtual void ponderateEdges(const double &weight) = 0;

    virtual void pondeateVertices(const double &weight) = 0;

    virtual void addEdge(const Edge &e) = 0;

    virtual void addVertex(Vertex &vertex) = 0;

    virtual void removeEdge(Edge &edge) = 0;

    virtual void removeVertex(Vertex &vertex) = 0;
    //virtual void accept(const Visitor& v);

    /*template<typename Func>
    void forEachAdjacentVertex(const Vertex &v, Func f);*/
};

#endif //GRAPH_IGRAPH_H
