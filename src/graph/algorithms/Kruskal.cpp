//
// Created by sebri on 16.05.2016.
//

#include "Kruskal.h"
#include "UnionFind.h"
#include "../graphs/Graph.h"


void Kruskal::visit(Graph *g, Vertex *from) {
    if (!g->isConnected()) {
        throw std::runtime_error("Error in Kruskal algorithm. The graph must be connected.");
    }
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Kruskal algorithm. The graph must be weighted.");
    }

    _G = g->emptyClone();
    MinPQ pq;
    UnionFind uf(g->V());
    g->forEachEdge([&](IEdge *e) {
        pq.push((Edge*)e);
    });

    while ( !pq.empty() && _G->E() < g->V()-1 ) {
        Edge *e = pq.top(); pq.pop();
        int v = e->either()->id();
        int w = e->other(e->either())->id();

        if( !uf.Connected(v,w) ) {
            uf.Union(v, w);
            _G->assignVertex(e->either());
            _G->assignVertex(e->other(e->either()));
            _G->assignEdge(e);
        }
    }
}

void Kruskal::visit(DiGraph *g, Vertex *from) {

}

void Kruskal::visit(FlowGraph *g, Vertex *from) {

}

IGraph *Kruskal::G() const {
    return _G;
}

std::vector<int> &Kruskal::table() {
    throw std::runtime_error("Error : No table for Kruskal algorithm.");
}

