//
// Created by sebri on 24.04.2016.
//

#include "DiGraph.h"

DiGraph::DiGraph(const DiGraph &dg) : DiGraphCommon(dg) { }

IGraph *DiGraph::emptyClone() const {
    DiGraph *g = new DiGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

void DiGraph::accept(Visitor *v, Vertex *from) {
    v->visit(this, from);
}

IEdge *DiGraph::createEdge(Vertex *v, Vertex *w) const {
    return new DiEdge(v, w);
}

DiGraph *DiGraph::clone() const {
    return new DiGraph(*this);
}


