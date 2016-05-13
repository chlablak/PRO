//
// Created by sebri on 01.05.2016.
//

#include "BFS.h"
#include "../graphs/Graph.h"

using namespace std;

Graph* BFS::visit(Graph *g, Vertex *from) {
    Graph *G = new Graph;
    // Table of distances
    _distances.assign(g->V(), numeric_limits<int>::max());
    _distances.at(from->id()) = 0;

    for (int i : _distances) {
        cout << i << " ";
    }
    cout << endl;

    // Initialize list with from
    list<Vertex*> Q;
    Q.push_back(from);

    // Initialize a graph with only the source vertex in it
    G->addVertex(from);

    while (!Q.empty()) {
        Vertex *u = Q.front();
        Q.pop_front();

        g->forEachAdjacentVertex(u, [&g, this, &u, &Q, &G](Vertex *v){
            if (_distances.at(v->id()) == numeric_limits<int>::max()) {
                cout << "u id  = " << u->id() << endl;
                cout << "v id  = " << v->id() << endl;
                _distances.at(v->id()) = _distances.at(u->id()) + 1;

                for (int i : _distances) {
                    cout << i << " ";
                }
                cout << endl;

                G->addVertex(v);
                G->addEdge(g->getEdge(u, v));
                Q.push_back(v);
            }
        });
    }


    cout << endl;

    return G;
}

DiGraph* BFS::visit(DiGraph *g, Vertex *v) {

}

FlowGraph* BFS::visit(FlowGraph *g, Vertex *v) {

}

BFS::~BFS() {

}

