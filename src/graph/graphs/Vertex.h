//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H


#include <string>
#include <list>

class Vertex {
private:
    int id;
    std::string *label;
    double *weight;
    size_t *minCapacity;
    size_t *maxCapacity;

public:
    Vertex(const int id, const std::string& label, const double weight,
           const size_t minCap, const size_t maxCap) :
            id(id), label (new std::string(label)), weight (new double(weight)),
            minCapacity (new size_t(minCap)), maxCapacity (new size_t(maxCap)){}

    ~Vertex();

    // Getters
    int getId() const;
    std::string* getLabel() const;
    double* getWeight() const;
    size_t* getMinCapacity() const;
    size_t* getMaxCapacity() const;

    // Setters
    void setLabel(const std::string& s);
    void setWeight(const double w);
    void setMinCapacity(const size_t minCap);
    void setMaxCapacitiy(const size_t maxCap);
};


#endif //GRAPH_VERTEX_H
