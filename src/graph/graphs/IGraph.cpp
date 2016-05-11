////
//// Created by sebri on 24.04.2016.
////
//
//#ifndef IGRAPH_CPP
//#define IGRAPH_CPP
//
//#include <list>
//#include <algorithm>
//#include <iostream>
//#include "IGraph.h"
//
///**
// * Assign a unique ID inside this class for each vertex
// */
//template <typename T>
//void IGraph<T>::computeId(vector<Vertex*> &result, vector<Vertex> &table) {
//    for (Vertex v : table) {
//        v.setId(result.size());
//        result.push_back(&v);
//    }
//}
//
///**
// * Constructs a graph only with vertices
// */
//template <typename T>
//IGraph<T>::IGraph(vector<Vertex> &vertices)
//        : _edgeId(0), _adjacentList(vertices.size()) {
//    computeId(_vertices, vertices);
//}
//
///**
// * Construct a graph with both vertices and edges
// */
//template <typename T>
//IGraph<T>::IGraph(vector<Vertex> &vertices, vector<T> &edges)
//        : _edgeId(0), _adjacentList(vertices.size()) {
//    computeId(_vertices, vertices);
//    fillAdjacentList(edges);
//}
//
//template <typename T>
//bool IGraph<T>::isNull() const {
//    return _vertices.size() == 0;
//}
//
///**
// *
// */
//template <typename T>
//bool IGraph<T>::isEmpty() const {
//    if(!isNull())
//        for(size_t i = 0; i < _adjacentList.size(); ++i)
//            if(_adjacentList.at(i).size() > 0)
//                return false;
//    return true;
//}
//
///**
// * A graph is negative weighted if at least one of his Edge
// * has a negative weight
// */
//template <typename T>
//bool IGraph<T>::isNegativeWeighted() const {
//    if(!isEmpty())
//        for(T* edge : edgeList())
//            if(edge->weight() < 0)
//                return true;
//    return false;
//}
//
///**
// * A planar graph can be draw on a sheet without having
// * intersections with edges
// */
//template <typename T>
//bool IGraph<T>::isPlanar() const {
//    // The graph need to be simple and connected
//    if (!isSimple() || !isConnected())
//        return false;
//
//    size_t n = _vertices.size();
//    if (n < 3)
//        return true;
//
//    return E() <= 3*n - 6;
//}
//
///**
// * fill the adjacentList after assigning an unique id to each edge
// */
//template <typename T>
// void IGraph<T>::fillAdjacentList(const vector<T>& edges){
//    for(T edge : edges){
//        addEdge(edge);
//        /*
//        for(Vertex* vertex : _vertices){
//            if (vertex == edge.either()) {
//                _adjacentList.at(vertex->id()).push_back(&edge);
//                continue;
//            }
//            if(vertex == edge.other(*edge.either())) {
//                _adjacentList.at(vertex->id()).push_back(&edge);
//            }
//
//        }
//         */
//    }
//}
//
///**
// * return the list of vertex of the graph
// */
//template <typename T>
//typename IGraph<T>::vertices IGraph<T>::vertexList() const {
//    vertices list;
//    for(Vertex* vertex : _vertices)
//        list.push_back(vertex); // decider si la modificaion des vertex à l'exterieur du graph doit affecter le graph
//    return list;
//}
//
///**
// * return the list of edges of the graph
// */
//template <typename T>
//typename IGraph<T>::edges IGraph<T>::edgeList() const {
//    edges list;
//    bool alreadyInside;
//    for(size_t i = 0; i<_adjacentList.size(); ++i){
//        for(T* e1 : _adjacentList.at(i)){
//            alreadyInside = false;
//            for(T* e2 : list){
//                if(*e1 == e2) {
//                    alreadyInside = true;
//                    break;
//                }
//            }
//            if(!alreadyInside) {
//                list.push_back(e1); // decider si la modificaion des edges à l'exterieur du graph doit affecter le graph
//            }
//        }
//    }
//    return list;
//}
//
///**
// * return the edge list adjacent to vertex in the graph
// */
//template <typename T>
//typename IGraph<T>::edges IGraph<T>::adjacentEdges(const Vertex *vertex) const {
//    return _adjacentList.at(vertex->id());
//}
//
///**
// * return the adjacentList of the graph
// */
//template <typename T>
//vector<list<T*>> IGraph<T>::adjacentList() const {
//    return _adjacentList;
//}
//
///**
// * assigned a weight to each vertex of the graph
// */
//template <typename T>
//void IGraph<T>::ponderateVertices(const double &weight) {
//    for (Vertex* v: _vertices) {
//        v->setWeight(weight);
//    }
//}
//
///**
// * assigned a weight to each edge of the graph
// */
//template <typename T>
//void IGraph<T>::ponderateEdges(const double &weight) {
//   for(size_t  i = 0; i < _adjacentList.size(); ++i)
//       for(T* edge : _adjacentList.at(i))
//           if(edge->weight() != weight)
//               edge->setWeight(weight);
//}
//
///**
// * add a vertex to the graph
// */
//template <typename T>
//void IGraph<T>::addVertex(Vertex &vertex) {
//    vertex.setId(_vertices.size());
//    _vertices.push_back(&vertex);
//    _adjacentList.resize(_vertices.size());
//}
//
////template <typename T>
////void IGraph<T>::removeVertex(Vertex &vertex) {
////
////    // TODO
////    // First remove all concerned edges from the adjacent list
////
////
////    // Then, remove the vertex
////
////    /*
////    if(_adjacentList.at(vertex.id()).size() > 0)
////        throw new string("Error : the vertex is link to other edge, you should delete them first");
////    bool isFind = false;
////    int curentId = 0;
////    for(vector<Vertex>::iterator it = _vertices.begin(); it<_vertices.end(); ++it){
////
////        if(it->operator==(&vertex)){
////            isFind = true;
////            continue;
////        }
////        if(isFind) {
////            curentId = it->id() - 1;
////            it->setId(curentId);
////        }
////    }
////   _vertices.erase(_vertices.begin() + vertex.id());
////     */
////}
//
//template <typename T>
//int IGraph<T>::V() const {
//    return _vertices.size();
//}
//
///**
// *
// */
//template <typename T>
//IGraph<T>::~IGraph() {
//
//}
//
//template <typename T>
//int IGraph<T>::E() const {
//    return _edgeId;
//}
//
//#endif