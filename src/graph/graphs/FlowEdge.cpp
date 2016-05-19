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

//FlowEdge::FlowEdge(const FlowEdge &e) {
//    _id = e._id;
//    _a = new Vertex(*e._a);
//    _b = new Vertex(*e._b);
//    _label = e._label;
//    _minCapacity = e._minCapacity;
//    _maxCapacity = e._maxCapacity;
//}

