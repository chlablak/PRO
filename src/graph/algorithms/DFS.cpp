//
// Created by sebri on 06.05.2016.
//

#include <stack>
#include "DFS.h"
#include "../graphs/Graph.h"

void DFS::DFSprocedure(Graph *g, Vertex *u) {
    g->forEachAdjacentEdge(u, [&g, &u, this](IEdge *ie){
        Vertex *v = ie->other(u);
        if (_dfsnum[v->id()] == -1) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(ie);
            DFSprocedure(g, v);
        }
    });
}

DFS::~DFS() {

}


void DFS::visit(Graph *g, Vertex *from, Vertex *) {
    if (g->isNull()) {
        _G = new Graph;
        return;
    }

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), -1);
    N = 0;
    _dfsnum.at(from->id()) = N;

    Vertex *fromCpy;

    // Create a graph with only vertex 'from'
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }

    _G->assignVertex(fromCpy);
    DFSprocedure(gClone, fromCpy);
}

void DFS::visit(DiGraph *g, Vertex *from, Vertex *) {
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    DiGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), -1);
    N = 0;
    _dfsnum.at(from->id()) = N;

    vector<int> debut, fin;
    debut.assign(g->V(), 0);
    fin.assign(g->V(), 0);
    int date = 0;
    debut[from->id()] = ++date;

    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }
    _G->assignVertex(fromCpy);

    gClone->forEachAdjacentEdge(fromCpy, [&gClone, &debut, &fin, &date, this](IEdge *ie) {
        if (debut[ie->to()->id()] == 0) {
            _dfsnum[ie->to()->id()] = ++N;
            _G->assignVertex(ie->to());
            _G->assignEdge(ie);
            DFSprocedure(gClone, ie->to(), debut, fin, date);
        }
    });
}

void DFS::visit(FlowGraph *g, Vertex *from, Vertex *) {
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    FlowGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    // Table of vertex discovery order
    _dfsnum.assign(g->V(), -1);
    N = 0;
    _dfsnum.at(from->id()) = N;

    vector<int> debut, fin;
    debut.assign(g->V(), 0);
    fin.assign(g->V(), 0);
    int date = 0;
    debut[from->id()] = ++date;

    Vertex *fromCpy;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
            break;
        }
    }
    _G->assignVertex(fromCpy);

    gClone->forEachAdjacentEdge(fromCpy, [&gClone, &debut, &fin, &date, this](IEdge *ie){
        if (debut[ie->to()->id()] == 0) {
            _dfsnum[ie->to()->id()] = ++N;
            _G->assignVertex(ie->to());
            _G->assignEdge(ie);
            DFSprocedure(gClone, ie->to(), debut, fin, date);
        }
    });
}

IGraph *DFS::G() const {
    return _G;
}

std::vector<double> DFS::table() {
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





