//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "Edge.h"



class DiEdge : public Edge {

public:
    // Constructors

    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to) : Edge(_id, _from, _to) {}
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double&  _weight) : Edge(_id, _from, _to) {this->_weight = new double(_weight); }
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const std::string& _label) : Edge(_id, _from, _to) {this->_label = new std::string (_label); }
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double&  _weight, const std::string& _label) : Edge(_id, _from, _to, _weight) {this->_label = new std::string(_label);}
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const size_t&  _maxCapacity) : Edge(_id, _from, _to) {this->_maxCapacity = new size_t(_maxCapacity); }
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const size_t&  _maxCapacity, const size_t&  _minCapacity) : Edge(_id,_from, _to, _maxCapacity) {this->_minCapacity = new size_t(_minCapacity); }
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double& _weight, const size_t&  _maxCapacity) : Edge(_id, _from, _to, _weight) {this->_maxCapacity = new size_t(_maxCapacity); }
    DiEdge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double& _weight, const std::string& _label, const size_t& _maxCapacity, const size_t& _minCapacity):
            Edge(_id, _from, _to, _weight, _label, _maxCapacity, _minCapacity) {}

    virtual ~DiEdge(){
        deleteItem();
    }

    const Vertex *from();
    const Vertex *to();




};


#endif //SRC_DiEdge_H
