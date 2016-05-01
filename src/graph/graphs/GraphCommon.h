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

private:

protected:

    virtual void fillAdjacentList();

    vector<Vertex> _vertices;
    vector<Edge> _edges;
    vector<edges> adjacentList;

public:
    GraphCommon(const vector<Vertex>& vertices)
            : _vertices(vertices), _edges(0), adjacentList(0){}
    GraphCommon(const vector<Vertex>& vertices, const vector<Edge>& edges)
            : _vertices(vertices), _edges(edges) { fillAdjacentList();  }
    virtual bool isEmpty() const;
    virtual bool isSimple() const = 0;
    virtual bool isConnected() const = 0;
    virtual bool isStronglyConnected() const = 0;
    virtual bool isDirected() const = 0;
    virtual bool isNegativeWeighted() const;
    virtual bool isPlanar() const;
    virtual vertices getVertices() const;
    virtual edges getEdges() const;
    virtual vector<edges> getAdjacentList(Vertex v) const;
    virtual vector<edges> getAdjacentList() const;
    virtual void ponderate(edges _edges, double weight);
    virtual void ponderateEdges(double weight);
    virtual void ponderate(vertices _vertices, double weight);
    virtual void addEdge(Edge e);
    virtual void addVertex(Vertex v);
    virtual void removeEdge(Edge e);
    virtual void removeVertex(Vertex v);
    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPHCOMMON_H
