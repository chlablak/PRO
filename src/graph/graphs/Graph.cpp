//
// Created by sebri on 24.04.2016.
//

#include <algorithm>
#include "Graph.h"


/**
 * First delete edges, then automatically call the base class destructor
 */
Graph::~Graph() {
    for (Edge *e : edgeList()) {
        delete e;
    }
}

/**
 * check wether the graph is simple or not
 * A graph is simple if it doesn't have multiple edges, or edge loop
 */
bool Graph::isSimple() const {
    if(IGraph<Edge>::isNull())
        return false;
    list<Edge*> edges = edgeList();
    bool first;
    for(list<Edge*>::const_iterator edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt){
        // check if the graph doesn't content a cycle
        if( (*edgeIt)->either()->operator==((*edgeIt)->other((*edgeIt)->either())))
            return false;
        first = true;
        for(list<Edge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != edges.end(); ++edgeIt2){

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
void Graph::addEdge(Edge *e) {
    // set edge id
    e->setId(_edgeId++);
    _adjacentList.at(e->either()->id()).push_back(e);
    if(e->either() != e->other(e->either())) {
        _adjacentList.at(e->other(e->either())->id()).push_back(e);
    }
}


/**
 * remove the Edge from the graph
 */
void Graph::removeEdge(Edge *edge) {
    _adjacentList.at(edge->either()->id()).remove(edge);
    _adjacentList.at(edge->other(edge->either())->id()).remove(edge);

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

void Graph::removeVertex(Vertex *vertex) {
    Vertex *otherVertex;
    // First remove the concerned edges from the adjacent List
    for (Edge* e : _adjacentList.at(vertex->id())) {
        if (e->either() == vertex) {
            otherVertex = e->other(vertex);
        } else {
            otherVertex = e->either();
        }

        // Remove edge in that other vertex
        _adjacentList.at(otherVertex->id()).remove(e);

        // Remove edge in this vertex
        _adjacentList.at(vertex->id()).remove(e);
    }

    _adjacentList.erase(_adjacentList.begin() + vertex->id());

    for (vector<Vertex*>::iterator it = _vertices.begin() + vertex->id() + 1; it != _vertices.end(); it++) {
        (*it)->setId( (*it)->id() - 1 );
    }
    _vertices.erase(_vertices.begin() + vertex->id());

    resetEdgeId();
}

Graph::Graph(vector<Vertex *> &vertices, vector<Edge *> &edges)
        : IGraph(vertices) {
    for (Edge* e : edges) {
        addEdge(e);
    }
}

size_t Graph::E() const {
    return edgeList().size();
}

IGraph<Edge>::Edges Graph::edgeList() const {
    Edges list;
    bool alreadyInside;
    for(size_t i = 0; i<_adjacentList.size(); ++i){
        for(Edge* e1 : _adjacentList.at(i)){
            alreadyInside = false;
            for(Edge* e2 : list){
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










