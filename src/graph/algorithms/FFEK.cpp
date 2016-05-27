//
// Created by sebri on 27.05.2016.
//

#include <stdexcept>
#include <unordered_map>
#include "FFEK.h"
#include "../graphs/FlowGraph.h"

void FFEK::visit(Graph *g, Vertex *from, Vertex *to) {
    throw runtime_error("Error. "); // TODO
}

void FFEK::visit(DiGraph *g, Vertex *from, Vertex *to) {
    throw runtime_error("Error. "); // TODO
}

void FFEK::visit(FlowGraph *g, Vertex *from, Vertex *to) {
//    if (!g->hasPositiveCapacity()) {
//        throw runtime_error("Error in 'FFEK' algorithm. The flow graph must "
//                                    "have a positive capacity");
//    }
//
//
//
//    Vertex *fromCpy;
//    Vertex *toCpy;
//    FlowGraph *gClone = g->clone();
//    for (Vertex *v : gClone->vertexList()) {
//        if (*v == *from) {
//            fromCpy = v;
//        }
//        if (*v == *to) {
//            toCpy = v;
//        }
//    }
//
//    unordered_map<pair<Vertex*, Vertex*>, FlowEdge*> edgeMap;
//    gClone->forEachEdge([](IEdge *ie){
//        FlowEdge *fe = (FlowEdge*)ie;
//        auto p = make_pair(fe->from(), fe->to());
//        edgeMap.insert(make_pair(p, fe));
//    });
//
//    do {
//
//        gClone->forEachVertex([this, &fromCpy](Vertex *v){
//            _p[v->id()] = nullptr;
//            _cap[v->id()] = 0;
//        });
//        _p[fromCpy->id()] = fromCpy;
//        _cap[fromCpy->id()] = numeric_limits<int>::max();
//        _L.push_back(fromCpy);
//
//        while(!_L.empty()) {
//            Vertex *i = _L.front(); _L.pop_front();
//
//            gClone->forEachAdjacentVertex(i, [this](Vertex *j){
//                FlowEdge *fe = edgeMap.at(make_pair(i,j));
//                if (_p[j->id()] == nullptr && _x[fe->id()] < _u[fe->id()]) {
//                    _p[j->id()] = i;
//                    _cap[j->id()] = min(_cap[i->id()], _u[fe->id()] - _x[fe->id()]);
//                    if (*j == *toCpy) break;
//                    _L.push_back(j);
//                }
//            });
//
//
//        }
//
//    } while (!_end);
}

IGraph *FFEK::G() const {
    return nullptr;
}

std::vector<double> FFEK::table() {
    return std::vector<double>();
}

