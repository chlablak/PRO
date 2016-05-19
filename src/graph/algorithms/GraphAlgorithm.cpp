//
// Created by sebri on 15.05.2016.
//

#include "GraphAlgorithm.h"

#include "BFS.h"
#include "DFS.h"
#include "ConnectedComponent.h"
#include "Kruskal.h"
#include "Prim.h"

IGraph *GraphAlgorithm::bfs(IGraph *g, Vertex *from, vector<int>& distances) {
    Visitor *v = new BFS;
    if (dynamic_cast<Graph*>(g)) {
        v->visit((Graph*)g, from);
    }
    else if (dynamic_cast<DiGraph*>(g)) {
        v->visit((DiGraph*)g, from);
    }
    else {
        v->visit((FlowGraph*)g, from);
    }
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::dfs(IGraph *g, Vertex *from, vector<int> &dfsnum) {
    Visitor *v = new DFS;
    if (dynamic_cast<Graph*>(g)) {
        v->visit((Graph*)g, from);
    }
    else if (dynamic_cast<DiGraph*>(g)) {
        v->visit((DiGraph*)g, from);
    }
    else {
        v->visit((FlowGraph*)g, from);
    }
    dfsnum = v->table();
    return v->G();
}

vector<int> &GraphAlgorithm::connectedComponent(IGraph *g) {
    Visitor *v = new ConnectedComponent;
    if (dynamic_cast<Graph*>(g)) {
        v->visit((Graph*)g, nullptr);
    }
    else if (dynamic_cast<DiGraph*>(g)) {
        v->visit((DiGraph*)g, nullptr);
    }
    else {
        v->visit((FlowGraph*)g, nullptr);
    }
    return v->table();
}

IGraph *GraphAlgorithm::kruskal(IGraph *g) {
    Visitor *v = new Kruskal;
    if (dynamic_cast<Graph*>(g)) {
        v->visit((Graph*)g, nullptr);
    }
    else if (dynamic_cast<DiGraph*>(g)) {
        v->visit((DiGraph*)g, nullptr);
    }
    else {
        v->visit((FlowGraph*)g, nullptr);
    }
    return v->G();
}

IGraph *GraphAlgorithm::prim(IGraph *g, Vertex *from = nullptr) {
    Visitor *v = new Prim;

    if (from == nullptr) {
        from = g->vertexList().front();
    }

    if (dynamic_cast<Graph*>(g)) {
        v->visit((Graph*)g, from);
    }
    else if (dynamic_cast<DiGraph*>(g)) {
        v->visit((DiGraph*)g, from);
    }
    else {
        v->visit((FlowGraph*)g, from);
    }
    return v->G();
}











