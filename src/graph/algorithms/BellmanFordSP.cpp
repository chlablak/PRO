/*! \brief Bellman-Ford's algorithm to find shortest path in a graph
 *
 * \file BellmanFordSP.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stdexcept>
#include <vector>
#include <limits>
#include "BellmanFordSP.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

void BellmanFordSP::relax(IEdge *ie, Vertex *u)
{
    Vertex *v = ie->from();
    Vertex *w = ie->to();
    if (*w == *u) {
        w = v;
        v = u;
    }

    double distThruE = _distanceTo[v->id()]+ie->weight();

    if(_distanceTo[w->id()] > distThruE) {
        _distanceTo[w->id()] = distThruE;

        if (_edgeTo[w->id()] != nullptr)
            _G->removeEdge(_edgeTo[w->id()]);

        _edgeTo[w->id()] = ie;

        _G->assignVertex(v);
        _G->assignVertex(w);
        _G->assignEdge(ie);
    }
}

template<typename T, typename U>
void BellmanFordSP::sp(T *g, U *, Vertex *from)
{
    if (!g->isWeighted())
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The directed graph must be weighted.");

    T *gClone = g->clone();
    _G = gClone->emptyClone();

    size_t nVertex = gClone->V();
    _edgeTo.resize(nVertex);
    _distanceTo.assign(nVertex,std::numeric_limits<double>::max());

    // Search from vertex
    Vertex *fromCpy = nullptr;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }

    _edgeTo[fromCpy->id()] = new U(fromCpy, fromCpy, 0.);
    _distanceTo[fromCpy->id()] = 0.;

    for (size_t i = 0; i < nVertex; ++i)
        gClone->forEachEdge([this, &fromCpy](IEdge *ie) {
            relax(ie, fromCpy);
        });
}

void BellmanFordSP::visit(Graph *g, Vertex *from, Vertex *)
{
    Edge *e = nullptr;
    sp(g, e, from);
}

void BellmanFordSP::visit(DiGraph *g, Vertex *from, Vertex *)
{
    DiEdge *e = nullptr;
    sp(g, e, from);
}

void BellmanFordSP::visit(FlowGraph *g, Vertex *from, Vertex *)
{
    FlowEdge *e = nullptr;
    sp(g, e, from);
}

IGraph *BellmanFordSP::G() const
{
    return _G;
}

std::vector<double> BellmanFordSP::table()
{
    return _distanceTo;
}
