//
// Created by sebri on 18.05.2016.
//

#include <set>
#include "Dijkstra.h"
#include "../graphs/DiGraph.h"
#include "../../utility/Global.h"

void Dijkstra::visit(Graph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
}

void Dijkstra::visit(DiGraph *g, Vertex *from) {
    UNUSED(from);

    if (g->isNegativeWeighted()) {
        throw std::runtime_error("Error in Dijkstra algorithm. The graph must be only null or positive weighted");
    }

    typedef std::pair<double, Vertex*> WeightVertex;

    std::set<WeightVertex> pq;
    std::vector<int> marques;
}

void Dijkstra::visit(FlowGraph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
}

IGraph *Dijkstra::G() const {
    return _G;
}

std::vector<int> &Dijkstra::table() {
    throw std::runtime_error("no table in Dijkstra");
}