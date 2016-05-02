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

///**
// * Construct the adjacent list for a non directed graph
// */
//void Graph::fillAdjacentList() {
//    // Resize the vector of vertices
//    _adjacentList.resize(_vertices.size());
//}
//
//Graph::Graph(const vector<Vertex &> vertices) {
//    GraphCommon::GraphCommon(vertices);
//    fillAdjacentList();
//}
//
//Graph::Graph(const vector<Vertex &> vertices, const vector<Edge &> edges) {
//    GraphCommon(vertices, edges);
//    fillAdjacentList();
//}
//
//bool Graph::isConnected() const {
//    // TODO
//    return false;
//}
//
//bool Graph::isStronglyConnected() const {
//    return isConnected();
//}
//
//bool Graph::isDirected() const {
//    return false;
//}
//



