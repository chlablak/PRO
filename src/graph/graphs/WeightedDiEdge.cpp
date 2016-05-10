//
// Created by PatrickDesle on 10.05.2016.
//

#include "WeightedDiEdge.h"


 double WeightedDiEdge::weight() const {
     return _weight;
 }

 void WeightedDiEdge::setWeight(const double &w) {
    _weight = w;
 }