//
// Created by PatrickDesle on 10.05.2016.
//

#include "IEdge.h"

int IEdge::id() const {
    return _id;
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

void IEdge::setLabel(const string &label) {
    _label = label;
}

void IEdge::setWeight(double weight) {
    _weight = weight;
}
