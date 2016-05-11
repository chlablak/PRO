//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <iostream>
#include <vector>
#include "Vertex.h"

using namespace std;

template <typename T> // Type of Edges, for example Edge or DiEdge or FlowEdge
class IGraph {

private:
    void computeId(vector<Vertex*> &result, vector<Vertex> &table);

protected:

    typedef list<T*> edges;
    typedef list<Vertex*> vertices;

    vector<Vertex*> _vertices;
    unsigned int _edgeId;
    vector<edges> _adjacentList;

    void fillAdjacentList(const vector<T>& edges);

public:
    // TODO patrick
    IGraph() : _vertices(0), _adjacentList(0) { }

    IGraph(vector<Vertex> &vertices);

    IGraph(vector<Vertex> &vertices, vector<T> &edges);
//
//    virtual ~IGraph();
//
//    bool isNull() const;
//
//    bool isEmpty() const;
//
//    virtual bool isSimple() const = 0;
//
//    virtual bool isConnected() const = 0;
//
//    virtual bool isStronglyConnected() const = 0; // TODO return isConnected() dans Graph et redéfinir dans DiGraph
//
//    virtual bool isDirected() const = 0;
//
//    bool isNegativeWeighted() const;
//
//    bool isPlanar() const;
//
//    virtual IGraph<T>::vertices vertexList() const;
//
//    virtual IGraph<T>::edges edgeList() const;
//
//    // TODO richoz
//    virtual IGraph<T>::edges adjacentEdges(const Vertex* vertex) const;
//
//    virtual vector<edges> adjacentList() const;
//
//    void ponderateEdges(const double &weight);
//
//    void ponderateVertices(const double &weight);
//
//    virtual void addEdge(T &e) = 0;
//
//    void addVertex(Vertex &vertex);
//
//    virtual void removeEdge(T &edge) = 0;
//
//    virtual void removeVertex(Vertex &vertex) = 0;
//
//    int V() const;
//
//    virtual int E() const;
//
//    template<typename Func>
//    void forEachAdjacentVertex(Vertex &v, Func f) {
//        for(T *e : _adjacentList.at(v.id()) ) {
//            f(e->other(v));
//        }
//    }
//
//    template<typename Func>
//    void forEachVertex(Func f) {
//        for (Vertex* v : _vertices) {
//            f(*v);
//        }
//    }
//    //virtual void accept(const Visitor& v);
};

#include "IGraph.cpp"

#endif //GRAPH_GRAPHCOMMON_H
