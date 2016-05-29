/*! \brief Dijkstra's algorithm to find shortest path in a graph
 *
 * \file Dijkstra.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <set>
#include <stdexcept>
#include "DijkstraSP.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

void DijkstraSP::relax(IEdge *ie, Vertex *u)
{
    Vertex *w = ie->to();
    if (*w == *u)
        w = ie->from();

    if (!_marques[w->id()]) {
        Vertex *v = ie->from();
        if (*v == *w)
            v = ie->to();

        double distThruE = _distanceTo[v->id()] + ie->weight();

        if (_distanceTo[w->id()] > distThruE) {
            _pq.erase(std::make_pair(_distanceTo[w->id()], w));
            _distanceTo[w->id()] = distThruE;

            if (_edgeTo[w->id()] != nullptr)
                _G->removeEdge(_edgeTo[w->id()]);

            _edgeTo[w->id()] = ie;

            _G->assignVertex(v);
            _G->assignVertex(w);
            _G->assignEdge(ie);

            _pq.insert(std::make_pair(_distanceTo[w->id()], w));
        }
    }
}

template <typename T, typename U>
void DijkstraSP::sp(T* g, U *, Vertex *from) {
    if (!g->isWeighted() || g->isNegativeWeighted())
        throw std::runtime_error("Error in Dijkstra algorithm. The graph must"
                                         " be positively weighted");

    T *gClone = g->clone();
    _G = gClone->emptyClone();

    // Init _distances and _edges
    _distanceTo.assign(g->V(),std::numeric_limits<double>::max());
    _edgeTo.resize(g->V());
    _marques.assign(g->V(), false);

    // Search from vertex
    Vertex *fromCpy = nullptr;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }

    _distanceTo[fromCpy->id()] = 0;
    _edgeTo[fromCpy->id()] = new U(fromCpy, fromCpy, 0);

    // Initialization. Insert all vertices of the graph in the priority queue
    gClone->forEachVertex([this](Vertex *v){
        _pq.insert( std::make_pair(_distanceTo[v->id()], v) );
    });

    // Get the min vertex, then treat his adjacent edges to progressively find
    // the shortest path
    while (!_pq.empty()) {

        Vertex *u = _pq.begin()->second;
        _pq.erase(_pq.begin());
        _marques[u->id()] = true;

        gClone->forEachAdjacentEdge(u, [this, &u](IEdge *ie){
            relax(ie, u);
        });
    }
}

void DijkstraSP::visit(Graph *g, Vertex *from, Vertex *) {
    Edge *e = nullptr;
    sp(g, e, from);
}

void DijkstraSP::visit(DiGraph *g, Vertex *from, Vertex *) {
    DiEdge *e = nullptr;
    sp(g, e, from);
}

void DijkstraSP::visit(FlowGraph *g, Vertex *from, Vertex *) {
    FlowEdge *e = nullptr;
    sp(g, e, from);
}

IGraph *DijkstraSP::G() const {
    return _G;
}

std::vector<double> DijkstraSP::table() {
    return _distanceTo;
}

