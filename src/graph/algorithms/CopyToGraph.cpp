/*! \brief Copy any type of graph into a new non-directed graph
 *
 * \file CopyToGraph.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stdexcept>
#include "CopyToGraph.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

template <typename T, typename U>
void CopyToGraph::common(T *g, U *)
{
    _G = new Graph;

    // Copy each vertex
    for (Vertex *v : g->vertexList())
        _G->addVertex(new Vertex(*v));

    // Copy each edge
    for (IEdge *ie : g->edgeList()) {
        U *de = (U*)ie;
        _G->addEdge(new Edge(de->from(), de->to(), de->label(), de->weight()));
    }
}

void CopyToGraph::visit(Graph *g, Vertex *, Vertex *)
{
    _G = g->clone();
}

void CopyToGraph::visit(DiGraph *g, Vertex *, Vertex *)
{
    DiEdge *e = nullptr;
    common(g, e);
}

void CopyToGraph::visit(FlowGraph *g, Vertex *, Vertex *)
{
    FlowEdge *e = nullptr;
    common(g, e);
}

IGraph *CopyToGraph::G() const
{
    return _G;
}

std::vector<double> CopyToGraph::table()
{
    throw std::runtime_error("Error. No table for 'CopyToGraph' algorithm.");
}

