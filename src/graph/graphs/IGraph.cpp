//
// Created by sebri on 24.04.2016.
//

#ifndef IGRAPH_CPP
#define IGRAPH_CPP

#include <list>
#include <algorithm>
#include <iostream>
#include "IGraph.h"

/**
 * Assign a unique ID inside this class for each vertex
 */
template <typename T>
void IGraph<T>::computeId(vector<Vertex*> &result, vector<Vertex*> &table) {
    for (Vertex* v : table) {
        v->setId(result.size());
        result.push_back(v);
    }
}

/**
 * Constructs a graph only with vertices
 */
template <typename T>
IGraph<T>::IGraph(vector<Vertex*> &vertices)
        : _edgeId(0), _adjacentList(vertices.size()) {
    computeId(_vertices, vertices);
}

/**
 *
 */
template <typename T>
IGraph<T>::~IGraph() {
    for (Vertex *v : _vertices) {
        delete v;
    }
}

template <typename T>
bool IGraph<T>::isNull() const {
    return _vertices.size() == 0;
}

/**
 *
 */
template <typename T>
bool IGraph<T>::isEmpty() const {
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
bool IGraph<T>::isNegativeWeighted() const {
    if(!isEmpty())
        for(T* edge : edgeList())
            if(edge->weight() < 0)
                return true;
    return false;
}

/**
 * A planar graph can be draw on a sheet without having
 * intersections with edges
 */
template <typename T>
bool IGraph<T>::isPlanar() const {
    // The graph need to be simple and connected
    if (!isSimple() || !isConnected())
        return false;

    size_t n = _vertices.size();
    if (n < 3)
        return true;

    return E() <= 3*n - 6;
}

/**
 * return the list of vertex of the graph
 */
template <typename T>
typename IGraph<T>::Vertices IGraph<T>::vertexList() const {
    Vertices list;
    for(Vertex* vertex : _vertices)
        list.push_back(vertex);
    return list;
}

/**
 * return the edge list adjacent to vertex in the graph
 */
template <typename T>
typename IGraph<T>::Edges IGraph<T>::adjacentEdges(const Vertex *vertex) const {
    return _adjacentList.at(vertex->id());
}

/**
 * return the adjacentList of the graph
 */
template <typename T>
vector<list<T*>> IGraph<T>::adjacentList() const {
    return _adjacentList;
}

/**
 * assigned a weight to each vertex of the graph
 */
template <typename T>
void IGraph<T>::ponderateVertices(const double &weight) {
    for (Vertex* v: _vertices) {
        v->setWeight(weight);
    }
}

template <typename T>
void IGraph<T>::ponderateCapacity(const size_t min, const size_t max) {
    for (Vertex* v: _vertices) {
        v->setMinCapacity(min);
        v->setMaxCapacitiy(max);
    }
}

/**
 * assigned a weight to each edge of the graph
 */
template <typename T>
void IGraph<T>::ponderateEdges(const double &weight) {
   for(size_t  i = 0; i < _adjacentList.size(); ++i)
       for(T* edge : _adjacentList.at(i))
           if(edge->weight() != weight)
               edge->setWeight(weight);
}

/**
 * add a vertex to the graph
 */
template <typename T>
void IGraph<T>::addVertex(Vertex *v) {
    v->setId(_vertices.size());
    _vertices.push_back(v);
    _adjacentList.resize(_vertices.size());
}

/**
 *
 */
template <typename T>
size_t IGraph<T>::V() const {
    return _vertices.size();
}

/**
 *
 */
template <typename T>
void IGraph<T>::resetEdgeId() {
    _edgeId = 0;
    for (T* e : edgeList()) {
        e->setId(_edgeId++);
    }
}

template <typename T>
IGraph<T>::IGraph(const IGraph &g) {
    _vertices.resize(g.V());
    _edgeId = g.E();
    _adjacentList.resize(g.V());
}


#endif