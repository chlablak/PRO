/*! \brief Common class for graphs
 *
 * \file GraphCommon.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef IGRAPH_CPP
#define IGRAPH_CPP

#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "GraphCommon.h"

template <typename T>
GraphCommon<T>::GraphCommon(vector<Vertex*> &vertices)
        : _adjacentList(vertices.size()), _edgeId(0), _vertices()
{
    computeId(_vertices, vertices);
}

template <typename T>
void GraphCommon<T>::computeId(vector<Vertex*> &result, vector<Vertex*> &table)
{
    for (Vertex* v : table) {
        v->setId(result.size());
        result.push_back(v);
    }
}

template <typename T>
GraphCommon<T>::~GraphCommon()
{
    for (Vertex *v : _vertices)
        delete v;
    for (IEdge *e : edgeList())
        delete e;
}

template <typename T>
bool GraphCommon<T>::isNull() const
{
    return _vertices.size() == 0;
}

template <typename T>
bool GraphCommon<T>::isEmpty() const
{
    if (!isNull())
        for (size_t i = 0; i < _adjacentList.size(); ++i)
            if (_adjacentList.at(i).size() > 0)
                return false;
    return true;
}

template <typename T>
bool GraphCommon<T>::isNegativeWeighted() const
{
    if (!isEmpty())
        for (IEdge* edge : edgeList())
            if (edge->weight() < 0)
                return true;
    return false;
}

template <typename T>
bool GraphCommon<T>::isPlanar() const
{
    if (!isSimple() || !isConnected())
        return false;

    size_t n = _vertices.size();
    if (n < 3)
        return true;

    return E() <= 3*n - 6;
}

template <typename T>
typename GraphCommon<T>::Edges GraphCommon<T>::edgeList() const
{
    std::unordered_set<IEdge*> s;

    size_t adjListSize = _adjacentList.size();
    for (size_t i = 0; i < adjListSize; ++i)
        for (IEdge *ie : _adjacentList.at(i))
            s.insert((T*)ie);

    IGraph::Edges l;
    for (IEdge *ie : s)
        l.push_back(ie);

    return l;
}

template <typename T>
typename GraphCommon<T>::Vertices GraphCommon<T>::vertexList() const
{
    Vertices list;
    for (Vertex* vertex : _vertices)
        if (vertex)
            list.push_back(vertex);
    return list;
}

template <typename T>
typename GraphCommon<T>::Edges GraphCommon<T>::adjacentEdges(const Vertex *v) const
{
    return _adjacentList.at(v->id());
}

template <typename T>
vector<list<IEdge*>> GraphCommon<T>::adjacentList() const
{
    return _adjacentList;
}

template <typename T>
void GraphCommon<T>::ponderateVertices(const double w)
{
    for (Vertex* v: _vertices)
        v->setWeight(w);
}

template <typename T>
void GraphCommon<T>::ponderateEdges(const double w)
{
   for (size_t  i = 0; i < _adjacentList.size(); ++i)
       for (IEdge* edge : _adjacentList.at(i))
           if (edge->weight() != w)
               edge->setWeight(w);
}

template <typename T>
void GraphCommon<T>::addVertex(Vertex *v)
{
    v->setId(_vertices.size());
    _vertices.push_back(v);
    _adjacentList.resize(_vertices.size());
}

template <typename T>
Vertex *GraphCommon<T>::getVertex(int id) const {
    if (id < 0 || id > _vertices.size())
        throw runtime_error("Error when trying to get Vertex from its id. "
                                    "The id specified is out of range");
    return _vertices[id];
}

template <typename T>
size_t GraphCommon<T>::V() const
{
    return _vertices.size();
}

template <typename T>
size_t GraphCommon<T>::E() const
{
    return edgeList().size();
}

template <typename T>
void GraphCommon<T>::resetEdgeId()
{
    _edgeId = 0;
    for (IEdge* e : edgeList())
        e->setId(_edgeId++);
}

template <typename T>
void GraphCommon<T>::assignVertex(Vertex *v)
{
    _vertices.at(v->id()) = v;
}

template <typename T>
bool GraphCommon<T>::isWeighted() const
{
    for (IEdge *e : edgeList())
        if (e->weight() == numeric_limits<double>::max())
            return false;
    return true;
}

template <typename T>
void GraphCommon<T>::print() const
{
    cout << toString();
}

template <typename T>
Vertex *GraphCommon<T>::createVertex() const
{
    return new Vertex;
}

template <typename T>
string GraphCommon<T>::toString() const
{
    string s;
    for (Vertex *v : vertexList())
        if (v != nullptr)
            s.append(v->toString() + "\n");

    for (IEdge* e : edgeList())
        if (e != nullptr)
            s.append(e->toString() + "\n");

    return s;
}


#endif