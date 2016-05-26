//
// Created by PatrickDesle on 23.05.2016.
//

#include <stdexcept>
#include "TopologicalSort.h"
#include "GraphAlgorithm.h"

bool TopologicalSort::isDAG(IGraph *g) const {
    IGraph *gCycle = GraphAlgorithm::detectCycle(g);
    return gCycle == nullptr;
}

void TopologicalSort::fillPredessessors(IGraph *g) {
    for(auto v : g->vertexList())
    {
        // for each successor u of vertex v, we add v to the list of predessessor of u
        for(auto iedge : g->adjacentEdges(v)){
            _predessessorsList.at(iedge->to()->id()).push_back(v);
        }
    }
}

void TopologicalSort::order(IGraph *g) {

    vector<size_t > inputDegree(g->V()); inputDegree.assign(g->V(), 0);
    list<Vertex *> L; // L will content the list of vertex without predessessor and that are not yet order
    double rang = 1;
    size_t degree;
    Vertex * current;

    // we calculate the input degree of each vertex
    for(auto v : g->vertexList())
    {
        degree = 0;
        for(auto u : _predessessorsList.at(v->id()))
        {
            degree++;
        }
        inputDegree.at(v->id()) = degree;
        if(inputDegree.at(v->id()) == 0)
        {
            L.push_back(v);
        }
    }

    while(!L.empty())
    {
        current = L.front(); L.pop_front();
        _order.at(current->id()) = rang;
        rang = rang + 1;
        for(auto iedge : g->adjacentEdges(current))
        {
            inputDegree.at(iedge->to()->id()) -= 1;
            if(inputDegree.at(iedge->to()->id()) == 0)
            {
                L.push_back(iedge->to());
            }
        }

    }
}

void TopologicalSort::visit(Graph *g, Vertex *from) {
    throw std::runtime_error("A topological sort can't be apply to a graph. The graph should be directed");
}

void TopologicalSort::visit(DiGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new Graph;
        return;
    }
    if(!isDAG(g))
    {
        throw std::runtime_error("A topological sort can't be apply to a directed cyclic graph. The graph should be acyclic");
    }
    UNUSED(from);
    IGraph * gClone = g->clone();
    _predessessorsList.resize(gClone->V());
    _order.resize(gClone->V());

    fillPredessessors(gClone);
    order(gClone);



}

void TopologicalSort::visit(FlowGraph *g, Vertex *from) {

    if (g->isNull()) {
     _G = new Graph;
     return;
    }
    if(!isDAG(g))
    {
         throw std::runtime_error("A topological sort can't be apply to a directed cyclic graph. The graph should be acyclic");
    }
    UNUSED(from);
    IGraph * gClone = g->clone();
    _predessessorsList.resize(gClone->V());
    _order.resize(gClone->V());

    fillPredessessors(gClone);
    order(gClone);
}

IGraph *TopologicalSort::G() const {
    return _G;
}

std::vector<double> TopologicalSort::table() {
    return _order;
}

















