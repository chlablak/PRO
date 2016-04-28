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
    Edge(const Vertex* from, const Vertex* to, const int id) : a(from), b(to), _id(id), _label(nullptr), _weight(nullptr),
                                                               _minCapacity(nullptr), _maxCapacity(nullptr) {}
    Edge(const Vertex* from, const Vertex* to, const int id, const string& _label) : Edge::Edge(from, to, id)  { this->_label = new string(_label);}
    Edge(const Vertex* from, const Vertex* to, const int id, const double& _weight) : Edge::Edge(from, to, id) { this->_weight = new double(_weight);}
    Edge(const Vertex* from, const Vertex* to, const int id, const double& _weight, const string& _label) : Edge::Edge(from, to, id, _weight){ this->_label = new string(_label);}
    Edge(const Vertex* from, const Vertex* to, const int id, const string& _label, const double& _weight , const size_t minCap, const size_t maxCap) :
            a(from), b(to), _id(id),
            _label (new string(_label)), _weight (new double(_weight)),
            _minCapacity (new size_t(minCap)), _maxCapacity (new size_t(maxCap)){}
    ~Edge(){
        deleteItem();
    };

    // Getters
    int id() const;
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
};


#endif //GRAPH_EDGE_H
