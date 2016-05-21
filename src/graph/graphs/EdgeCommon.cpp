//
// Created by sebri on 20.05.2016.
//

#include "EdgeCommon.h"


EdgeCommon::EdgeCommon(const EdgeCommon& e) {
    _id = e.id();
    _a = e.vertexA(); // Superficial copy
    _b = e.vertexB(); // Superficial copy
    _label = e.label();
    _weight = e.weight();
}


int EdgeCommon::id() const {
    return _id;
}


Vertex *EdgeCommon::vertexA() const {
    return _a;
}

Vertex *EdgeCommon::vertexB() const {
    return _b;
}

string EdgeCommon::label() const {
    return _label;
}

double EdgeCommon::weight() const {
    return _weight;
}

void EdgeCommon::setId(int id) {
    _id = id;
}

void EdgeCommon::setA(Vertex *v) {
    _a = v;
}

void EdgeCommon::setB(Vertex *v) {
    _b = v;
}

void EdgeCommon::setLabel(const string &label) {
    _label = label;
}

void EdgeCommon::setWeight(double weight) {
    _weight = weight;
}

string EdgeCommon::toString() const {
    string s;
    s.append(vertexA()->label());
    s.append("(");
    s.append(patch::to_string(vertexA()->id()));
    s.append(") ");
    s.append(edgeStyle());
    s.append(" (");
    s.append(patch::to_string(vertexB()->id()));
    s.append(")");
    s.append(vertexB()->label());
    s.append(" id: ");
    s.append(patch::to_string(id()));
    s.append(", \"");
    s.append(label());
    s.append("\", weight: ");
    s.append(patch::to_string(weight()));

    return s;
}


ostream &operator<<(ostream &os, const EdgeCommon &e) {
    return os << e.toString();
}