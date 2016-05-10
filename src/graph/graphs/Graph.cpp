//
// Created by sebri on 24.04.2016.
//

#include <algorithm>
#include "Graph.h"


/**
 * Delete elements in adjacentList
 */
Graph::~Graph() {
    size_t size = _adjacentList.size();
    for (size_t i = 0; i < size; ++i) {
        for (Edge* e : _adjacentList.at(i)) {
            delete e;
        }
    }
}

/**
 * check wether the graph is simple or not
 * A graph is simple if it doesn't have multiple edges, or edge loop
 */
// TODO à corriger. Test effectué sur un graphe simple, il retourne qu'il n'est pas simple.
bool Graph::isSimple() const {
    if(IGraph::isNull())
        return false;
    list<Edge*> edges = IGraph::edgeList();
    bool first;
    for(list<Edge*>::const_iterator edgeIt = edges.begin(); edgeIt != edges.end(); ++edgeIt){
        // check if the graph doesn't content a cycle
        if( (*edgeIt)->either()->operator==((*edgeIt)->other(*(*edgeIt)->either())))
            return false;
        first = true;
        for(list<Edge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != edges.end(); ++edgeIt2){

            if(first){
                first = false;
                continue;
            }
            // check that the graph doesn't content a parallel edge or cycle
            if((((*edgeIt)->either()->operator==((*edgeIt2)->either()))) &&
                ((*edgeIt)->other(*(*edgeIt)->either())->operator==((*edgeIt2)->other(*(*edgeIt2)->either()))))
                return false;
        }
    }
    return true;
}

/**
 * add an Edge to the graph
 * NB : the user should not add an edge without add his vertex first
 */
void Graph::addEdge(Edge &e) {
    // set edge id
    e.setId(_edgeId++);
    _adjacentList.at(e.either()->id()).push_back(&e);
    if(e.either() != e.other(*e.either()))
        _adjacentList.at(e.other(*e.either())->id()).push_back(&e);
}


/**
 * remove the Edge from the graph
 */
void Graph::removeEdge(Edge &edge) {
    _adjacentList.at(edge.either()->id()).remove(&edge);
    _adjacentList.at(edge.other(*edge.either())->id()).remove(&edge);
    _edgeId--;
    /*
    Edge *tmpEdge = nullptr;
    list<Edge*> eitherList, otherList;
    for(list<Edge*>::iterator it = _adjacentList.at(edge.either()->id()).begin(); it!=_adjacentList.at(edge.either()->id()).end(); ++it){
        if((*it)->operator==(&edge)){
            tmpEdge = *it;
            continue;
        }
        eitherList.push_back(*it);
    }
    if(edge.either() != edge.other(*edge.either())){
        for(list<Edge*>::iterator it = _adjacentList.at(edge.other(*edge.either())->id()).begin(); it!=_adjacentList.at(edge.other(*edge.either())->id()).end(); ++it){
            if((*it)->operator==(&edge)){
                continue;
            }
            otherList.push_back(*it);
        }
    }
    _adjacentList.at(edge.either()->id()) = eitherList;
    _adjacentList.at(edge.other(*edge.either())->id()) = otherList;
    delete tmpEdge;
     */
}


bool Graph::isStronglyConnected() const {
    return false;
}

bool Graph::isDirected() const {
    return false;
}

bool Graph::isConnected() const {
    return false;
}

void Graph::removeVertex(Vertex &vertex) {
    Vertex *otherVertex;
    // First remove the concerned edges from the adjacent List
    for (Edge* e : _adjacentList.at(vertex.id())) {
        if (e->either() == &vertex) {
            otherVertex = e->other(vertex);
        } else {
            otherVertex = e->either();
        }

        // Remove edge in that other vertex
        _adjacentList.at(otherVertex->id()).remove(e);

        // Remove edge in this vertex
        _adjacentList.at(vertex.id()).remove(e);
    }

    // Then, reorder the adjacent list and the vector table
    for (int i = vertex.id(); i < _adjacentList.size(); ++i) {
        _adjacentList.at(i) = _adjacentList.at(i+1);
        _vertices.at(i) = _vertices.at(i+1);
    }

    // Finally, remove the vertex
    _vertices.pop_back();
    _adjacentList.pop_back();
}




