//
// Created by sebri on 16.05.2016.
//

#include <stdexcept>
#include "Prim.h"

#include "../graphs/Graph.h"

void Prim::visit(Graph *g, Vertex *from) {
    if (!g->isSimple()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must be simple.");
    }
    if (!g->isConnected()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must be connected.");
    }
    if (!g->isPonderate()) {
        throw std::runtime_error("Error in Prim algorithm. The graph must have a ponderation.");
    }

    vector<int> lamba;
    vector<int*> p;
    lamba.assign(g->V(), numeric_limits<int>::max());
    p.assign(g->V(), nullptr);

    lamba[from->id()] = 0;
    _G = new Graph;
    std::list<Vertex *> L = g->vertexList();

    while (!L.empty()) {
        // Get vertex from L of smallest mark lamba

    }
}

void Prim::visit(DiGraph *g, Vertex *from) {

}

void Prim::visit(FlowGraph *g, Vertex *from) {

}

IGraph *Prim::G() const {
    return nullptr;
}

std::vector<int> &Prim::table() {
    throw std::runtime_error("No table for that algorithm");
}

