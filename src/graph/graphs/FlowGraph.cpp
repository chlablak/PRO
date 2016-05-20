//
// Created by sebri on 24.04.2016.
//

#include "FlowGraph.h"
#include "FlowEdge.h"

IGraph::Edges FlowGraph::getEdges(Vertex *v1, Vertex *v2) const {
    std::list<IEdge*> edges;
    for (IEdge *e : this->_adjacentList.at(v1->id())) {
        if (((FlowEdge*)e)->to() == v2) {
            edges.push_back((FlowEdge*)e);
        }
    }
    return edges;
}

IGraph *FlowGraph::emptyClone() const {
    FlowGraph *g = new FlowGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}