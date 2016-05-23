//
// Created by sebri on 22.05.2016.
//

#include <stdexcept>
#include <vector>
#include <limits>
#include "BellmanFordSP.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

BellmanFordSP::~BellmanFordSP() {

}

void BellmanFordSP::relax(IEdge *ie) {
    Vertex *v = ie->from(), *w = ie->to();
    double distThruE = _distanceTo[v->id()]+ie->weight();

    if(_distanceTo[w->id()] > distThruE) {
        _distanceTo[w->id()] = distThruE;
        if (_edgeTo[w->id()] != nullptr) {
            _G->removeEdge(_edgeTo[w->id()]);
        }
        _edgeTo[w->id()] = ie;

        _G->assignVertex(v);
        _G->assignVertex(w);
        _G->assignEdge(ie);
    }
}

void BellmanFordSP::visit(Graph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
    throw std::runtime_error("The 'Bellman-Ford' algorithm can't be applied"
                                     "to a non directed graph.");
}

void BellmanFordSP::visit(DiGraph *g, Vertex *from) {
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The directed graph must be weighted.");
    }

    _G = g->emptyClone();

    _edgeTo.resize(g->V());
    _distanceTo.assign(g->V(),std::numeric_limits<double>::max());

    _edgeTo[from->id()] = new DiEdge(from, from, 0.);
    _distanceTo[from->id()] = 0.;

    for(size_t i = 0; i < g->V(); ++i) {
        g->forEachEdge([this](IEdge *ie) {
            relax(ie);
        });
    }
}

void BellmanFordSP::visit(FlowGraph *g, Vertex *from) {
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The flow graph must be weighted.");
    }

    _G = g->emptyClone();

    _edgeTo.resize(g->V());
    _distanceTo.assign(g->V(),std::numeric_limits<double>::max());

    _edgeTo[from->id()] = new FlowEdge(from, from, 0.);
    _distanceTo[from->id()] = 0.;

    for(size_t i = 0; i < g->V(); ++i) {
        g->forEachEdge([this](IEdge *ie) {
            relax(ie);
        });
    }
}

IGraph *BellmanFordSP::G() const {
    return _G;
}

std::vector<int> BellmanFordSP::table() {
    throw std::runtime_error("caca"); // TODO
}
