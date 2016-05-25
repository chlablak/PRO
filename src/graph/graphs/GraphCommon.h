//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "IEdge.h"
#include "../algorithms/Visitor.h"
#include "IGraph.h"

using namespace std;

template <typename T> // Type of Edges, for example Edge or DiEdge or FlowEdge
class GraphCommon : public IGraph
{

private:
    void computeId(vector<Vertex*> &result, vector<Vertex*> &table);

protected:
    // Give access to sub-classes
    vector<Edges> _adjacentList;
    size_t _edgeId;
    vector<Vertex*> _vertices;

    virtual void resetEdgeId();

public:
    GraphCommon() : _adjacentList(0), _edgeId(0), _vertices(0) { }
    GraphCommon(vector<Vertex*> &vertices);
    GraphCommon(const GraphCommon &g) : _adjacentList(g.V()), _edgeId(g.E()), _vertices(g.V(), nullptr) { }
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
    virtual Vertex *createVertex() const override;

    template<typename Func>
    void forEachVertex(Func f) {
        for (Vertex* v : _vertices) {
            f(v);
        }
    }

    template <typename Func>
    void forEachEdge(Func f) {
        for (IEdge *e : edgeList()) {
            f(e);
        }
    }

    template <typename Func>
    void forEachAdjacentEdge(Vertex *v, Func f) {
        for (IEdge* e : _adjacentList.at(v->id())) {
            f(e);
        }
    }

    template <typename Func>
    void forEachAdjacentVertex(Vertex *v, Func f) {
        for (IEdge* ie : _adjacentList.at(v->id())) {
            if (ie->either() == v) {
                f(ie->other(ie->either()));
            } else {
                f(ie->either());
            }

        }
    }

    virtual void print() const override;

    virtual bool isWeighted() const override;

    virtual string toString() const override;

    friend ostream& operator<<(ostream& os, const GraphCommon<T>& g) {
        return os << g.toString();
    }

    virtual void printAdjList() const override {
        for (Vertex *v : _vertices) {
            if (v != nullptr) {
                cout << "|" << v->label() << "(" << v->id() << ") | --- ";
                for (IEdge *ie : _adjacentList.at(v->id())) {
                    cout << ie->label() << "(" << ie->id() << ") --- ";
                }
                cout << "/" << endl;
            }
        }
    }


};

#include "GraphCommon.cpp"

#endif //GRAPH_GRAPHCOMMON_H
