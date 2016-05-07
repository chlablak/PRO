//
// Created by sebri on 01.05.2016.
//

#include "BFS.h"
#include "../factory/GraphFactory.h"
#include <limits>
#include <list>

using namespace std;

/**
 * Visit a non-oriented graph
 *
 * @return a tree (graph) containing all accessible vertices from v
 */
Graph& BFS::visitGraph(Graph &g, const Vertex &from) {

    // Table of distances
    distances.assign(g.V(), numeric_limits<int>::max());
    distances.at(from.id()) = 0;

    // Initialize list with from
    list<Vertex> Q;
    Q.push_back(from);

    // Initialize a graph with only vertex 'from' in it
    Graph *result = new Graph({from});

    while (!Q.empty()) {
        Vertex u = Q.front();
        Q.pop_front();

        g.forEachAdjacentVertex(u, [&g, this, &u, &Q](Vertex v){
            if (distances.at(v.id()) == numeric_limits<int>::max()) {
                distances.at(v.id()) = distances.at(u.id()) + 1;
                g.addVertex(v);
                Edge e(u, v);
                g.addEdge(e);
                Q.push_back(v);
            }
        });
    }

    return *result;
}

DiGraph& BFS::visitDiGraph(DiGraph &g, const Vertex &v) {

}

FlowGraph &BFS::visitFlowGraph(FlowGraph &g, const Vertex &from) {
    //return <#initializer#>;
}









