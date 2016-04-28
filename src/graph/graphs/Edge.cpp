//
// Created by sebri on 24.04.2016.
//

#include "Edge.h"

// Getters
int Edge::id() const { return _id; }
string * Edge::label() const { return  _label; }
double* Edge::weight() const { return  _weight; }
size_t * Edge::minCapacity() const { return _minCapacity; }
size_t * Edge::maxCapacity() const { return _maxCapacity; }
const Vertex* Edge::either() const { return  a; }
const Vertex* Edge::other(const Vertex *v) const { if (a == b) return b; else return a; } // faudra surcharger l'op == pour les vertex
void Edge::deleteItem() {
    if(a != nullptr){
        delete a;
    }
    if(b != nullptr){
        delete b;
    }
    if(_label != nullptr){
        delete _label;
    }
    if(_weight != nullptr){
        delete _weight;
    }
    if(_minCapacity != nullptr){
        delete _minCapacity;
    }
    if(_maxCapacity != nullptr){
        delete _maxCapacity;
    }
}
