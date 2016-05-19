//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_COMMONEDGE_H
#define GRAPH_COMMONEDGE_H

#include <string>
#include "Vertex.h"

class IEdge
{
protected:
    int _id;
    Vertex *_a;
    Vertex *_b;
    string _label;
    double _weight;

public:
    IEdge(Vertex *from, Vertex *to)
            : _id(-1), _a(from), _b(to), _label(""), _weight(numeric_limits<double>::max()) {}
    IEdge(Vertex *from, Vertex *to, const double weight)
            : _id(-1), _a(from), _b(to), _label(""), _weight(weight) {}
    IEdge(Vertex *from, Vertex *to, const string& label)
            : _id(-1), _a(from), _b(to), _label(label), _weight(numeric_limits<double>::max()) {}
    IEdge(Vertex *from, Vertex *to, const string& label, const double weight)
            : _id(-1), _a(from), _b(to), _label(label), _weight(weight) {}

    IEdge(IEdge *e);

    virtual ~IEdge() {}

    virtual Vertex* either() const = 0;
    virtual Vertex* other(Vertex *v) const = 0;
    virtual Vertex *from() const = 0;
    virtual Vertex *to() const = 0;
    // Getters
    int id() const;

    Vertex* vertexA() const;

    Vertex* vertexB() const;

    string label() const;

    double weight() const;

    // Setters
    void setId(int _id);

    void setA(Vertex *v);

    void setB(Vertex *v);

    void setLabel(const string &label);

    void setWeight(double weight);

    inline bool operator< (const IEdge& e) const { return _weight < e.weight(); }
    inline bool operator> (const IEdge& e) const { return e < *this; }
    inline bool operator<=(const IEdge& e) const { return !(*this > e); }
    inline bool operator>=(const IEdge& e) const { return !(*this < e); }

    friend ostream& operator<<(ostream& os, const IEdge& e);
};


#endif //GRAPH_COMMONEDGE_H
