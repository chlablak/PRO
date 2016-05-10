//
// Created by PatrickDesle on 10.05.2016.
//

#include "WeightedEdge.h"

double WeightedEdge::weight() const {
    return _weight;
}

void WeightedEdge::setWeight(const double &w) {
    _weight = w;
}