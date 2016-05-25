//
// Created by sebri on 22.05.2016.
//

#include <stdexcept>
#include <vector>
#include <limits>
#include "BellmanFordSP.h"
#include "../graphs/Graph.h"
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
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The directed graph must be weighted.");
    }

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();

    size_t nVertex = gClone->V();
    _edgeTo.resize(nVertex);
    _distanceTo.assign(nVertex,std::numeric_limits<double>::max());

    // Search from vertex
    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
        }
    }

    _edgeTo[fromCpy->id()] = new Edge(fromCpy, fromCpy, 0.);
    _distanceTo[fromCpy->id()] = 0.;

    for(size_t i = 0; i < nVertex; ++i) {
        gClone->forEachEdge([this](IEdge *ie) {
            relax(ie);
        });
    }
}

void BellmanFordSP::visit(DiGraph *g, Vertex *from) {
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The directed graph must be weighted.");
    }

    DiGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    size_t nVertex = gClone->V();
    _edgeTo.resize(nVertex);
    _distanceTo.assign(nVertex,std::numeric_limits<double>::max());

    // Search from vertex
    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
        }
    }

    _edgeTo[fromCpy->id()] = new DiEdge(fromCpy, fromCpy, 0.);
    _distanceTo[fromCpy->id()] = 0.;

    for(size_t i = 0; i < nVertex; ++i) {
        gClone->forEachEdge([this](IEdge *ie) {
            relax(ie);
        });
    }
}

void BellmanFordSP::visit(FlowGraph *g, Vertex *from) {
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Bellman-Ford algorithm."
                                         "The flow graph must be weighted.");
    }

    FlowGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    size_t nVertex = gClone->V();
    _edgeTo.resize(nVertex);
    _distanceTo.assign(nVertex,std::numeric_limits<double>::max());

    // Search from vertex
    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
        }
    }

    _edgeTo[fromCpy->id()] = new FlowEdge(fromCpy, fromCpy, 0.);
    _distanceTo[fromCpy->id()] = 0.;

    for(size_t i = 0; i < nVertex; ++i) {
        gClone->forEachEdge([this](IEdge *ie) {
            relax(ie);
        });
    }
}

IGraph *BellmanFordSP::G() const {
    return _G;
}

std::vector<double> BellmanFordSP::table() {
    return _distanceTo;
}
