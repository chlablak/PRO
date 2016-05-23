//
// Created by sebri on 06.05.2016.
//

#include <stack>
#include "DFS.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

void DFS::DFSprocedure(Graph *g, Vertex *u) {
    g->forEachAdjacentVertex(u, [&g, &u, this](Vertex *v){
        if (_dfsnum[v->id()] == 0) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(g->getEdges(u, v).front());
            DFSprocedure(g, v);
        }
    });
}

DFS::~DFS() {

}


void DFS::visit(Graph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new Graph;
        return;
    }

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
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    _G = g->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), 0);
    N = 1;
    _dfsnum.at(from->id()) = N;

    vector<int> debut, fin;
    debut.assign(g->V(), 0);
    fin.assign(g->V(), 0);
    int date = 0;
    debut[from->id()] = ++date;
    _G->assignVertex(from);

    g->forEachAdjacentEdge(from, [&g, &debut, &fin, &date, this](IEdge *ie){
        if (debut[ie->to()->id()] == 0) {
            _dfsnum[ie->to()->id()] = ++N;
            _G->assignVertex(ie->to());
            _G->assignEdge(ie);
            DFSprocedure(g, ie->to(), debut, fin, date);
        }
    });
}

void DFS::visit(FlowGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    _G = g->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), 0);
    N = 1;
    _dfsnum.at(from->id()) = N;

    vector<int> debut, fin;
    debut.assign(g->V(), 0);
    fin.assign(g->V(), 0);
    int date = 0;
    debut[from->id()] = ++date;
    _G->assignVertex(from);

    g->forEachAdjacentEdge(from, [&g, &debut, &fin, &date, this](IEdge *ie){
        if (debut[ie->to()->id()] == 0) {
            _dfsnum[ie->to()->id()] = ++N;
            _G->assignVertex(ie->to());
            _G->assignEdge(ie);
            DFSprocedure(g, ie->to(), debut, fin, date);
        }
    });
}

IGraph *DFS::G() const {
    return _G;
}

std::vector<int> DFS::table() {
    return _dfsnum;
}

void DFS::DFSprocedure(DiGraph *g, Vertex *u, vector<int> &debut,
                       vector<int> &fin, int date) {
    debut[u->id()] = ++date;

    g->forEachAdjacentEdge(u, [&u, &g, &debut, &fin, &date, this](IEdge *ie){
        Vertex *v = ie->to();
        if (debut[v->id()] == 0) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(ie);
            DFSprocedure(g, v, debut, fin, date);
        }
    });

    fin[u->id()] = ++date;
}

void DFS::DFSprocedure(FlowGraph *g, Vertex *u, vector<int> &debut,
                       vector<int> &fin, int date) {
    debut[u->id()] = ++date;

    g->forEachAdjacentEdge(u, [&u, &g, &debut, &fin, &date, this](IEdge *ie){
        Vertex *v = ie->to();
        if (debut[v->id()] == 0) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(ie);
            DFSprocedure(g, v, debut, fin, date);
        }
    });

    fin[u->id()] = ++date;
}





