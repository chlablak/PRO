//
// Created by sebri on 24.04.2016.
//

#include "Vertex.h"

Vertex::Vertex(const Vertex &v) {
    _id = v.id();
    _label = v.label();
    _minCapacity = v.minCapacity();
    _maxCapacity = v.maxCapacity();
    _weight = v.weight();
}

int Vertex::id() const {
    return _id;
}

string Vertex::label() const {
    return _label;
}

double Vertex::weight() const {
    return _weight;
}

int Vertex::minCapacity() const {
    return _minCapacity;
}

int Vertex::maxCapacity() const {
    return _maxCapacity;
}

void Vertex::setLabel(const string &s) {
    _label = s;
}

void Vertex::setWeight(const double w) {
    _weight = w;
}

void Vertex::setMinCapacity(const int minCap) {
    _minCapacity = minCap;
}

void Vertex::setMaxCapacity(const int maxCap) {
    _maxCapacity = maxCap;
}

void Vertex::setId(const int i) {
    _id = i;
}

ostream &operator<<(ostream &os, const Vertex &v) {
    return os << "(VERTEX) id: " << v.id() << ", \"" << v.label() << "\", weight: "
           << v.weight() << ", min cap: " << v.minCapacity() << ", max cap: "
           << v.maxCapacity();
}
