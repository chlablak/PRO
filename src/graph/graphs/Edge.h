//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H


#include <string>
#include "Vertex.h"

using namespace std;

class Edge {

protected:
    const int _id;
    const Vertex *a, *b;
    string* _label;
    double* _weight;
    size_t* _minCapacity;
    size_t* _maxCapacity;

    void deleteItem();

public:
    // Constructors

    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to) : _id(_id), a(_from), b(_to), _label(nullptr), _weight(nullptr),
                                                                         _minCapacity(nullptr), _maxCapacity(nullptr) {}
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double&  _weight) : Edge(_id, _from, _to) {this->_weight = new double(_weight); }
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const std::string& _label) : Edge(_id, _from, _to) {this->_label = new std::string (_label); }
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double&  _weight, const std::string& _label) : Edge(_id, _from, _to, _weight) {this->_label = new std::string(_label);}
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const size_t&  _maxCapacity) : Edge(_id, _from, _to) {this->_maxCapacity = new size_t(_maxCapacity); }
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const size_t&  _maxCapacity, const size_t&  _minCapacity) : Edge(_id,_from, _to, _maxCapacity) {this->_minCapacity = new size_t(_minCapacity); }
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double& _weight, const size_t&  _maxCapacity) : Edge(_id, _from, _to, _weight) {this->_maxCapacity = new size_t(_maxCapacity); }
    Edge(const unsigned int _id, const Vertex* _from, const Vertex* _to, const double& _weight, const std::string& _label, const size_t& _maxCapacity, const size_t& _minCapacity):
            _id(_id), a(_from), b(_to), _label (new std::string(_label)), _weight (new double(_weight)),  _maxCapacity (new size_t(_maxCapacity)),
            _minCapacity (new size_t(_minCapacity)){}

    virtual ~Edge(){
        deleteItem();
    }

    // Getters
    unsigned int id() const;
    string* label() const;
    double* weight() const;
    size_t* minCapacity() const;
    size_t* maxCapacity() const;
    const Vertex* either() const;
    const Vertex* other(const Vertex* v) const;

    // Setters
    void setLabel(const string& s);
    void setWeight(const double w);
    void setminCapacity(const size_t minCap);
    void setMaxCapacitiy(const size_t maxCap);


    // opérateurs

};


#endif //GRAPH_EDGE_H
