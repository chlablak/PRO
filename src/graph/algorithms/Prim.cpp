//
// Created by sebri on 16.05.2016.
//

#include <stdexcept>
#include <set>
#include "Prim.h"
#include "../graphs/Graph.h"

namespace std
{
    template <>
    struct less<std::pair<Edge*,Vertex*>>
    {
        bool operator()(const std::pair<Edge*,Vertex*>& a, const std::pair<Edge*,Vertex*>& b) const
        {
            return a.first->weight() < b.first->weight();
        }
    };
}

void Prim::visit(Graph *g, Vertex *from, Vertex *) {
    if (!g->isSimple()) {
        throw std::runtime_error("Error in 'Prim' algorithm. The graph must be simple.");
    }
    if (!g->isConnected()) {
        throw std::runtime_error("Error in 'Prim' algorithm. The graph must be connected.");
    }
    if (!g->isWeighted()) {
        throw std::runtime_error("Error in 'Prim' algorithm. The graph must be weighted.");
    }

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();

    //typedef std::pair<Edge*,Vertex*> EdgeVertex;
    std::set<std::pair<Edge*,Vertex*>> pq;
    std::vector<Edge*> edge(gClone->V(), nullptr);
    std::vector<bool> marked(gClone->V(),false);

    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }

    marked[fromCpy->id()] = true;
    _G->assignVertex(fromCpy);

    gClone->forEachAdjacentEdge(fromCpy,[&](IEdge* ie) {
        Edge *e = (Edge*)ie;
        Vertex *w = e->other(fromCpy);
        edge[w->id()] = e;
        pq.insert(std::make_pair(e,w));
    });

    while ( !pq.empty() && _G->E() < gClone->V()-1 ) {
        Edge *e = pq.begin()->first;
        Vertex *v = pq.begin()->second;
        marked[v->id()] = true;

        _G->assignVertex(v);
        _G->assignEdge(e);

        pq.erase(pq.begin());

        gClone->forEachAdjacentEdge(v,[v, &pq, &marked, &edge, this](IEdge* ie) {
            Edge *e2 = (Edge*)ie;
            Vertex *w = e2->other(v);

            if(!marked[w->id()] && (edge[w->id()] == nullptr || *edge[w->id()] > *e2) ) {
                if (edge[w->id()] != nullptr) {
                    pq.erase(std::make_pair(edge[w->id()], w));
                    _G->removeEdge(edge[w->id()]);
                }
                std::set<std::pair<Edge*,Vertex*>>::iterator it;
                it = pq.find(std::make_pair(e2,w));
                if (it != pq.end()) {
                    pq.erase(std::make_pair(e2,w));
                }
                pq.insert(std::make_pair(e2,w));
                edge[w->id()] = e2;
                _G->assignVertex(w);
                _G->assignEdge(e2);
            }
        });
    }
}

void Prim::visit(DiGraph *, Vertex *, Vertex *) {
}

void Prim::visit(FlowGraph *, Vertex *, Vertex *) {
}

IGraph *Prim::G() const {
    return _G;
}

std::vector<double> Prim::table() {
    throw std::runtime_error("Error. No table for 'Prim' algorithm");
}

