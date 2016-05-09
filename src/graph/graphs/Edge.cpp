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

void Edge::setWeight(const double w) {
    _weight = w;
}
// TODO surcharger l'op == pour les vertex

void Edge::deleteItem() {
    if(_a != nullptr){
        delete _a;
        _a = nullptr;
    }
    if(_b != nullptr){
        delete _b;
        _b = nullptr;
    }

}

void Edge::setId(const int i) {
    _id = i;
}

bool Edge::operator==(const Edge *e) const {
    return _id == e->_id;
}

ostream &operator<<(ostream &os, const Edge &e) {
    return os << "(EDGE) " << (e.either())->id() << "--" << (e.other(*e.either()))->id()
           << " id: " << e.id() << ", \"" << e.label() << "\", weight: "
           << e.weight() << ", min cap: " << e.minCapacity() << ", max cap: "
           << e.maxCapacity();
}




