//
// Created by sebri on 19.05.2016.
//

#include <stdexcept>
#include "CopyToDiGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/FlowGraph.h"
#include "../graphs/FlowEdge.h"


void CopyToDiGraph::visit(Graph *g, Vertex *from) {
    UNUSED(from);

    _G = new DiGraph;

    // Copy each vertex
    for (Vertex *v : g->vertexList()) {
        _G->addVertex(new Vertex(*v));
    }

    // Transform each Edge into double opposite DiEdge, except for loop Edge
    // which are transformed into single DiEdge
    for (IEdge *ie : g->edgeList()) {
        Edge *e = (Edge *)ie;
        _G->addEdge( new DiEdge(e->either(), e->other(e->either()), e->label(), e->weight()) );
        if (e->either() != e->other(e->either())) {
            _G->addEdge( new DiEdge(e->other(e->either()), e->either(), e->label(), e->weight()) );
        }
    }
}

void CopyToDiGraph::visit(DiGraph *g, Vertex *from) {
    UNUSED(from);
    _G = g->clone();
}

void CopyToDiGraph::visit(FlowGraph *g, Vertex *from) {
    UNUSED(from);

    _G = new DiGraph;

    // Copy each vertex
    for (Vertex *v : g->vertexList()) {
        _G->addVertex(new Vertex(*v));
    }

    // Copy each edge
    for (IEdge *ie : g->edgeList()) {
        FlowEdge *fe = (FlowEdge *)ie;
        _G->addEdge( new DiEdge(fe->from(), fe->to(), fe->label(), fe->weight()) );
    }
}

IGraph *CopyToDiGraph::G() const {
    return _G;
}

std::vector<int> CopyToDiGraph::table() {
    throw std::runtime_error("No table for <CopyToDiGraph>");
}

