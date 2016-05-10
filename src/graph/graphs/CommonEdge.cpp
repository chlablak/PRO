//
// Created by PatrickDesle on 10.05.2016.
//

#include "CommonEdge.h"

int CommonEdge::id() const {
    return _id;
}

string CommonEdge::label() const {
    return _label;
}

void CommonEdge::setId(int id) {
    _id = id;
}
