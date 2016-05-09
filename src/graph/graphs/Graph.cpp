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
 * check weither the graph is simple or not
 */
bool Graph::isSimple()  const {
    if(GraphCommon::isNull())
    return false;
    list<Edge*> edges = GraphCommon::edgeList();
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
            // check that the graph doesn't content a parallèle edges or cycle
            if((((*edgeIt)->either()->operator==((*edgeIt2)->either()))) &&
                ((*edgeIt)->other(*(*edgeIt)->either())->operator==((*edgeIt2)->other(*(*edgeIt2)->either()))))
            return false;
        }
    }
    return true;
}

/**
 * add un Edge to the graph
 * NB : the user should not add an edge without add his vertex first
 */
void Graph::addEdge(const Edge &e) {
    // TODO ajouter 2x dans la liste d'adjacence
    Edge *tmpEdge = new Edge(e);
    tmpEdge->setId(edgeId++);
    _adjacentList.at(e.either()->id()).push_back(tmpEdge);
    if(e.either() != e.other(*e.either()))
        _adjacentList.at(e.other(*e.either())->id()).push_back(tmpEdge);
}


/**
 * remove the Edge to graph
 */
void Graph::removeEdge(Edge &edge) {
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
}




