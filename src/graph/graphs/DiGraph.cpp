//
// Created by sebri on 24.04.2016.
//

#include "DiGraph.h"

// TODO patrick

DiGraph::DiGraph(vector<Vertex*> &vertices, vector<DiEdge*> &edges) : GraphCommon(vertices) {

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

GraphCommon<DiEdge>::Edges DiGraph::edgeList() const {
    return std::list<IEdge *>();
}

void DiGraph::addEdge(IEdge *e) {
    //TODO caster e en DiEdge
}

void DiGraph::removeEdge(IEdge *e) {
    //TODO caster e en DiEdge
}

void DiGraph::removeVertex(Vertex *v) {

}

size_t DiGraph::E() const {
    return 0;
}

DiGraph::~DiGraph() {
    for (IEdge *e : edgeList()) {
        delete e;
    }
}










