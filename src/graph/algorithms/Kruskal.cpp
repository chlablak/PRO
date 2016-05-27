//
// Created by sebri on 16.05.2016.
//

#include <stdexcept>
#include "Kruskal.h"
#include "UnionFind.h"
#include "../graphs/Graph.h"

namespace std
{
    template <>
    struct greater<IEdge*>
    {
        bool operator()(const IEdge *a, const IEdge *b) const
        {
            return a->weight() > b->weight();
        }
    };
}

void Kruskal::visit(Graph *g, Vertex *, Vertex *) {

    if (!g->isConnected()) {
        throw std::runtime_error("Error in Kruskal algorithm. The graph must be connected.");
    }
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Kruskal algorithm. The graph must be weighted.");
    }

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();
    MinPQ pq;
    UnionFind uf(g->V());
    gClone->forEachEdge([&](IEdge *e) {
        pq.push((Edge*)e);
    });

    while ( !pq.empty() && _G->E() < gClone->V()-1 ) {
        IEdge *ie = pq.top(); pq.pop();
        Edge *e = (Edge*)ie;

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

void Kruskal::visit(DiGraph *, Vertex *, Vertex *) {

    throw std::runtime_error("Error. A directed graph can't be applied "
                                     "to 'Kruskal algorithm'");
}

void Kruskal::visit(FlowGraph *, Vertex *, Vertex *) {

    throw std::runtime_error("Error. A flow graph can't be applied "
                                     "to 'Kruskal' algorithm.");
}

IGraph *Kruskal::G() const {
    return _G;
}

std::vector<double> Kruskal::table() {
    throw std::runtime_error("Error. No table for 'Kruskal' algorithm.");
}

