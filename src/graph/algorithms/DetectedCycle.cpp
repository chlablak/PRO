//
// Created by PatrickDesle on 23.05.2016.
//

#include <stack>
#include "DetectedCycle.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"


void DetectedCycle::visit(Graph *g, Vertex *from) {

    if (g->isNull()) {
        _G = new Graph;
        return;
    }
    UNUSED(from);

    _marked.resize(g->V(), false);
    _stacked.resize(g->V(), false);

    Graph *gClone = g->clone();

    for(Vertex* u : gClone->vertexList()){
        hasCycle(u, u->id(), gClone);
        if(cycleFounded){
            break;
        }
    }

    if(cycleFounded) {

        // Initialize _G with an empty graph
        _G = gClone->emptyClone();

        // we add the vertex of the cycle to _G
        for (unsigned int i = 0; i < _cycle.size() - 1; ++i) {
            _G->assignVertex(_cycle.at(i));
        }
        // we add the edge to _G
        unsigned int i = 0;
        for (i = 0; i < (_cycle.size() - 1); ++i) {
            _G->assignEdge(gClone->getEdges(_cycle.at(i), _cycle.at(i + 1)).front());
        }
    }


}

void DetectedCycle::visit(DiGraph *g, Vertex *from) {

    if (g->isNull()) {
        _G = new DiGraph;
        return;
    }
    UNUSED(from);

    // Initialize _G with the an empty DiGraph
    DiGraph *gClone = g->clone();

    _marked.resize(g->V(), false);
    _stacked.resize(g->V(), false);

    commonFlowDiGraph(gClone);
}

void DetectedCycle::visit(FlowGraph *g, Vertex *from) {
    if (g->isNull()) {
        _G = new FlowGraph;
        return;
    }
    UNUSED(from);

    // Initialize _G with an empty FlowGraph
    IGraph *gClone = g->clone();

    _marked.resize(gClone->V(), false);
    _stacked.resize(gClone->V(), false);

    commonFlowDiGraph(gClone);
}

IGraph *DetectedCycle::G() const {
    return _G;
}

std::vector<double> DetectedCycle::table() {
    throw std::runtime_error("no table in Detected Cycle");
}



void DetectedCycle::hasCycleDirected(Vertex *v, IGraph* g) {

    _marked.at(v->id()) = true;
    _stacked.at((v->id())) =  true;
    _cycle.push_back(v);

    for(IEdge *edge : g->adjacentEdges(v)){

        if(cycleFounded){
            return;
        }
        else if(!_marked.at(edge->to()->id())){
            hasCycleDirected(edge->to(), g);
        }
        else if(_stacked.at(edge->to()->id())){
            cycleFounded = true;
            _cycle.push_back(edge->to());
        }
    }

    if(!cycleFounded){
        _stacked.at(v->id()) = false;
        _cycle.pop_back();
    }


}
void DetectedCycle::hasCycle(Vertex *v, int fromId, IGraph *g) {
    _marked.at(v->id()) = true;
    _stacked.at((v->id())) =  true;
    _cycle.push_back(v);

    for(IEdge *edge : g->adjacentEdges(v)){

        if(fromId == edge->other(v)->id()){
            continue;
        }
        if(cycleFounded){
            return;
        }
        else if(!_marked.at(edge->other(v)->id())){
            hasCycle(edge->other(v), v->id(), g);
        }
        else if(_stacked.at(edge->other(v)->id())){
            cycleFounded = true;
            _cycle.push_back(edge->other(v));
        }
    }

    if(!cycleFounded){
        _stacked.at(v->id()) = false;
        _cycle.pop_back();
    }
}

void DetectedCycle::commonFlowDiGraph(IGraph *g) {

    for(Vertex* u : g->vertexList()){
        hasCycleDirected(u, g);
        if(cycleFounded){
            break;
        }
    }

    if(cycleFounded) {
        // Initialize _G with an empty graph
        _G = g->emptyClone();

        // we add the vertex of the cycle to _G
        for (unsigned int i = 0; i < _cycle.size() - 1; ++i) {
            _G->assignVertex(_cycle.at(i));
        }
        // we add the edge to _G
        unsigned int i = 0;
        for (i = 0; i < (_cycle.size() - 1); ++i) {
            _G->assignEdge(g->getEdges(_cycle.at(i), _cycle.at(i + 1)).front());
        }
    }
}

bool DetectedCycle::hasCycle() const {
    return cycleFounded;
}










