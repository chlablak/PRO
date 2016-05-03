//
// Created by sebri on 24.04.2016.
//

#include "Edge.h"

// Getters
unsigned int Edge::id() const { return _id; }

string Edge::label() const { return _label; }

double Edge::weight() const { return _weight; }

int Edge::minCapacity() const { return _minCapacity; }

int Edge::maxCapacity() const { return _maxCapacity; }

const Vertex *Edge::either() const { return _a; }

const Vertex *Edge::other(const Vertex& v) const {
    return &v == this->_a ? this->_b : this->_a;
}

// TODO surcharger l'op == pour les vertex

void Edge::deleteItem() {
    // We don't delete the vertices
}

void Edge::setId(const int i) {
    _id = i;
}

ostream &operator<<(ostream &os, const Edge &e) {
    return os << "(EDGE) " << (e.either())->id() << "--" << (e.other(*e.either()))->id()
           << " id: " << e.id() << ", \"" << e.label() << "\", weight: "
           << e.weight() << ", min cap: " << e.minCapacity() << ", max cap: "
           << e.maxCapacity();
}




