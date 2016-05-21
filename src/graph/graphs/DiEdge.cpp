//
// Created by PatrickDesle on 26.04.2016.
//

#include "DiEdge.h"

string DiEdge::toString() const {
    string s = "(DI EDGE) ";
    s.append(EdgeCommon::toString());
    return s;
}

