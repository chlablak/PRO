//
// Created by sebri on 24.04.2016.
//

#include "DiGraph.h"

DiGraph::DiGraph(const DiGraph &dg) {
    // TODO
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
    // TODO
}

size_t DiGraph::E() const {
    return 0;
}

IGraph::Edges DiGraph::getEdges(Vertex *v1, Vertex *v2) const {
    std::list<IEdge*> edges;
    for (IEdge *e : this->_adjacentList.at(v1->id())) {
        if (((DiEdge*)e)->to() == v2) {
            edges.push_back((DiEdge*)e);
        }
    }
    return edges;
}

IGraph *DiGraph::emptyClone() const {
    DiGraph *g = new DiGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

void DiGraph::assignEdge(IEdge *e) {
    // TODO
}

void DiGraph::accept(Visitor *v, Vertex *from) {
    v->visit(this, from);
}

IEdge *DiGraph::createEdge(Vertex *v, Vertex *w) const {
    return new DiEdge(v, w);
}
