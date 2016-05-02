//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>
#include <iostream>
#include "Vertex.h"

using namespace std;

class Edge {

protected:
    int _id;
    const Vertex *_a;
    const Vertex *_b;
    string _label;
    double _weight;
    int _minCapacity;
    int _maxCapacity;

    void deleteItem();

public:
    // Constructors
    Edge();
    Edge(const Vertex &from, const Vertex &to)
            : _id(-1), _a(&from), _b(&to), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(-1), _maxCapacity(-1) { }

    Edge(const Vertex &from, const Vertex &to,
         const double &weight)
            : _id(-1), _a(&from), _b(&to), _label(""),
              _weight(weight),
              _minCapacity(-1), _maxCapacity(-1) { }

    Edge(const Vertex &from, const Vertex &to,
         const string &label)
            : _id(-1), _a(&from), _b(&to), _label(label),
              _weight(numeric_limits<double>::max()), _minCapacity(-1), _maxCapacity(-1) { }

    Edge(const Vertex &from, const Vertex &to,
         const double &weight,
         const string &label)
            : _id(-1), _a(&from), _b(&to), _label(label),
              _weight(weight), _minCapacity(-1),
              _maxCapacity(-1) { }

    Edge(const Vertex &from, const Vertex &to,
         const int &maxCapacity)
            : _id(-1), _a(&from), _b(&to), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(0),
              _maxCapacity(maxCapacity) { }

    Edge(const Vertex &from, const Vertex &to,
         const int minCapacity, const int &maxCapacity)
            : _id(-1), _a(&from), _b(&to), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(minCapacity),
              _maxCapacity(maxCapacity) { }

    Edge(const Vertex &from, const Vertex &to,
         const double &weight, const int maxCapacity)
            : _id(-1), _a(&from), _b(&to), _label(""),
              _weight(weight), _minCapacity(0),
              _maxCapacity(maxCapacity) { }

    Edge(const Vertex &from, const Vertex &to,
         const double &weight,
         const string &label, const int minCapacity,
         const int maxCapacity)
            : _id(-1), _a(&from), _b(&to), _label(label),
              _weight(weight),
              _minCapacity(minCapacity),
              _maxCapacity(maxCapacity) { }

    virtual ~Edge() {
        deleteItem();
    }

    // Getters
    unsigned int id() const;

    string label() const;

    double weight() const;

    int minCapacity() const;

    int maxCapacity() const;

    const Vertex *either() const;

    const Vertex *other(const Vertex &v) const;

    // Setters
    void setId(const int i);
    void setLabel(const string &s);

    void setWeight(const double w);

    void setminCapacity(const int minCap);

    void setMaxCapacitiy(const int maxCap);


    // opérateurs
    // TODO

    friend ostream& operator<<(ostream& os, const Edge& e);
};


#endif //GRAPH_EDGE_H
