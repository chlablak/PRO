//
// Created by PatrickDesle on 10.05.2016.
//

#include <stdexcept>
#include "FlowEdge.h"

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const int &minCapacity,
                   const int &maxCapacity) : DiEdgeCommon(from, to) {
    checkCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const string &label,
                   const int &minCapacity, const int &maxCapacity) : DiEdgeCommon(from, to, label){
    checkCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const double weight,
                   const int &minCapacity, const int &maxCapacity) : DiEdgeCommon(from, to, weight){
    checkCapacity(minCapacity, maxCapacity);
}

FlowEdge::FlowEdge(Vertex *from, Vertex *to, const string &label,
                   const double weight, const int &minCapacity,
                   const int &maxCapacity) : DiEdgeCommon(from, to, label, weight){
    checkCapacity(minCapacity, maxCapacity);
}


void FlowEdge::checkCapacity(const int minCapacity, const int maxCapacity) {
    if (minCapacity > maxCapacity) {
        throw runtime_error("Error in FlowEdge initialization with constructor."
                                    "'maxCapacity' can't be greater than 'minCapacity'");
    }
    _minCapacity = minCapacity;
    _maxCapacity = maxCapacity;
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