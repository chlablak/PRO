//
// Created by PatrickDesle on 10.05.2016.
//

#include <stdexcept>
#include "FlowEdge.h"

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const int &minCapacity,
                   const int &maxCapacity) : DiEdgeCommon(from, to) {
    setCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const string &label,
                   const int &minCapacity, const int &maxCapacity) : DiEdgeCommon(from, to, label){
    setCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const double weight,
                   const int &minCapacity, const int &maxCapacity) : DiEdgeCommon(from, to, weight){
    setCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const string &label,
                   const double weight, const int &minCapacity,
                   const int &maxCapacity) : DiEdgeCommon(from, to, label, weight){
    setCapacity(minCapacity, maxCapacity);
}


void FlowEdge::setCapacity(const int minCapacity, const int maxCapacity) {
    if (minCapacity > maxCapacity || minCapacity < 0 || maxCapacity < 0) {
        throw runtime_error("Error in FlowEdge initialization with constructor."
                                    "'maxCapacity' can't be greater than "
                                    "'minCapacity' and both need positive or "
                                    "null value");
    }
    _minCapacity = minCapacity;
    _maxCapacity = maxCapacity;
    _flow = 0;
}

int FlowEdge::minCapacity() const {
    return _minCapacity;
}

int FlowEdge::maxCapacity() const {
    return _maxCapacity;
}

void FlowEdge::setMinCapacity(const int m) {
    _minCapacity = m;
}

void FlowEdge::setMaxCapacity(const int m) {
    _maxCapacity = m;
}

string FlowEdge::toString() const {
    string s = "(FLOW EDGE) ";
    s.append(EdgeCommon::toString());
    s.append(", min cap: ");
    s.append(utility::toString(minCapacity()));
    s.append(", max cap: ");
    s.append(utility::toString(maxCapacity()));
    return s;
}

int FlowEdge::flow() const {
    return _flow;
}

void FlowEdge::setFlow(const int f) {
    _flow = f;
}



