//
// Created by sebri on 01.05.2016.
//

#include <stack>
#include "BFS.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

using namespace std;

void BFS::visit(Graph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new Graph;
        return;
    }

    Graph *gClone = g->clone();
    _G = gClone->emptyClone();

    // Table of distances
    _distances.assign(gClone->V(), numeric_limits<int>::max());
    _distances.at(from->id()) = 0;

    // Initialize list with from
    list<Vertex*> Q;
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            Q.push_back(v);
            break;
        }
    }

    while (!Q.empty()) {
        Vertex *u = Q.front(); Q.pop_front();
        _G->assignVertex(u);

        gClone->forEachAdjacentEdge(u, [this, &u, &Q](IEdge *ie){
            Vertex *v = ie->other(u);

            if (_distances.at(v->id()) == numeric_limits<int>::max()) {
                _distances.at(v->id()) = _distances.at(u->id()) + 1;
                Q.push_back(v);
                _G->assignVertex(v);
                _G->assignEdge(ie);
            }
        });
    }
}

void BFS::visit(DiGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }

    DiGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    _distances.assign(gClone->V(), -1);
    vector<Vertex*> p;
    p.assign(gClone->V(), nullptr);
    _distances[from->id()] = 0;

    stack<Vertex*> Q;
    // Initialize stack with from
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            Q.push(v);
            break;
        }
    }

    while (!Q.empty()) {
        Vertex *u = Q.top(); Q.pop();
        _G->assignVertex(u);

        gClone->forEachAdjacentEdge(u, [&p, &Q, this, &u](IEdge *ie) {
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

    FlowGraph *gClone = g->clone();
    _G = gClone->emptyClone();

    _distances.assign(gClone->V(), -1);
    vector<Vertex*> p;
    p.assign(gClone->V(), nullptr);
    _distances[from->id()] = 0;

    stack<Vertex*> Q;
    // Initialize stack with from
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            Q.push(v);
            break;
        }
    }

    while (!Q.empty()) {
        Vertex *u = Q.top(); Q.pop();
        _G->assignVertex(u);

        gClone->forEachAdjacentEdge(u, [&p, &Q, this, &u](IEdge *ie) {
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

std::vector<double> BFS::table() {
    return _distances;
}