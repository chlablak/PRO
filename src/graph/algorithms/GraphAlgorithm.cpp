//
// Created by sebri on 15.05.2016.
//

#include "GraphAlgorithm.h"

#include "BFS.h"

IGraph *GraphAlgorithm::bfs(Graph *g, Vertex *from, vector<int>& distances) {
    Visitor *v = new BFS;
    v->visit(g, from);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::bfs(DiGraph *g, Vertex *from, vector<int> *distances) {
    return nullptr;
}

IGraph *GraphAlgorithm::bfs(FlowGraph *g, Vertex *from, vector<int> *distances) {
    return nullptr;
}

