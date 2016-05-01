//
// Created by sebri on 18.04.2016.
//

#ifndef GRAPH_IGRAPH_H
#define GRAPH_IGRAPH_H

#include <list>
#include "Edge.h" // contains Vertex.h
#include "../visitor/Visitor.h"

class IGraph {
public:

    typedef list<Edge*> edges;
    typedef list<Vertex*> vertices;

    virtual ~IGraph(){}


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
    virtual unsigned int vertexId() = 0;
    virtual unsigned int edgeId() = 0;
    virtual IGraph::edges adjacentList(const Vertex* _vertex) const;
    virtual vector<edges> adjacentList() const;
    virtual void ponderate(edges& _edges, const double& _weight) = 0;
    virtual void ponderateEdges(const double& _weight) = 0;
    virtual void ponderate(vertices& _vertices, const double& _weight) = 0;
    virtual void addEdge(Edge* _edge) = 0;
    virtual void addVertex(Vertex* _vertex) = 0;
    virtual void removeEdge(Edge* _edge) = 0;
    virtual void removeVertex(Vertex* _vertex) = 0;
    //virtual void accept(const Visitor& v);
};

#endif //GRAPH_IGRAPH_H
