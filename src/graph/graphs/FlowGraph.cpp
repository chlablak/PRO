//
// Created by sebri on 24.04.2016.
//

#include "FlowGraph.h"

IGraph *FlowGraph::emptyClone() const {
    FlowGraph *g = new FlowGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

FlowGraph::FlowGraph(const FlowGraph &fg) : DiGraphCommon(fg) { }

FlowGraph *FlowGraph::clone() const {
    return new FlowGraph(*this);
}

bool FlowGraph::hasPositiveCapacity() const {
    for (IEdge *ie : edgeList()) {
        FlowEdge *fe = (FlowEdge*)ie;
        if (fe->maxCapacity() < 0) {
            return false;
        }
    }

    return true;
}

void FlowGraph::accept(Visitor *v, Vertex *from, Vertex *to) {
    v->visit(this, from, to);
}

IEdge *FlowGraph::createEdge(Vertex *v, Vertex *w) const {
    return new FlowEdge(v, w);
}







