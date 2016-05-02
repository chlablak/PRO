//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H


#include <string>
#include <list>

class Vertex {
private:
    const unsigned int _id;
    std::string *_label;
    double *_weight;
    size_t *_minCapacity;
    size_t *_maxCapacity;

    void deleteItem();

public:
    Vertex(const unsigned int _id) : _id(_id), _weight(nullptr), _label(nullptr), _minCapacity(nullptr) , _maxCapacity(nullptr){ }
    Vertex(const unsigned int _id, const double&  _weight) : Vertex(_id) {this->_weight = new double(_weight); }
    Vertex(const unsigned int _id, const std::string& _label) : Vertex(_id) {this->_label = new std::string (_label); }
    Vertex(const unsigned int _id, const double&  _weight, const std::string& _label) : Vertex(_id, _weight) {this->_label = new std::string(_label);}
    Vertex(const unsigned int _id, const size_t&  _maxCapacity) : Vertex(_id) {this->_maxCapacity = new size_t(_maxCapacity); }
    Vertex(const unsigned int _id, const size_t&  _maxCapacity, const size_t&  _minCapacity) : Vertex(_id, _maxCapacity) {this->_minCapacity = new size_t(_minCapacity); }
    Vertex(const unsigned int _id, const double& _weight, const size_t&  _maxCapacity) : Vertex(_id, _weight) {this->_maxCapacity = new size_t(_maxCapacity); }
    Vertex(const unsigned int _id, const double& weight, const std::string& _label, const size_t& _maxCapacity, const size_t& _minCapacity):
            _id(_id), _label (new std::string(_label)), _weight (new double(weight)),  _maxCapacity (new size_t(_maxCapacity)),
            _minCapacity (new size_t(_minCapacity)){}

    ~Vertex() { deleteItem();}

    // Getters
    int id() const;
    std::string* label() const;
    double* weight() const;
    size_t* minCapacity() const;
    size_t* maxCapacity() const;

    // Setters
    void setLabel(const std::string& s);
    void setWeight(const double w);
    void setMinCapacity(const size_t minCap);
    void setMaxCapacitiy(const size_t maxCap);
};


#endif //GRAPH_VERTEX_H
