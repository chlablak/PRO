//
// Created by sebri on 08.05.2016.
//

#include <stdexcept>
#include "ConnectedComponent.h"
#include "../graphs/Graph.h"

ConnectedComponent::~ConnectedComponent() { }

void ConnectedComponent::visit(Graph *g, Vertex *from) {
    UNUSED(from);

    _cc.assign(g->V(), 0);
    int N = 0;
    g->forEachVertex([&g, &N, this](Vertex *v){
        if (_cc[v->id()] == 0) {
            // Create an empty list
            list<Vertex*> Q;
            Q.push_back(v);
            ++N;
            while (!Q.empty()) {
                Vertex *u = Q.front(); Q.pop_front();
                _cc[u->id()] = N;
                g->forEachAdjacentEdge(u, [&N, &Q, &u, this](IEdge *ie){
                    Vertex *w = ie->other(u);
                    if (_cc[w->id()] == 0) {
                        _cc[w->id()] = N;
                        Q.push_back(w);
                    }
                });
            }
        }
    });
}

void ConnectedComponent::visit(DiGraph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
    throw std::runtime_error("The 'Connected Component' algorithm doesn't apply for"
                                "directed graphs. Use the 'Strongly Connected"
                                "Component' algorithm instead");
}

void ConnectedComponent::visit(FlowGraph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
    throw std::runtime_error("The 'Connected Component' algorithm doesn't apply for"
                                "directed graphs. Use the 'Strongly Connected"
                                "Component' algorithm instead");
}

IGraph *ConnectedComponent::G() const {
    return nullptr;
}

std::vector<int> ConnectedComponent::table() {
    return _cc;
}

