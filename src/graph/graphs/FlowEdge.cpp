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

void FlowEdge::setMinCapacity(const int &m) {
    _minCapacity = m;
}

void FlowEdge::setMaxCapacity(const int &m) {
    _maxCapacity = m;
}