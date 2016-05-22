//
// Created by PatrickDesle on 16.05.2016.
//

#include "DiGraphCommon.h"

template<typename T>
DiGraphCommon<T>::DiGraphCommon(const DiGraphCommon &g) : GraphCommon<T>::GraphCommon(g) {
    for (Vertex *v : g.vertexList()) {
        this->_vertices.at(v->id()) = new Vertex(*v);
    }
    for (IEdge *ie : g.edgeList()) {
        T *e = (T*)ie;
        T *copy = new T(*e);
        copy->setA(this->_vertices.at(e->vertexA()->id()));
        copy->setB(this->_vertices.at(e->vertexB()->id()));
        assignEdge(copy);
    }
}

template<typename T>
DiGraphCommon<T>::~DiGraphCommon() {
    for (IEdge *e : edgeList()) {
        delete e;
    }
}

template<typename T>
bool DiGraphCommon<T>::isSimple() const {
    if(this->isNull())
        return false;
    list<IEdge*> edges = edgeList();
    bool first;
    for(list<IEdge*>::const_iterator edgeIt = edgeList().begin(); edgeIt != edgeList().end(); ++edgeIt){
        // check if the graph doesn't content a cycle
        DiEdgeCommon *de = (DiEdgeCommon*)*edgeIt;
        if( de->from()->operator==(de->to()))
            return false;
        first = true;
        for(list<IEdge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != edgeList().end(); ++edgeIt2){

            if(first){
                first = false;
                continue;
            }

            DiEdgeCommon *de2 = (DiEdgeCommon*)*edgeIt2;
            // check that the graph doesn't content a parallel edge or cycle
            if(((de2->from()->operator==(de2->from()))) &&
               ((de2->to()->operator==(de2->to()))))
                return false;
        }
    }
    return true;
}

template<typename T>
bool DiGraphCommon<T>::isConnected() const {
    // TODO
    return false;
}

template<typename T>
bool DiGraphCommon<T>::isStronglyConnected() const {
    // TODO
    return false;
}

template<typename T>
bool DiGraphCommon<T>::isDirected() const {
    return true;
}

template<typename T>
typename IGraph::Edges DiGraphCommon<T>::edgeList() const {
    IGraph::Edges list;
    for(size_t i = 0; i<this->_adjacentList.size(); ++i){
        for(IEdge* e1 : this->_adjacentList.at(i)){
            list.push_back(e1);
        }
    }
    return list;
}

template<typename T>
void DiGraphCommon<T>::addEdge(IEdge *e) {
    e->setId(this->_edgeId++);
    assignEdge((T*)e);
}

/**
 *  this->_adjacentList.erase(this->_adjacentList.begin() + v->id());

    for (vector<Vertex *>::iterator itVertex = this->_vertices.begin() + v->id(); itVertex != this->_vertices.end(); ++itVertex) {
        (*itVertex)->setId((*itVertex)->id());
    }
    this->_vertices.erase(this->_vertices.begin() + v->id());
    this->resetEdgeId();
 */
template<typename T>
void DiGraphCommon<T>::removeVertex(Vertex *v) {

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

    for (vector<Vertex*>::iterator it = this->_vertices.begin() + v->id() + 1; it != this->_vertices.end(); it++) {
        (*it)->setId( (*it)->id() - 1 );
    }
    this->_vertices.erase(this->_vertices.begin() + v->id());

    GraphCommon<T>::resetEdgeId();

    delete v;
}

template<typename T>
void DiGraphCommon<T>::removeEdge(IEdge *e) {
    this->_adjacentList.at(((T*)e)->from()->id()).remove(e);
    this->resetEdgeId();
}

template<typename T>
size_t DiGraphCommon<T>::E() const {
    return this->_edgeId;
}

template<typename T>
void DiGraphCommon<T>::assignEdge(IEdge *ie) {
    T *e = (T*)ie;
    this->_adjacentList.at(e->from()->id()).push_back(e);
}

template<typename T>
IGraph::Edges DiGraphCommon<T>::getEdges(Vertex *from, Vertex *to) const {
    std::list<IEdge*> edges;
    for (IEdge *ie : this->_adjacentList.at(from->id())) {
        T *e = (T*)ie;
        if (e->to() == to) {
            edges.push_back(e);
        }
    }
    return edges;
}

