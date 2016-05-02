//
// Created by sebri on 24.04.2016.
//

#include <list>
#include <algorithm>
#include <iostream>
#include "GraphCommon.h"

/**
 * Assign a unique ID inside this class for each vertex
 */
template <typename T>
void GraphCommon::computeId(vector<T> &result, const vector<T> &table) {
    for (T t : table) {
        t.setId(result.size());
        result.push_back(t);
    }
}

/**
 * Constructs a graph only with vertices
 */
GraphCommon::GraphCommon(const vector<Vertex> &vertices) {
    computeId(_vertices, vertices);
    // TODO
}

/**
 * Construct a graph with both vertices and edges
 */
GraphCommon::GraphCommon(const vector<Vertex> &vertices,
                         const vector<Edge> &edges) {
    computeId(_vertices, vertices);
    // TODO
}

/**
 * A graph is empty if there isn't any vertex
 */
bool GraphCommon::isEmpty() const {
    // TODO
    return false;
}

/**
 * A graph is negative weighted if at least one of his Edge
 * has a negative weight
 */
bool GraphCommon::isNegativeWeighted() const {
    // TODO
    return false;
}

/**
 * A planar graph can be draw on a sheet without having
 * intersections with edges
 */
bool GraphCommon::isPlanar() const {
    // The graph need to be simple and connected
    if (!isSimple() || !isConnected())
        return false;

    // TODO
    size_t n = _vertices.size();
    if (n < 3)
        return true;

    return false;
    //return _edges.size() <= 3*n - 6;
}


//
///**
// * Construct the adjacent list from current edges et vertices
// */
////void GraphCommon::fillAdjacentList() {
////    // Resize the vector of vertices
////    _adjacentList.resize(_vertices.size());
////
////    // Add the corresponding list of Edge* for each vertex
////    for_each(_adjacentList.begin(), _adjacentList.end(), [](){
////        for(vector<Edge&>::iterator it = _edges.begin(); it != _edges.end(); ++it){
////            if ( (*it).either()  ) {
////                _adjacentList.at()
////            }
////        }
////    });
////
////
////    for(vector<Vertex*>::iterator vertexIt = _vertices.begin(); vertexIt != _vertices.end(); ++vertexIt ){
////        /* pour chaque edge du graphe vérifier si l'une de ses extremités correspond au vertex courant*/
////        for(vector<Edge*>::iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt){
////            if(((*edgeIt)->either()->id() == (*vertexIt)->id()) || ((*edgeIt)->other((*edgeIt)->either())->id() == (*vertexIt)->id()))
////                _adjacentList.at((*vertexIt)->id()).push_back(*edgeIt); // ajouter ce edge dans liste des edges adjacents du vertex courant
////
////        }
////    }
//}
//
//
//void GraphCommon::ponderate(IGraph::vertices &_vertices, const double &_weight) {
////    for(Graph::vertices::iterator vertexIt = _vertices.begin(); vertexIt!= _vertices.end(); ++vertexIt )
////        (*vertexIt)->setWeight(_weight);
//}
//
//void GraphCommon::ponderateEdges(const double &_weight) {
////for(vector<Edge*>::iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt)
////    (*edgeIt)->setWeight(_weight);
//}
//
//void GraphCommon::ponderate(IGraph::edges &_edges, const double &_weight) {
////    for(Graph::edges::iterator edgeIt = _edges.begin(); edgeIt!= _edges.end(); ++edgeIt )
////        (*edgeIt)->setWeight(_weight);
//}
//
//vector<IGraph::edges> GraphCommon::adjacentList() const {
////    return _adjacentList;
//}
//
//virtual IGraph::edges GraphCommon::adjacentEdges(const Vertex* _vertex) const{
////     return _adjacentList.at(_vertex->id());
//}
//
//IGraph::edges GraphCommon::edgeList() const {
////    IGraph::edges _edgeList;
////    for(vector<Edge*>::const_iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt)
////        _edgeList.push_back(*edgeIt);
////    return _edgeList;
//}
//
//IGraph::vertices GraphCommon::vertexList() const {
////    IGraph::vertices _vertexList;
////    for(vector<Vertex*>::const_iterator vertexIt = _vertices.begin(); vertexIt != _vertices.end(); ++vertexIt)
////        _vertexList.push_back(*vertexIt);
////    return _vertexList;
//}
//
//bool GraphCommon::isSimple() const {
////    for(vector<Edge*>::const_iterator edgeIt = _edges.begin(); edgeIt != _edges.end(); ++edgeIt){
////        // vérifier que le graphe ne contient pas de cycle
////        if( (*edgeIt)->either()->id() == (*edgeIt)->other((*edgeIt)->either())->id() )
////            return false;
////        for(vector<Edge*>::const_iterator edgeIt2 = edgeIt; edgeIt2 != _edges.end(); ++edgeIt2){
////            // vérifier que le graphe ne contient pas d'edge parallèle
////            if((((*edgeIt)->either()->id() == (*edgeIt2)->either()->id())) && ((*edgeIt)->other((*edgeIt)->either())->id() == (*edgeIt2)->other((*edgeIt2)->either())->id()))
////                return false;
////        }
////    }
////    if(!isNull())
////        return false;
//    return true;
//}
//
//bool GraphCommon::isEmpty() const {
////    return  (_vertices.size() >= 1) && (_edges.size() == 0  );
//}
//
//bool GraphCommon::isNull() const {
////    return (_vertices.size() == 0) && (_edges.size() == 0);
//}
//
///**
// * Define properly the index of vertices
// */
//GraphCommon::GraphCommon(const vector<Vertex> vertices) {
//    size_t size = vertices.size();
//}
//
//
//





