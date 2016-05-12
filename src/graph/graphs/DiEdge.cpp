//
// Created by PatrickDesle on 26.04.2016.
//

#include "DiEdge.h"


DiEdge::DiEdge(DiEdge *e) : IEdge(e) {
    _minCapacity = e->_minCapacity;
    _maxCapacity = e->_maxCapacity;
}


Vertex* DiEdge::from() { return _a; }
Vertex* DiEdge::to() { return _b; }