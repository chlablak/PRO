//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include <list>
#include <limits>
#include <iostream>
#include "../../utility/Global.h"

using namespace std;

class Vertex {
private:
    int _id;
    string _label;
    double _weight;
    int _minCapacity;
    int _maxCapacity;

public:
    Vertex()
            : _id(-1), _label(""), _weight(numeric_limits<double>::max()), _minCapacity(-1),
              _maxCapacity(-1) { }

    Vertex(const string& label)
            : _id(-1), _label(label), _weight(numeric_limits<double>::max()), _minCapacity(-1),
              _maxCapacity(-1) { }

    Vertex(const double& weight)
            : _id(-1), _label(""), _weight(weight),
              _minCapacity(-1), _maxCapacity(-1) { }

    Vertex(const double& weight, const string& label)
            : _id(-1), _label(label), _weight(weight),
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

    Vertex(const Vertex &v);

    ~Vertex() { }

    string toString() const;

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
    void setMaxCapacity(const int maxCap);

    // Operators
    friend ostream& operator<<(ostream& os, const Vertex& v);

    // L'utilisateur de cette classe devra respcter la contrainte qui est
    // deux vertexs ne devra jamais avoir le même label
    bool operator == (const Vertex v) const{
        return _label == v._label;
    }
    bool operator == (const Vertex *v) const{
        return _label == v->_label;
    }
    bool operator != (const Vertex* v) const{
        return _label != v->_label;
    }
};


#endif //GRAPH_VERTEX_H
