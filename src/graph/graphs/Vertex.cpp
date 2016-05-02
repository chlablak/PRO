//
// Created by sebri on 24.04.2016.
//

#include "Vertex.h"


int Vertex::id() const {return _id; }
std::string* Vertex::label() const { return  _label; }
double* Vertex::weight() const { return _weight;}
size_t* Vertex::minCapacity() const {return _minCapacity; }
size_t* Vertex::maxCapacity() const { return  _maxCapacity; }
void Vertex::setLabel(const std::string &s) { *_label = s; }
void Vertex::setWeight(const double w) {*_weight = w; }
void Vertex::setMinCapacity(const size_t minCap) { *_minCapacity = minCap; }
void Vertex::setMaxCapacitiy(const size_t maxCap) { *_maxCapacity = maxCap; }

void Vertex::deleteItem() {
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