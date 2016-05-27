//
// Created by sebri on 15.05.2016.
//

#include "GraphAlgorithm.h"

// Visitors
#include "BFS.h"
#include "DFS.h"
#include "ConnectedComponent.h"
#include "Kruskal.h"
#include "Prim.h"
#include "CopyToDiGraph.h"
#include "CopyToGraph.h"
#include "CopyToFlowGraph.h"
#include "SCCTarjan.h"
#include "BellmanFordSP.h"
#include "DijkstraSP.h"
#include "DetectedCycle.h"
#include "TopologicalSort.h"
#include "PushRelabel.h"

IGraph *GraphAlgorithm::bfs(IGraph *g, Vertex *from, vector<double>& distances) {
    Visitor *v = new BFS;
    g->accept(v, from, nullptr);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::dfs(IGraph *g, Vertex *from, vector<double> &dfsnum) {
    Visitor *v = new DFS;
    g->accept(v, from, nullptr);
    dfsnum = v->table();
    return v->G();
}

vector<double> GraphAlgorithm::connectedComponent(IGraph *g) {
    Visitor *v = new ConnectedComponent;
    g->accept(v, nullptr, nullptr);
    return v->table();
}

vector<double> GraphAlgorithm::stronglyConnectedComponent(IGraph *g) {
    Visitor *v = new SCCTarjan;
    g->accept(v, nullptr, nullptr);
    return v->table();
}

IGraph *GraphAlgorithm::kruskal(IGraph *g) {
    Visitor *v = new Kruskal;
    g->accept(v, nullptr, nullptr);
    return v->G();
}

IGraph *GraphAlgorithm::prim(IGraph *g, Vertex *from) {
    Visitor *v = new Prim;

    if (from == nullptr) {
        from = g->vertexList().front();
    }

    g->accept(v, from, nullptr);
    return v->G();
}

IGraph *GraphAlgorithm::copyToDiGraph(IGraph *g) {
    Visitor *v = new CopyToDiGraph;
    g->accept(v, nullptr, nullptr);
    return v->G();
}

IGraph *GraphAlgorithm::copyToGraph(IGraph *g) {
    Visitor *v = new CopyToGraph;
    g->accept(v, nullptr, nullptr);
    return v->G();
}

IGraph *GraphAlgorithm::copyToFlowGraph(IGraph *g) {
    Visitor *v = new CopyToFlowGraph;
    g->accept(v, nullptr, nullptr);
    return v->G();
}

IGraph *GraphAlgorithm::bellmanFord(IGraph *g, Vertex *from, vector<double>& distances) {
    Visitor *v = new BellmanFordSP;
    g->accept(v, from, nullptr);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::dijkstra(IGraph *g, Vertex *from, vector<double>& distances) {
    Visitor *v = new DijkstraSP;
    g->accept(v, from, nullptr);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::detectCycle(IGraph *g) {
    Visitor *v = new DetectedCycle;
    g->accept(v, g->vertexList().front(), nullptr);
    return v->G();
}

vector<double> GraphAlgorithm::topoloqicalSort(IGraph *g) {
    Visitor *v = new TopologicalSort;
    g->accept(v, g->vertexList().front(), nullptr);
    return v->table();
}

int GraphAlgorithm::maxFlow(IGraph *g, Vertex *from, Vertex *to) {
    Visitor *v = new PushRelabel(g->V());
    g->accept(v, from, to);
    return 0;
}










