//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H


#include <string>
#include <list>

class Vertex {
private:
    int _id;
    std::string *_label;
    double *_weight;
    size_t *_minCapacity;
    size_t *_maxCapacity;

public:
    Vertex(const int id, const std::string& label, const double weight,
           const size_t minCap, const size_t maxCap) :
            _id(id), _label (new std::string(label)), _weight (new double(weight)),
            _minCapacity (new size_t(minCap)), _maxCapacity (new size_t(maxCap)){}

    ~Vertex();

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
