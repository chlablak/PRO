//
// Created by PatrickDesle on 26.04.2016.
//

#include "DiEdge.h"


DiEdge::DiEdge(const DiEdge &e) : IEdge(e) {
    _minCapacity = e._minCapacity;
    _maxCapacity = e._maxCapacity;
}


Vertex* DiEdge::from() const { return _a; }
Vertex* DiEdge::to() const { return _b; }

Vertex *DiEdge::either() const {
    return either();
}

Vertex *DiEdge::other(Vertex *v) const {
    return other(either());
}