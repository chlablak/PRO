//
// Created by sebri on 06.05.2016.
//

#include "DFS.h"

Graph* DFS::visitGraph(Graph &g, Vertex &from) {

//    // Table of vertex discovery order
//    dfsnum.assign(g.V(), 0);
//    N = 1;
//    dfsnum.at(from.id()) = N;
//
//    // Create a graph with only vertex'from'
//    Graph *T = new Graph({from});
//
//    DFSprocedure(T, from);
//
//    return T;
}

DiGraph* DFS::visitDiGraph(DiGraph &g, const Vertex &from) {

}

FlowGraph* DFS::visitFlowGraph(FlowGraph &g, const Vertex &from) {

}

void DFS::DFSprocedure(Graph *g, Vertex &u) {
//    g->forEachAdjacentVertex(u, [&g, &u, this](Vertex *v){
//        if (dfsnum[v->id()] == 0) {
//            ++N;
//            dfsnum[v->id()] = N;
//            g->addVertex(*v);
//            Edge e(u, *v);
//            g->addEdge(e);
//        }
//    });
}





