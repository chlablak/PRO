//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H


#include <string>
#include "Vertex.h"

using namespace std;

class Edge {
private:
    const int id;
    const Vertex *a, *b;
    string* label;
    double* weight;
    size_t* minCapacity;
    size_t* maxCapacity;

public:
    // Constructors
    Edge(const Vertex* from, const Vertex* to, const int id);
    Edge(const Vertex* from, const Vertex* to, const int id, const string& label);
    Edge(const Vertex* from, const Vertex* to, const int id, const double weight);
    Edge(const Vertex* from, const Vertex* to, const int id, const double weight, const string& label);
    Edge(const Vertex* from, const Vertex* to, const int id,
         const string& label, const double weight,
         const size_t minCap, const size_t maxCap) :
            a(from), b(to), id(id),
            label (new string(label)), weight (new double(weight)),
            minCapacity (new size_t(minCap)), maxCapacity (new size_t(maxCap)){}
    ~Edge();

    // Getters
    int getId() const;
    string* getLabel() const;
    double* getWeight() const;
    size_t* getMinCapacity() const;
    size_t* getMaxCapacity() const;

    // Setters
    void setLabel(const string& s);
    void setWeight(const double w);
    void setMinCapacity(const size_t minCap);
    void setMaxCapacitiy(const size_t maxCap);
};


#endif //GRAPH_EDGE_H
