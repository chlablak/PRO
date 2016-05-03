//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include <string>
#include <list>
#include <limits>
#include <iostream>

using namespace std;

class Vertex {
private:
    int _id;
    string _label;
    double _weight;
    int _minCapacity;
    int _maxCapacity;

    void deleteItem();

public:
    Vertex()
            : _id(-1), _weight(numeric_limits<double>::max()), _label(""), _minCapacity(-1),
              _maxCapacity(-1) { }

    Vertex(const string& label)
            : _id(-1), _weight(numeric_limits<double>::max()), _label(label), _minCapacity(-1),
              _maxCapacity(-1) { }

    Vertex(const double& weight)
            : _id(-1), _label(nullptr), _weight(weight),
              _minCapacity(-1), _maxCapacity(-1) { }

    Vertex(const double& weight, const string& label)
            : _id(-1), _weight(weight), _label(label),
              _minCapacity(-1), _maxCapacity(-1) { }

    Vertex(const int& maxCapacity)
            : _id(-1), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(0), _maxCapacity(maxCapacity) { }

    Vertex(const int& minCapacity, const int& maxCapacity)
            : _id(-1), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(minCapacity),
              _maxCapacity(maxCapacity) { }

    Vertex(const double& weight, const int& maxCapacity)
            : _id(-1), _label(""), _weight(weight),
              _minCapacity(0),
              _maxCapacity(maxCapacity) { }

    Vertex(const double& weight, const string& label,
           const int& minCapacity, const int& maxCapacity)
            : _id(-1), _label(label), _weight(weight),
              _minCapacity(minCapacity),
              _maxCapacity(maxCapacity) { }

    ~Vertex() { deleteItem(); }

    // Getters
    int id() const;
    string label() const;
    double weight() const;
    int minCapacity() const;
    int maxCapacity() const;

    // Setters
    void setId(const int i);
    void setLabel(const string& s);
    void setWeight(const double w);
    void setMinCapacity(const int minCap);
    void setMaxCapacitiy(const int maxCap);

    friend ostream& operator<<(ostream& os, const Vertex& v);
};


#endif //GRAPH_VERTEX_H
