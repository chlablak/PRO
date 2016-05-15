//
// Created by sebri on 24.04.2016.
//

#include <algorithm>
#include "Graph.h"

Graph::Graph(const Graph &g) : GraphCommon(g) {
    for (Vertex *v : g.vertexList()) {
        _vertices.at(v->id()) = new Vertex(*v);
    }
    for (IEdge *ie : g.edgeList()) {
        Edge *e = (Edge*)ie;
        Edge *copy = new Edge(e);
        copy->setA(_vertices.at(e->vertexA()->id()));
        copy->setB(_vertices.at(e->vertexB()->id()));
        assignEdge(copy);
    }
}

/**
 * First delete edges, then automatically call the base class destructor
 */
Graph::~Graph() {
    for (IEdge *e : edgeList()) {
        delete e;
    }
}

/**
 * check wether the graph is simple or not
 * A graph is simple if it doesn't have multiple edges, or edge loop
 */
bool Graph::isSimple() const {
    if(isNull())
        return false;
    list<IEdge*> edges = edgeList();
    bool first;
    for(list<IEdge*>::const_iterator edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt){
        // check if the graph doesn't content a cycle
        if( (*edgeIt)->either()->operator==((*edgeIt)->other((*edgeIt)->either())))
            return false;
        first = true;
        for(list<IEdge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != edges.end(); ++edgeIt2){

            if(first){
                first = false;
                continue;
            }
            // check that the graph doesn't content a parallel edge or cycle
            if((((*edgeIt)->either()->operator==((*edgeIt2)->either()))) &&
                ((*edgeIt)->other((*edgeIt)->either())->operator==((*edgeIt2)->other((*edgeIt2)->either()))))
                return false;
        }
    }
    return true;
}

/**
 * add an Edge to the graph
 * NB : the user should not add an edge without add his vertex first
 */
void Graph::addEdge(IEdge *e) {
    // set edge id
    e->setId(_edgeId++);
    assignEdge((Edge*)e);
}


/**
 * remove the Edge from the graph
 */
void Graph::removeEdge(IEdge *e) {
    _adjacentList.at(e->either()->id()).remove(e);
    _adjacentList.at(e->other(e->either())->id()).remove(e);

    // Reset edge ids
    resetEdgeId();
}


bool Graph::isStronglyConnected() const {
    return isConnected();
}

bool Graph::isDirected() const {
    return false;
}

bool Graph::isConnected() const {
    // TODO sébastien
    return false;
}

void Graph::removeVertex(Vertex *v) {
    Vertex *otherVertex;
    // First remove the concerned edges from the adjacent List
    for (IEdge* e : _adjacentList.at(v->id())) {
        if (((Edge*)e)->either() == v) {
            otherVertex = ((Edge*)e)->other(v);
        } else {
            otherVertex = ((Edge*)e)->either();
        }

        // Remove edge in that other vertex
        _adjacentList.at(otherVertex->id()).remove(e);

        // Remove edge in this vertex
        _adjacentList.at(v->id()).remove(e);
    }

    _adjacentList.erase(_adjacentList.begin() + v->id());

    for (vector<Vertex*>::iterator it = _vertices.begin() + v->id() + 1; it != _vertices.end(); it++) {
        (*it)->setId( (*it)->id() - 1 );
    }
    _vertices.erase(_vertices.begin() + v->id());

    resetEdgeId();
}

Graph::Graph(vector<Vertex *> &vertices, vector<Edge *> &edges)
        : GraphCommon(vertices) {
    for (Edge* e : edges) {
        addEdge(e);
    }
}

size_t Graph::E() const {
    return edgeList().size();
}

GraphCommon<Edge>::Edges Graph::edgeList() const {
    Edges list;
    bool alreadyInside;
    for(size_t i = 0; i<_adjacentList.size(); ++i){
        for(IEdge* e1 : _adjacentList.at(i)){
            alreadyInside = false;
            for(IEdge* e2 : list){
                if(e1 == e2) {
                    alreadyInside = true;
                    break;
                }
            }
            if(!alreadyInside) {
                list.push_back(e1);
            }
        }
    }
    return list;
}

Edge* Graph::getEdge(Vertex *either, Vertex *other) const {
    for (IEdge *e : _adjacentList.at(either->id())) {
        if (e->other(either) == other) {
            return (Edge*)e;
        }
    }
    return nullptr;
}

Graph* Graph::clone() const {
    return new Graph(*this);
}

void Graph::assignEdge(IEdge *e) {
    _adjacentList.at(e->either()->id()).push_back(e);
    if (e->either() != e->other(e->either())) {
        _adjacentList.at(e->other(e->either())->id()).push_back(e);
    }
}

void Graph::accept(Visitor *v, Vertex *from) {
    v->visit(this, from);
}

Graph *Graph::emptyClone() const {
    Graph *g = new Graph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}






















