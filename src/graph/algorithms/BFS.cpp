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
Graph BFS::visitGraph(Graph &g, const Vertex &v) {

    // Table of distances
    vector<int> d;
    d.assign(g.V(), numeric_limits<int>::max());
    d.at(v.id()) = 0;

    // Initialize list with v
    list<Vertex> Q;
    Q.push_back(v);

    // Initialize a graph with only vertex v
    Graph result = GraphFactory::getInstance().createGraph({v});

    while (!Q.empty()) {
        Vertex u = Q.front();
        Q.pop_front();

        g.forEachAdjacentVertex(u, [&g](Vertex v){
            if (d.at(v.id()) == numeric_limits<int>::max()) {
                d.at(v.id()) = d.at(u.id()) + 1;
                g.addVertex(v);
                g.addEdge(u, v);
                Q.push_back(v);
            }
        });
    }

    return result;
}

DiGraph BFS::visitDiGraph(DiGraph &g, const Vertex &v) {
    return DiGraph(std::vector<Vertex>(), std::vector<Edge>());
}



