/*! \brief Class FlowGraph (manipulate FlowEdge)
 *
 * \file FlowGraph.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "FlowGraph.h"

IGraph *FlowGraph::emptyClone() const
{
    FlowGraph *g = new FlowGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

FlowGraph::FlowGraph(const FlowGraph &fg) : DiGraphCommon(fg) {}


bool FlowGraph::isConnected() const
{
    vector<double> cc = GraphAlgorithm::connectedComponent((FlowGraph*)this);
    size_t ccSize = cc.size();
    if (ccSize > 1)
        for (size_t i = 1; i < ccSize; ++i)
            if (cc[i] != cc[0])
                return false;

    return true;
}

bool FlowGraph::isStronglyConnected() const
{
    vector<double> scc = GraphAlgorithm::stronglyConnectedComponent((FlowGraph*)this);
    size_t ccSize = scc.size();
    if (ccSize > 1)
        for (size_t i = 1; i < ccSize; ++i)
            if (scc[i] != scc[0])
                return false;

    return true;
}


FlowGraph *FlowGraph::clone() const
{
    return new FlowGraph(*this);
}

bool FlowGraph::hasPositiveCapacity() const
{
    for (IEdge *ie : edgeList()) {
        FlowEdge *fe = (FlowEdge*)ie;
        if (fe->maxCapacity() < 0)
            return false;
    }

    return true;
}

void FlowGraph::accept(Visitor *v, Vertex *from, Vertex *to)
{
    v->visit(this, from, to);
}

IEdge *FlowGraph::createEdge(Vertex *v, Vertex *w) const
{
    return new FlowEdge(v, w);
}