/*! \brief Common class for directed graphs
 *
 * \file DiGraphCommon.hpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "DiGraphCommon.h"
#include "../algorithms/GraphAlgorithm.h"
#include "DiGraph.h"

template<typename T>
DiGraphCommon<T>::DiGraphCommon(const DiGraphCommon &g)
        : GraphCommon<T>::GraphCommon(g)
{
    for (Vertex *v : g.vertexList())
        this->_vertices.at(v->id()) = new Vertex(*v);

    for (IEdge *ie : g.edgeList()) {
        T *e = (T*)ie;
        T *copy = new T(*e);
        copy->setA(this->_vertices.at(e->from()->id()));
        copy->setB(this->_vertices.at(e->to()->id()));
        assignEdge(copy);
    }
}

template<typename T>
bool DiGraphCommon<T>::isSimple() const
{
    if(this->isNull() || this->isEmpty())
        return true;

    list<IEdge*> edgeList = this->edgeList();
    bool first = false;

    // Let's search for multiple directed edges and loops through the edge list
    IGraph::Edges::iterator it = edgeList.begin();
    while (it != edgeList.end()) {

        // Search for edgeloop
        if (*(*it)->from() == *(*it)->to())
            return false;

        // Search for multiple directed edges
        first = true;
        for (IGraph::Edges::const_iterator it2 = it; it2 != edgeList.end(); ++it2) {
            if (first) {
                first = false;
                continue;
            }
            if (*(*it)->from() == *(*it2)->from() && *(*it)->to() == *(*it2)->to())
                return false;
        }
        it++;
    }

    return true;
}

template<typename T>
bool DiGraphCommon<T>::isDirected() const
{
    return true;
}

template<typename T>
void DiGraphCommon<T>::removeVertex(Vertex *v)
{

    // Remove all edges that are connected to v
    for (size_t i = 0; i < this->V(); ++i) {
        for (list<IEdge*>::iterator it = this->_adjacentList.at(i).begin(); it != this->_adjacentList.at(i).end(); it++ ) {
            T *eTo = (T*)*it;
            if ( eTo->to() == v) {
                list<IEdge*>::iterator temp = it;
                it--;
                this->_adjacentList.at(i).erase(temp);
            }
        }
    }

    // Remove all edges from v
    this->_adjacentList.erase(this->_adjacentList.begin() + v->id());

    for (vector<Vertex*>::iterator it = this->_vertices.begin() + v->id() + 1; it != this->_vertices.end(); it++)
        (*it)->setId( (*it)->id() - 1 );

    this->_vertices.erase(this->_vertices.begin() + v->id());
    GraphCommon<T>::resetEdgeId();

    delete v;
}

template<typename T>
void DiGraphCommon<T>::removeEdge(IEdge *e)
{
    this->_adjacentList.at(((T*)e)->from()->id()).remove(e);
    this->resetEdgeId();
}

template<typename T>
void DiGraphCommon<T>::addEdge(IEdge *e) {
    e->setId(this->_edgeId++);
    assignEdge((T*)e);
}

template<typename T>
void DiGraphCommon<T>::assignEdge(IEdge *ie)
{
    T *e = (T*)ie;
    this->_adjacentList.at(e->from()->id()).push_back(e);
}

template<typename T>
IGraph::Edges DiGraphCommon<T>::getEdges(Vertex *from, Vertex *to) const
{
    std::list<IEdge*> edges;
    for (IEdge *ie : this->_adjacentList.at(from->id())) {
        T *e = (T*)ie;
        if (e->to() == to)
            edges.push_back(e);
    }
    return edges;
}

template<typename T>
DiGraphCommon<T>::DiGraphCommon(vector<Vertex *> &vertices,
                             vector<IEdge *> &edges)
        : GraphCommon<T>::GraphCommon(vertices)
{
    for (IEdge* ie: edges)
        addEdge((T*)ie);
}


