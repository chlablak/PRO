/*! \brief Depth First Search's algorithm
 *
 * \file DFS.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stack>
#include "DFS.h"
#include "../graphs/Graph.h"

void DFS::DFSprocedure(Graph *g, Vertex *u)
{
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

template <typename T>
void DFS::DFSprocedure(T *g, Vertex *u, vector<int> &begin,
                       vector<int> &end, int date)
{
    begin[u->id()] = ++date;

    g->forEachAdjacentEdge(u, [&u, &g, &begin, &end, &date, this](IEdge *ie) {
        Vertex *v = ie->to();
        if (begin[v->id()] == 0) {
            _dfsnum[v->id()] = ++N;
            _G->assignVertex(v);
            _G->assignEdge(ie);
            DFSprocedure(g, v, begin, end, date);
        }
    });

    end[u->id()] = ++date;
}

template <typename T>
void DFS::common(T *g, Vertex *from)
{
    if (g->isNull()) {
        _G = new T;
        return;
    }

    T *gClone = g->clone();
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

void DFS::visit(Graph *g, Vertex *from, Vertex *)
{
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

void DFS::visit(DiGraph *g, Vertex *from, Vertex *)
{
    common(g, from);
}

void DFS::visit(FlowGraph *g, Vertex *from, Vertex *)
{
    common(g, from);
}

IGraph *DFS::G() const
{
    return _G;
}

std::vector<double> DFS::table()
{
    return _dfsnum;
}