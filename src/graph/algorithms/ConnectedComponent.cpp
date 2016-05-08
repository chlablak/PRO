//
// Created by sebri on 08.05.2016.
//

#include "ConnectedComponent.h"


Graph *ConnectedComponent::visitGraph(Graph &g, const Vertex &v) {

    cc.assign(g.V(), 0);
    int N = 0;
    g.forEachVertex([&g, &N, this](const Vertex &v){
        if (cc[v.id()] == 0) {
            // Create an empty list
            list<Vertex> Q;
            Q.push_back(v);
            ++N;
            while (!Q.empty()) {
                Vertex u = Q.front();
                Q.pop_front();
                cc[u.id()] = N;
                g.forEachAdjacentVertex(u, [&N, &Q, this](const Vertex &w){
                    if (cc[w.id()] == 0) {
                        cc[w.id()] = N;
                        Q.push_back(w);
                    }
                });
            }
        }
    });

    return &g;
}

DiGraph *ConnectedComponent::visitDiGraph(DiGraph &g, const Vertex &v) {
    return nullptr;
}

FlowGraph *ConnectedComponent::visitFlowGraph(FlowGraph &g, const Vertex &v) {
    return nullptr;
}

