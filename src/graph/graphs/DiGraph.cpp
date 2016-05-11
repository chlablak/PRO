//
// Created by sebri on 24.04.2016.
//

#include "DiGraph.h"

// TODO patrick

DiGraph::DiGraph(vector<Vertex*> &vertices, vector<DiEdge*> &edges) : IGraph(vertices) {

}

bool DiGraph::isSimple() const {
    return false;
}

bool DiGraph::isConnected() const {
    return false;
}

bool DiGraph::isStronglyConnected() const {
    return false;
}

bool DiGraph::isDirected() const {
    return true;
}

IGraph<DiEdge>::Edges DiGraph::edgeList() const {
    return std::list<DiEdge *>();
}

void DiGraph::addEdge(DiEdge *e) {

}

void DiGraph::removeEdge(DiEdge *edge) {

}

void DiGraph::removeVertex(Vertex *vertex) {

}

size_t DiGraph::E() const {
    return 0;
}

DiGraph::~DiGraph() {
    for (DiEdge *e : edgeList()) {
        delete e;
    }
}










