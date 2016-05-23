//
// Created by PatrickDesle on 10.05.2016.
//

#include "FlowEdge.h"

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

FlowEdge::FlowEdge(const FlowEdge &e) : DiEdgeCommon(e) {
    _minCapacity = e._minCapacity;
    _maxCapacity = e._maxCapacity;
}

string FlowEdge::toString() const {
    string s = "(FLOW EDGE) ";
    s.append(EdgeCommon::toString());
    s.append(", min cap: ");
    s.append(patch::to_string(minCapacity()));
    s.append(", max cap: ");
    s.append(patch::to_string(maxCapacity()));
    return s;
}



