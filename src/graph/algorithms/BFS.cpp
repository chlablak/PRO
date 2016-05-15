//
// Created by sebri on 01.05.2016.
//

#include "BFS.h"
#include "../graphs/Graph.h"

using namespace std;

void BFS::visit(Graph *g, Vertex *from) {
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
                _G->assignEdge(g->getEdge(u, v));
                Q.push_back(v);
            }
        });
    }
}

void BFS::visit(DiGraph *g, Vertex *v) {

}

void BFS::visit(FlowGraph *g, Vertex *v) {

}

BFS::~BFS() {

}

IGraph* BFS::G() const {
    return _G;
}

std::vector<int>* BFS::table() {
    return &_distances;
}





