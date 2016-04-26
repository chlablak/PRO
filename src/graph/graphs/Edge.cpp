//
// Created by sebri on 24.04.2016.
//

#include "Edge.h"

// Getters
int Edge::getId() const { return id; }
string * Edge::getLabel() const { return  label; }
double* Edge::getWeight() const { return  weight; }
size_t * Edge::getMinCapacity() const { return minCapacity; }
size_t * Edge::getMaxCapacity() const { return maxCapacity; }
Vertex* Edge::getEither() const { return  a; }
Vertex* Edge::getOther(const Vertex *v) const { if (a == b) return b; else return a; } // faudra surcharger l'op == pour les vertex
void Edge::deleteItem() {
    if(a != nullptr){
        delete a;
    }
    if(b != nullptr){
        delete b;
    }
    if(label != nullptr){
        delete label;
    }
    if(weight != nullptr){
        delete weight;
    }
    if(minCapacity != nullptr){
        delete minCapacity;
    }
    if(maxCapacity != nullptr){
        delete maxCapacity;
    }
}
