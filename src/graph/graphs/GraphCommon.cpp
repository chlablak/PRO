//
// Created by sebri on 24.04.2016.
//

#ifndef IGRAPH_CPP
#define IGRAPH_CPP

#include <list>
#include <algorithm>
#include <iostream>
#include "GraphCommon.h"

/**
 * Assign a unique ID inside this class for each vertex
 */
template <typename T>
void GraphCommon<T>::computeId(vector<Vertex*> &result, vector<Vertex*> &table) {
    for (Vertex* v : table) {
        v->setId(result.size());
        result.push_back(v);
    }
}

/**
 * Constructs a graph only with vertices
 */
template <typename T>
GraphCommon<T>::GraphCommon(vector<Vertex*> &vertices)
        : _adjacentList(vertices.size()), _edgeId(0), _vertices() {
    computeId(_vertices, vertices);
}

/**
 *
 */
template <typename T>
GraphCommon<T>::~GraphCommon() {
    for (Vertex *v : _vertices) {
        delete v;
    }
}

template <typename T>
bool GraphCommon<T>::isNull() const {
    return _vertices.size() == 0;
}

/**
 *
 */
template <typename T>
bool GraphCommon<T>::isEmpty() const {
    if(!isNull())
        for(size_t i = 0; i < _adjacentList.size(); ++i)
            if(_adjacentList.at(i).size() > 0)
                return false;
    return true;
}

/**
 * A graph is negative weighted if at least one of his Edge
 * has a negative weight
 */
template <typename T>
bool GraphCommon<T>::isNegativeWeighted() const {
    if(!isEmpty())
        for(IEdge* edge : edgeList())
            if(edge->weight() < 0)
                return true;
    return false;
}

/**
 * A planar graph can be draw on a sheet without having
 * intersections with edges
 */
template <typename T>
bool GraphCommon<T>::isPlanar() const {
    // The graph need to be simple and connected
    if (!isSimple() || !isConnected())
        return false;

    size_t n = _vertices.size();
    if (n < 3) {
        return true;
    }

    return E() <= 3*n - 6;
}

/**
 * return the list of vertex of the graph
 */
template <typename T>
typename GraphCommon<T>::Vertices GraphCommon<T>::vertexList() const {
    Vertices list;
    for(Vertex* vertex : _vertices)
        list.push_back(vertex);
    return list;
}

/**
 * return the edge list adjacent to vertex in the graph
 */
template <typename T>
typename GraphCommon<T>::Edges GraphCommon<T>::adjacentEdges(const Vertex *v) const {
    return _adjacentList.at(v->id());
}

/**
 * return the adjacentList of the graph
 */
template <typename T>
vector<list<IEdge*>> GraphCommon<T>::adjacentList() const {
    return _adjacentList;
}

/**
 * assigned a weight to each vertex of the graph
 */
template <typename T>
void GraphCommon<T>::ponderateVertices(const double w) {
    for (Vertex* v: _vertices) {
        v->setWeight(w);
    }
}

/**
 * assigned a weight to each edge of the graph
 */
template <typename T>
void GraphCommon<T>::ponderateEdges(const double w) {
   for(size_t  i = 0; i < _adjacentList.size(); ++i)
       for(IEdge* edge : _adjacentList.at(i))
           if(edge->weight() != w)
               edge->setWeight(w);
}

template <typename T>
void GraphCommon<T>::addVertex(Vertex *v) {
    v->setId(_vertices.size());
    _vertices.push_back(v);
    _adjacentList.resize(_vertices.size());
}

/**
 *
 */
template <typename T>
size_t GraphCommon<T>::V() const {
    return _vertices.size();
}

/**
 *
 */
template <typename T>
void GraphCommon<T>::resetEdgeId() {
    _edgeId = 0;
    for (IEdge* e : edgeList()) {
        e->setId(_edgeId++);
    }
}

template <typename T>
void GraphCommon<T>::assignVertex(Vertex *v) {
    _vertices.at(v->id()) = v;
}

template <typename T>
bool GraphCommon<T>::isWeighted() const {
    for (IEdge *e : edgeList()) {
        if (e->weight() == numeric_limits<double>::max()) {
            return false;
        }
    }
    return true;
}

template <typename T>
void GraphCommon<T>::print() const {
    cout << *this << endl;
}

template <typename T>
Vertex *GraphCommon<T>::createVertex() const {
    return new Vertex;
}

template <typename T>
string GraphCommon<T>::toString() const {
    string s;
    for (Vertex *v : vertexList()) {
        if(v != nullptr) {
            s.append(v->toString() + "\n");
        }
    }
    for (IEdge* e : edgeList()) {
        if (e != nullptr) {
            s.append(e->toString() + "\n");
        }
    }
    return s;
}


#endif