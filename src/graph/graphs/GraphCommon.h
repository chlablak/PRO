//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "IEdge.h"
#include "../visitors/Visitor.h"
#include "IGraph.h"

using namespace std;

template <typename T> // Type of Edges, for example Edge or DiEdge or FlowEdge
class GraphCommon : public IGraph
{

private:
    void computeId(vector<Vertex*> &result, vector<Vertex*> &table);

protected:
    // Give access to sub-classes
    vector<Vertex*> _vertices;
    size_t _edgeId;
    vector<Edges> _adjacentList;

    virtual void resetEdgeId();

public:
    GraphCommon() : _edgeId(0), _vertices(0), _adjacentList(0) { }
    GraphCommon(vector<Vertex*> &vertices);
    GraphCommon(const GraphCommon &g);
    virtual ~GraphCommon();

    bool isNull() const;
    bool isEmpty() const;
    bool isNegativeWeighted() const;
    bool isPlanar() const;
    virtual GraphCommon<T>::Vertices vertexList() const;
    virtual GraphCommon<T>::Edges adjacentEdges(const Vertex* v) const;
    virtual vector<Edges> adjacentList() const;
    void ponderateEdges(const double w);
    void ponderateVertices(const double w);
    void addVertex(Vertex *vertex);
    size_t V() const;
    void assignVertex(Vertex *v);

    template<typename Func>
    void forEachVertex(Func f) {
        for (Vertex* v : _vertices) {
            f(v);
        }
    }

    virtual void print() const override {
        if (this != nullptr) {
            cout << *this << endl;
        }
    }


    friend ostream& operator<<(ostream& os, const GraphCommon<T>& g) {
        for (Vertex *v : g.vertexList()) {
            os << *v << endl;
        }
        for (IEdge* e : g.edgeList()) {
            os << *(T*)e << endl;
        }
        return os;
    }
};


#include "GraphCommon.cpp"

#endif //GRAPH_GRAPHCOMMON_H
