//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_COMMONEDGE_H
#define GRAPH_COMMONEDGE_H

#include <string>
#include "Vertex.h"
#include "IGraph.h"

class IEdge {

private:

protected:
    int _id;
    Vertex *_a;
    Vertex *_b;
    string _label;
    double _weight;

public:
    IEdge(): _id(-1), _a(nullptr), _b(nullptr), _label(""), _weight(numeric_limits<double>::max()) {}
    IEdge(Vertex *from, Vertex *to)
            : _a(from), _b(to), _id(-1), _label(""), _weight(numeric_limits<double>::max()) {}
    IEdge(Vertex *from, Vertex *to, const double weight)
            : _a(from), _b(to), _id(-1), _label(""), _weight(weight) {}
    IEdge(Vertex *from, Vertex *to, const string label)
            : _a(from), _b(to), _id(-1), _label(label), _weight(numeric_limits<double>::max()) {}
    IEdge(Vertex *from, Vertex *to, const string label, const double weight)
            : _a(from), _b(to), _id(-1), _label(label), _weight(weight) {}

    virtual ~IEdge() {}

    // Getters
    int id() const;

    string label() const;

    double weight() const;

    // Setters
    void setId(int _id);

    void setLabel(const string &label);

    void setWeight(double weight);

    inline bool operator< (const IEdge& e) const { return _weight < e.weight(); }
    inline bool operator> (const IEdge& e) const { return e < *this; }
    inline bool operator<=(const IEdge& e) const { return !(*this > e); }
    inline bool operator>=(const IEdge& e) const { return !(*this < e); }
};


#endif //GRAPH_COMMONEDGE_H
