//
// Created by sebri on 24.04.2016.
//

#include "GraphCommon.h"



/**
 * fonction permettant d'initialiser la liste adgecente à partir des vertex et des edges
 */
void GraphCommon::fillAdjacentList() {
    for(vector<Vertex*>::iterator vertexIt = _vertices.begin(); vertexIt != _vertices.end(); ++vertexIt ){
        /* pour chaque edge du graphe vérifier si l'une de ses extremités correspond au vertex courant*/
        for(vector<Edge*>::iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt){
            if(((*edgeIt)->either()->id() == (*vertexIt)->id()) || ((*edgeIt)->other((*edgeIt)->either())->id() == (*vertexIt)->id()))
                _adjacentList.at((*vertexIt)->id()).push_back(*edgeIt); // ajouter ce edge dans liste des edges adjacents du vertex courant

        }
    }
}


void GraphCommon::ponderate(IGraph::vertices &_vertices, const double &_weight) {
    for(Graph::vertices::iterator vertexIt = _vertices.begin(); vertexIt!= _vertices.end(); ++vertexIt )
        (*vertexIt)->setWeight(_weight);
}

void GraphCommon::ponderateEdges(const double &_weight) {
for(vector<Edge*>::iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt)
    (*edgeIt)->setWeight(_weight);
}

void GraphCommon::ponderate(IGraph::edges &_edges, const double &_weight) {
    for(Graph::edges::iterator edgeIt = _edges.begin(); edgeIt!= _edges.end(); ++edgeIt )
        (*edgeIt)->setWeight(_weight);
}

vector<IGraph::edges> GraphCommon::adjacentList() const {
    return _adjacentList;
}

virtual IGraph::edges GraphCommon::adjacentList(const Vertex* _vertex) const{
     return _adjacentList.at(_vertex->id());

}

unsigned int GraphCommon::edgeId() {
    return _edgeid++;
}

unsigned int GraphCommon::vertexId() {
    return _vertexId++;
}

IGraph::edges GraphCommon::edgeList() const {
    IGraph::edges _edgeList;
    for(vector<Edge*>::const_iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt)
        _edgeList.push_back(*edgeIt);
    return _edgeList;
}

IGraph::vertices GraphCommon::vertexList() const {
    IGraph::vertices _vertexList;
    for(vector<Vertex*>::const_iterator vertexIt = _vertices.begin(); vertexIt != _vertices.end(); ++vertexIt)
        _vertexList.push_back(*vertexIt);
    return _vertexList;
}

bool GraphCommon::isDirected() const {
    return false;
}

bool GraphCommon::isStronglyConnected() const {
    return false;
}

bool GraphCommon::isConnected() const {
    return false;
}

bool GraphCommon::isSimple() const {
    for(vector<Edge*>::const_iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt){
        // vérifier que le graphe ne contient pas de cycle
        if( (*edgeIt)->either()->id() == (*edgeIt)->other((*edgeIt)->either())->id() )
            return false;
        for(vector<Edge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != _edges.end(); ++edgeIt2){
            // vérifier que le graphe ne contient pas d'edge parallèle
            if((((*edgeIt)->either()->id() == (*edgeIt2)->either()->id())) && ((*edgeIt)->other((*edgeIt)->either())->id() == (*edgeIt2)->other((*edgeIt2)->either())->id()))
                return false;
        }
    }
    if(!isNull())
        return false;
    return true;
}

bool GraphCommon::isEmpty() const {
    return  (_vertices.size() >= 1) && (_edges.size() == 0  );
}

bool GraphCommon::isNull() const {
    return (_vertices.size() == 0) && (_edges.size() == 0);
}

void GraphCommon::addEdge(Edge *_edge) {
    _edges.push_back(_edge);
}

void GraphCommon::addVertex(Vertex *_vertex) {
    _vertices.push_back(_vertex);
}

void GraphCommon::removeEdge(Edge *_edge) {

}

void GraphCommon::removeVertex(Vertex *_vertex) {

}

