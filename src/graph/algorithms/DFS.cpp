//
// Created by sebri on 06.05.2016.
//

#include "DFS.h"
#include "../graphs/Graph.h"


void DFS::DFSprocedure(Graph *g, Vertex *u) {
    g->forEachAdjacentVertex(u, [&g, &u, this](Vertex *v){
        if (_dfsnum[v->id()] == 0) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(g->getEdge(u, v));
            DFSprocedure(g, v);
        }
    });
}

DFS::~DFS() {

}


void DFS::visit(Graph *g, Vertex *from) {
    _G = g->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), 0);
    N = 1;
    _dfsnum.at(from->id()) = N;

    // Create a graph with only vertex 'from'
    _G->assignVertex(from);

    DFSprocedure(g, from);
}

void DFS::visit(DiGraph *g, Vertex *from) {

}

void DFS::visit(FlowGraph *g, Vertex *from) {

}

IGraph *DFS::G() const {
    return _G;
}

std::vector<int>& DFS::table() {
    return _dfsnum;
}







