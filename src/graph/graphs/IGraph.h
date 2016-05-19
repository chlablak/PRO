//
// Created by sebri on 12.05.2016.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <list>
#include <vector>
#include "IEdge.h"
#include "../algorithms/Visitor.h"

class IGraph {
public:
    typedef list<IEdge*> Edges;
    typedef list<Vertex*> Vertices;

    virtual ~IGraph() {}

    /*! \brief A graph is null if there isn't any vertex
     *
     * \return true if the graph is null
     */
    virtual bool isNull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isWeighted() const = 0;
    virtual bool isNegativeWeighted() const = 0;
    virtual bool isPlanar() const = 0;
    virtual Vertices vertexList() const = 0;
    virtual Edges edgeList() const = 0;
    virtual Edges adjacentEdges(const Vertex* v) const = 0;
    virtual vector<Edges> adjacentList() const = 0;
    virtual void ponderateEdges(const double w) = 0;
    virtual void ponderateVertices(const double w) = 0;
    virtual void addVertex(Vertex *v) = 0;
    virtual size_t V() const = 0;
    virtual size_t E() const = 0;
    virtual bool isSimple() const = 0;
    virtual bool isConnected() const = 0;
    virtual bool isStronglyConnected() const = 0;
    virtual bool isDirected() const = 0;
    virtual void addEdge(IEdge *e) = 0;
    virtual void removeEdge(IEdge *e) = 0;
    virtual void removeVertex(Vertex *v) = 0;
    virtual IEdge* getEdge(Vertex *v1, Vertex *v2) const = 0;
    virtual IGraph* clone() const = 0;
    virtual IGraph* emptyClone() const = 0;
    virtual void assignVertex(Vertex *v) = 0;
    virtual void assignEdge(IEdge *e) = 0;
    virtual void print() const = 0;

    // virtual IGraph* bfs(IGraph *g, Vertex *from, vector<int> *distances) = 0;

    virtual void accept(Visitor *v, Vertex *from) = 0;
};


#endif //GRAPH_IGRAPH_H
