/*! \brief Copy any type of graph into a new flow graph
 *
 * \file CopyToFlowGraph.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stdexcept>
#include "CopyToFlowGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/FlowGraph.h"
#include "../graphs/DiGraph.h"


void CopyToFlowGraph::visit(Graph *g, Vertex *, Vertex *)
{

    _G = new FlowGraph;

    // Copy each vertex
    for (Vertex *v : g->vertexList())
        _G->addVertex(new Vertex(*v));

    // Transform each Edge into double opposite DiEdge, except for loop Edge
    // which are transformed into single DiEdge
    for (IEdge *ie : g->edgeList()) {
        Edge *e = (Edge *)ie;
        _G->addEdge( new FlowEdge(e->either(), e->other(e->either()), e->label(), e->weight()) );
        if (e->either() != e->other(e->either()))
            _G->addEdge( new FlowEdge(e->other(e->either()), e->either(), e->label(), e->weight()) );
    }
}

void CopyToFlowGraph::visit(DiGraph *g, Vertex *, Vertex *)
{
    _G = new FlowGraph;

    // Copy each vertex
    for (Vertex *v : g->vertexList())
        _G->addVertex(new Vertex(*v));

    // Copy each edge
    for (IEdge *ie : g->edgeList()) {
        DiEdge *de = (DiEdge *)ie;
        _G->addEdge( new FlowEdge(de->from(), de->to(), de->label(), de->weight()) );
    }
}

void CopyToFlowGraph::visit(FlowGraph *g, Vertex *, Vertex *)
{
    _G = g->clone();
}

IGraph *CopyToFlowGraph::G() const {
    return _G;
}

std::vector<double> CopyToFlowGraph::table() {
    throw std::runtime_error("Error. No table for 'CopyToFlowGraph' algorithm.");
}


