//
// Created by PatrickDesle on 10.05.2016.
//

#include "IEdge.h"


IEdge::IEdge(IEdge *e) {
    _id = e->id();
    _a = e->_a; // Superficial copy
    _b = e->_b; // Superficial copy
    _label = e->label();
    _weight = e->weight();
}


int IEdge::id() const {
    return _id;
}


Vertex *IEdge::vertexA() const {
    return _a;
}

Vertex *IEdge::vertexB() const {
    return _b;
}

string IEdge::label() const {
    return _label;
}

double IEdge::weight() const {
    return _weight;
}

void IEdge::setId(int id) {
    _id = id;
}

void IEdge::setA(Vertex *v) {
    _a = v;
}

void IEdge::setB(Vertex *v) {
    _b = v;
}

void IEdge::setLabel(const string &label) {
    _label = label;
}

void IEdge::setWeight(double weight) {
    _weight = weight;
}
