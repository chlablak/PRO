//
// Created by sebri on 01.05.2016.
//

#include "BFS.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"
#include <stack>

using namespace std;

void BFS::visit(Graph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new Graph;
        return;
    }

    _G = g->emptyClone();
    // Table of distances
    _distances.assign(g->V(), numeric_limits<int>::max());
    _distances.at(from->id()) = 0;

    // Initialize list with from
    list<Vertex*> Q;
    Q.push_back(from);

    // Initialize a graph with only the source vertex in it
    _G->assignVertex(from);

    while (!Q.empty()) {
        Vertex *u = Q.front();
        Q.pop_front();

        g->forEachAdjacentVertex(u, [&g, this, &u, &Q](Vertex *v){
            if (_distances.at(v->id()) == numeric_limits<int>::max()) {
                _distances.at(v->id()) = _distances.at(u->id()) + 1;
                _G->assignVertex(v);
                _G->assignEdge(g->getEdges(u, v).front());
                Q.push_back(v);
            }
        });
    }
}

void BFS::visit(DiGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    _G = g->emptyClone();

    _distances.assign(g->V(), -1);
    vector<Vertex*> p;
    p.assign(g->V(), nullptr);
    _distances[from->id()] = 0;
    stack<Vertex*> Q;
    Q.push(from);

    while (!Q.empty()) {
        Vertex *u = Q.top(); Q.pop();
        _G->assignVertex(u);
        g->forEachAdjacentEdge(u, [&p, &Q, this, &u](IEdge *ie) {
            Vertex *v = ie->to();
            if (_distances[v->id()] == -1) {
                _distances[v->id()] = _distances[u->id()] + 1;
                p[v->id()] = u;
                Q.push(v);
                _G->assignVertex(v);
                _G->assignEdge(ie);
            }
        });
    }
}

void BFS::visit(FlowGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new FlowGraph;
        return;
    }

    _G = g->emptyClone();

    _distances.assign(g->V(), -1);
    vector<Vertex*> p;
    p.assign(g->V(), nullptr);
    _distances[from->id()] = 0;
    stack<Vertex*> Q;
    Q.push(from);

    while (!Q.empty()) {
        Vertex *u = Q.top(); Q.pop();
        _G->assignVertex(u);
        g->forEachAdjacentEdge(u, [&p, &Q, this, &u](IEdge *ie) {
            Vertex *v = ie->to();
            if (_distances[v->id()] == -1) {
                _distances[v->id()] = _distances[u->id()] + 1;
                p[v->id()] = u;
                Q.push(v);
                _G->assignVertex(v);
                _G->assignEdge(ie);
            }
        });
    }
}

BFS::~BFS() {

}

IGraph* BFS::G() const {
    return _G;
}

std::vector<int>& BFS::table() {
    return _distances;
}