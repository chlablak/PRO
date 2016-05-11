//
// Created by sebri on 24.04.2016.
//

#include "Edge.h"



// Getters
Vertex* Edge::either() const { return _a; }

Vertex* Edge::other(Vertex *v) const {
    return v == this->_a ? this->_b : this->_a;
}

// TODO surcharger l'op == pour les vertex


ostream &operator<<(ostream &os, const Edge &e) {
    return os << "(EDGE) " << (e.either())->id() << "--" << (e.other(e.either()))->id()
           << " id: " << e.id() << ", \"" << e.label() << "\", weight: " << e.weight();
}

Edge::Edge(const Edge &e) {
    _id = e._id;
    _a = new Vertex(*e._a);
    _b = new Vertex(*e._b);
    _label = e._label;
}






