//
// Created by sebri on 19.05.2016.
//

#include <stdexcept>
#include "CopyToGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

void CopyToGraph::visit(Graph *g, Vertex *, Vertex *) {
    _G = g->clone();
}

void CopyToGraph::visit(DiGraph *g, Vertex *, Vertex *) {
    _G = new Graph;

    // Copy each vertex
    for (Vertex *v : g->vertexList()) {
        _G->addVertex(new Vertex(*v));
    }

    // Copy each edge
    for (IEdge *ie : g->edgeList()) {
        DiEdge *de = (DiEdge*)ie;
        _G->addEdge(new Edge(de->from(), de->to(), de->label(), de->weight()));
    }
}

void CopyToGraph::visit(FlowGraph *g, Vertex *, Vertex *) {

    _G = new Graph;

    // Copy each vertex
    for (Vertex *v : g->vertexList()) {
        _G->addVertex(new Vertex(*v));
    }

    // Copy each edge
    for (IEdge *ie : g->edgeList()) {
        FlowEdge *fe = (FlowEdge*)ie;
        _G->addEdge(new Edge(fe->from(), fe->to(), fe->label(), fe->weight()));
    }
}

IGraph *CopyToGraph::G() const {
    return _G;
}

std::vector<double> CopyToGraph::table() {
    throw std::runtime_error("Error. No table for 'CopyToGraph' algorithm.");
}

