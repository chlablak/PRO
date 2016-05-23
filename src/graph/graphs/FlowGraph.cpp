//
// Created by sebri on 24.04.2016.
//

#include "FlowGraph.h"
#include "FlowEdge.h"

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

void FlowGraph::accept(Visitor *v, Vertex *from) {
    v->visit(this, from);
}

IEdge *FlowGraph::createEdge(Vertex *v, Vertex *w) const {
    return new FlowEdge(v, w);
}







