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

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();

    typedef std::pair<Edge*,Vertex*> EdgeVertex;
    std::set<EdgeVertex> pq;
    std::vector<Edge*> edge(gClone->V());
    std::vector<bool> marked(gClone->V(),false);

    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }

    marked[fromCpy->id()] = true;

    gClone->forEachAdjacentEdge(fromCpy,[&](IEdge* ie) {
        Edge *e = (Edge*)ie;
        Vertex *w = e->other(fromCpy);
        edge[w->id()] = e;
        pq.insert(std::make_pair(e,w));
    });

//    while (!pq.empty()) {
//        cout << *pq.begin()->first << "  " << *pq.begin()->second << endl;
//        pq.erase(pq.begin());
//    }

    while ( !pq.empty() && _G->E() < gClone->V()-1 ) {
        cout << *pq.begin()->first << "  " << *pq.begin()->second << endl;
//        pq.erase(pq.begin());
        Edge *e = pq.begin()->first;
        _G->assignVertex(e->either());
        _G->assignVertex(e->other(e->either()));
        _G->assignEdge(e);

        Vertex *v = pq.begin()->second;
        marked[v->id()] = true;

        pq.erase(pq.begin());
        gClone->forEachAdjacentEdge(v,[&](IEdge* ie) {
            Edge *e2 = (Edge*)ie;
            Vertex *w = e2->other(v);
            if(!marked[w->id()] && edge[w->id()] > e2) {
                pq.erase(std::make_pair(edge[w->id()],w));
                pq.insert(std::make_pair(e2,w));
                edge[w->id()] = e2;
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

