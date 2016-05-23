//
// Created by sebri on 16.05.2016.
//

#include <stdexcept>
#include <set>
#include "Prim.h"

#include "../graphs/Graph.h"

void Prim::visit(Graph *g, Vertex *from) {
    if (!g->isSimple()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must be simple.");
    }
    if (!g->isConnected()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must be connected.");
    }
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must have a ponderation.");
    }

    _G = g->emptyClone();

    typedef std::pair<Edge*,Vertex*> EdgeVertex;
    std::set<EdgeVertex> pq;
    std::vector<Edge*> edge(g->V());
    std::vector<bool> marked(g->V(),false);

    marked[from->id()] = true;

    g->forEachAdjacentEdge(from,[&](IEdge* ie) {
        Edge *e = (Edge*)ie;
        Vertex *w = e->other(from);
        edge[w->id()] = e;
        pq.insert(std::make_pair(e,w));
    });

    while ( !pq.empty() && _G->E() < g->V()-1 ) {

        Edge *e = pq.begin()->first;
        _G->assignVertex(e->either());
        _G->assignVertex(e->other(e->either()));
        _G->assignEdge(e);

        Vertex *v = pq.begin()->second;
        marked[v->id()] = true;

        pq.erase(pq.begin());
        g->forEachAdjacentEdge(v,[&](IEdge* ie) {
            Edge *e = (Edge*)ie;
            Vertex *w = e->other(v);
            if(!marked[w->id()] && *edge[w->id()] > *e) {
                pq.erase(std::make_pair(edge[w->id()],w));
                pq.insert(std::make_pair(e,w));
                edge[w->id()] = e;
            }
        });
    }
}

void Prim::visit(DiGraph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
}

void Prim::visit(FlowGraph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
}

IGraph *Prim::G() const {
    return _G;
}

std::vector<int> Prim::table() {
    throw std::runtime_error("No table for Prim algorithm");
}

