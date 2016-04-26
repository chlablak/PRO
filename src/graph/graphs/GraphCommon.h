//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H


#include <vector>
#include "IGraph.h"
#include "Vertex.h"

using  namespace std;

class GraphCommon : public IGraph {
protected:

    typedef list<Edge*> edges;
    vector<Vertex> vertices;
    vector<Edge> edges;
    vector<edges> adjacentList;

public:
    GraphCommon(const vector<Vertex>& vertices, const vector<Edge>& edges);
    virtual bool isEmpty() const;
    virtual bool isSimple() const = 0;
    virtual bool isConnected() const = 0;
    virtual bool isStronglyConnected() const = 0;
    virtual bool isDirected() const = 0;
    virtual bool isNegativeWeighted() const;
    virtual bool isPlanar() const;
    virtual edges getVertices() const;
    virtual edges getEdges() const;
    virtual vector<edges> getAdjacentList(vertex v) const;
    virtual vector<edges> getAdjacentList() const;
    virtual void ponderate(edges edges, double weight);
    virtual void ponderateEdges(double weight);
    virtual void ponderate(std::list<Vertex> vertices, double weight);
    virtual void addEdge(Edge e);
    virtual void addVertex(Vertex v);
    virtual void removeEdge(Edge e);
    virtual void removeVertex(Vertex v);
    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPHCOMMON_H
