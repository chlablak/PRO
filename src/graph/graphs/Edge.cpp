//
// Created by sebri on 24.04.2016.
//

#include "Edge.h"



// Getters
Vertex* Edge::either() const { return _a; }

Vertex* Edge::other(Vertex *v) const {
    return v == this->_a ? this->_b : this->_a;
}

Vertex *Edge::from() const {
    return either();
}

Vertex *Edge::to() const {
    return other(either());
}

// TODO surcharger l'op == pour les vertex

ostream &operator<<(ostream &os, const Edge &e) {
    return os << "(EDGE) " << *dynamic_cast<const IEdge*>(&e);
}

