//
// Created by sebri on 22.05.2016.
//

#include <stdexcept>
#include "SCCTarjan.h"

SCCTarjan::~SCCTarjan() { }

void SCCTarjan::visit(Graph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
    throw std::runtime_error("The algorithm of strongly connected component"
                                     "can't be applied to a non-directed graph");
}

void SCCTarjan::visit(DiGraph *g, Vertex *from) {
    UNUSED(from);
    _scc.assign(g->V(), 0);
    _dfsnum.assign(g->V(), 0);
    _low.assign(g->V(), 0);

    g->forEachVertex([this, &g](Vertex* v){
        if (_scc[v->id()] == 0) {
            SCC(v, g);
        }
    });
}

void SCCTarjan::visit(FlowGraph *g, Vertex *from) {
    visit((DiGraph*)g, from);
}

IGraph *SCCTarjan::G() const {
    return nullptr;
}

std::vector<int> &SCCTarjan::table() {
    return _scc;
}

void SCCTarjan::SCC(Vertex *u, DiGraph *g) {
    ++_N;
    _dfsnum[u->id()] = _N;
    _low[u->id()] = _N;
    _P.push(u);


    g->forEachAdjacentVertex(u, [this, &g, &u](Vertex *v){
        if (_dfsnum[v->id()] == 0) {
            SCC(v, g); // v has not been visited yet
        }
        if (_scc[v->id()] == 0) {
            _low[u->id()] = min(_low[u->id()], _low[v->id()]);
        }
    });

    if (_low[u->id()] == _dfsnum[u->id()]) {
        // Let's unstack until u
        ++_K;
        Vertex *w = nullptr;
        do {
             w = _P.top(); _P.pop();
            _scc[w->id()] = _K;
        } while (w != u);
    }
}
