//
// Created by PatrickDesle on 26.04.2016.
//

#include "DiEdge.h"


const Vertex* DiEdge::from() { return either(); }
const Vertex* DiEdge::to() { return other(either()); }