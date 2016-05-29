/*! \brief Class DiGraph (manipulate DiEdge)
 *
 * \file DiGraph.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "DiGraph.h"

DiGraph::DiGraph(const DiGraph &dg) : DiGraphCommon(dg)
{}

IGraph *DiGraph::emptyClone() const
{
    DiGraph *g = new DiGraph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

bool DiGraph::isConnected() const
{
    vector<double> cc = GraphAlgorithm::connectedComponent((DiGraph*)this);
    size_t ccSize = cc.size();
    if (ccSize > 1)
        for (size_t i = 1; i < ccSize; ++i)
            if (cc[i] != cc[0])
                return false;

    return true;
}

bool DiGraph::isStronglyConnected() const
{
    vector<double> scc = GraphAlgorithm::stronglyConnectedComponent((DiGraph*)this);
    size_t ccSize = scc.size();
    if (ccSize > 1)
        for (size_t i = 1; i < ccSize; ++i)
            if (scc[i] != scc[0])
                return false;

    return true;
}


void DiGraph::accept(Visitor *v, Vertex *from, Vertex *to)
{
    v->visit(this, from, to);
}

IEdge *DiGraph::createEdge(Vertex *v, Vertex *w) const
{
    return new DiEdge(v, w);
}

DiGraph *DiGraph::clone() const
{
    return new DiGraph(*this);
}
