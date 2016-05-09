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
GraphCommon::GraphCommon(const vector<Vertex> &vertices) : edgeId(0), _adjacentList(vertices.size()) {
    computeId(_vertices, vertices);
    // TODO

}

/**
 * Construct a graph with both vertices and edges
 */
GraphCommon::GraphCommon(const vector<Vertex> &vertices,
                         const vector<Edge> &edges) : edgeId(0), _adjacentList(vertices.size()) {
    computeId(_vertices, vertices);
    // TODO
    fillAdjacentList(edges);

}

bool GraphCommon::isNull() const {
    return _vertices.size() == 0;
}

/**
 *
 */
bool GraphCommon::isEmpty() const {
    // TODO
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
bool GraphCommon::isNegativeWeighted() const {
    // TODO
    if(!isEmpty())
        for(Edge* edge : edgeList())
            if(edge->weight() < 0)
                return false;
    return true;
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

/**
 * fill the adjacentList after assigned an unique id to each edge
 */
 void GraphCommon::fillAdjacentList(const vector<Edge>& edges){
    for(Edge edge : edges){
        edge.setId(edgeId++);
        for(Vertex vertex : _vertices){
            Edge* tmpEdge = new Edge(edge);
            if (vertex == edge.either()) {
                _adjacentList.at(vertex.id()).push_back(tmpEdge);
                continue;
            }
            if(vertex == edge.other(*edge.either())) {
                _adjacentList.at(vertex.id()).push_back(tmpEdge);
            }

        }

    }
}
/**
 * return the list of vertex of the graph
 */

IGraph::vertices GraphCommon::vertexList() const {
    vertices list;
    for(Vertex vertex : _vertices)
        list.push_back(new Vertex(vertex)); // decider si la modificaion des vertex à l'exterieur du graph doit affecter le graph
    return list;
}

/**
 * return the list of edges of the graph
 */
IGraph::edges GraphCommon::edgeList() const {
    edges list;
    bool alreadyInside;
    for(size_t i = 0; i<_adjacentList.size(); ++i){
        for(Edge* e1 : _adjacentList.at(i)){
            alreadyInside = false;
            for(Edge* e2 : list){
                if(*e1 == e2) {
                    alreadyInside = true;
                    break;
                }
            }
            if(!alreadyInside) {
                list.push_back(new Edge(*e1)); // decider si la modificaion des edges à l'exterieur du graph doit affecter le graph
            }
        }
    }
    return list;
}

/**
 * return the edges list adjacent of vertex in the graph
 */
IGraph::edges GraphCommon::adjacentEdges(const Vertex *vertex) const {
    return _adjacentList.at(vertex->id());
}

/**
 * return the adjacentList of the graph
 */
vector<IGraph::edges> GraphCommon::adjacentList() const {
    return _adjacentList;
}

/**
 * assigned a weight to each vertex of the graph
 */
void GraphCommon::pondeateVertices(const double &weight) {
    /*for(Vertex vertex : _vertices)
        vertex.setWeight(weight);*/
    /*for(vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
        it->setWeight(weight);*/
    for (int i = 0; i < _vertices.size() ; ++i) {
        _vertices.at(i).setWeight(weight);
    }
}

/**
 * assigned a weight to each edge of the graph
 */
void GraphCommon::ponderateEdges(const double &weight) {
   for(size_t  i = 0; i < _adjacentList.size(); ++i)
       for(Edge* edge : _adjacentList.at(i))
           if(edge->weight() != weight)
               edge->setWeight(weight);
}

/**
 * add a vertex to the graph
 */
void GraphCommon::addVertex(Vertex &vertex) {
    vertex.setId(_vertices.size());
    _vertices.push_back(vertex);
    _adjacentList.resize(_vertices.size());
}

void GraphCommon::removeVertex(Vertex &vertex) {


    /*vector<Vertex> tmpList;
    for(vector<Vertex>::iterator it = _vertices.begin(); it<_vertices.end(); ++it){
        if(it->operator==(&vertex)){
            isFind = true;
            continue;
        }
        if(isFind) {
            curentId = it->id() - 1;
            it->setId(curentId);
        }
        tmpList.push_back(*it);
        _vertices = tmpList;
    }*/

    if(_adjacentList.at(vertex.id()).size() > 0)
        throw new string("Error : the vertex is link to other edge, you should delete them first");
    bool isFind = false;
    int curentId = 0;
    for(vector<Vertex>::iterator it = _vertices.begin(); it<_vertices.end(); ++it){

        if(it->operator==(&vertex)){
            isFind = true;
            continue;
        }
        if(isFind) {
            curentId = it->id() - 1;
            it->setId(curentId);
        }
    }
   _vertices.erase(_vertices.begin() + vertex.id());
}


//
///**
// * Construct the adjacent list from current edges et vertices
// */
 //void GraphCommon::fillAdjacentList() {
   // Resize the vector of vertices
 //   _adjacentList.resize(_vertices.size());

   // Add the corresponding list of Edge* for each vertex
 //  for_each(_adjacentList.begin(), _adjacentList.end(), [](){
   //     for(vector<Edge&>::iterator it = _edges.begin(); it != _edges.end(); ++it){
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





