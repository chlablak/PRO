//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPHCOMMON_H
#define GRAPH_GRAPHCOMMON_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "IEdge.h"
#include "../visitor/Visitor.h"

using namespace std;

template <typename T> // Type of Edges, for example Edge or DiEdge or FlowEdge
class IGraph
{

private:
    void computeId(vector<Vertex*> &result, vector<Vertex*> &table);

protected:
    typedef list<T*> Edges;
    typedef list<Vertex*> Vertices;

    vector<Vertex*> _vertices;
    size_t _edgeId;
    vector<Edges> _adjacentList;

    virtual void resetEdgeId();

public:
    IGraph() : _edgeId(0), _vertices(0), _adjacentList(0) { }

    IGraph(vector<Vertex*> &vertices);

    IGraph(const IGraph &g);

    virtual ~IGraph();

    /*! \brief A graph is null if there isn't any vertex
     *
     * \return true if the graph is null
     */
    bool isNull() const;

    bool isEmpty() const;

    bool isNegativeWeighted() const;

    bool isPlanar() const;

    virtual IGraph<T>::Vertices vertexList() const;

    virtual IGraph<T>::Edges adjacentEdges(const Vertex* vertex) const;

    virtual vector<Edges> adjacentList() const;

    void ponderateEdges(const double &weight);

    void ponderateVertices(const double &weight);

    void ponderateCapacity(const size_t min, const size_t max);

    void addVertex(Vertex *vertex);

    size_t V() const;

    template<typename Func>
    void forEachAdjacentVertex(Vertex *v, Func f) {
        for(T *e : _adjacentList.at(v->id()) ) {
            f(e->other(v));
        }
    }

    template<typename Func>
    void forEachVertex(Func f) {
        for (Vertex* v : _vertices) {
            f(*v);
        }
    }

    virtual bool isSimple() const = 0;

    virtual bool isConnected() const = 0; // TODO sébastien

    virtual bool isStronglyConnected() const = 0;

    virtual bool isDirected() const = 0;

    virtual Edges edgeList() const = 0;

    virtual void addEdge(T *e) = 0;

    virtual void removeEdge(T *edge) = 0;

    virtual void removeVertex(Vertex *vertex) = 0;

    virtual size_t E() const = 0;

    virtual T* getEdge(Vertex *v1, Vertex *v2) const = 0;

    virtual IGraph<T>* clone() const = 0;

    virtual void assignEdge(T *e) = 0;

    virtual IGraph<T>* accept(Visitor *v, Vertex *from) = 0;

    friend ostream& operator<<(ostream& os, const IGraph<T>& g) {
        for (Vertex *v : g.vertexList()) {
            os << *v << endl;
        }
        for (T* t : g.edgeList()) {
            os << *t << endl;
        }
        return os;
    }
};


#include "IGraph.cpp"

#endif //GRAPH_GRAPHCOMMON_H
