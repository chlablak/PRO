//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H


#include <vector>
#include "IGraph.h"
#include "Vertex.h"

class GraphCommon : public IGraph {
private:
    vector<Vertex> vertices;
    vector<Edge> edges;
    vector<list<Edge*>> adjacentList;

public:
    GraphCommon(const vector<Vertex>& vertices, const vector<Edge>& edges) {}
    virtual bool isEmpty() const;
    virtual bool isSimple() const = 0;
    virtual bool isConnected() const = 0;
    virtual bool isStronglyConnected() const = 0;
    virtual bool isDirected() const = 0;
    virtual bool isNegativeWeighted() const;
    virtual bool isPlanar() const;
    virtual std::list<Vertex> getVertices() const;
    virtual std::list<Edge> getEdges() const;
    virtual void ponderate(std::list<Edge> edges, double weight);
    virtual void ponderateEdges(double weight);
    virtual void ponderate(std::list<Vertex> vertices, double weight);
    virtual void addEdge(Edge e);
    virtual void addVertex(Vertex v);
    virtual void removeEdge(Edge e);
    virtual void removeVertex(Vertex v);
    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPHCOMMON_H
