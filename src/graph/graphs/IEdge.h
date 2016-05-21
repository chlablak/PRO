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
    virtual string edgeStyle() const = 0;
public:
    virtual ~IEdge() {}

    virtual string toString() const = 0;

    // Getterss
    virtual int id() const = 0;
    virtual Vertex* vertexA() const = 0;
    virtual Vertex* vertexB() const = 0;
    virtual string label() const = 0;
    virtual double weight() const = 0;

    // Setters
    virtual void setId(int _id) = 0;
    virtual void setA(Vertex *v) = 0;
    virtual void setB(Vertex *v) = 0;
    virtual void setLabel(const string &label) = 0;
    virtual void setWeight(double weight) = 0;

    inline bool operator< (const IEdge& e) const { return weight() < e.weight(); }
    inline bool operator> (const IEdge& e) const { return e < *this; }
    inline bool operator<=(const IEdge& e) const { return !(*this > e); }
    inline bool operator>=(const IEdge& e) const { return !(*this < e); }

    friend ostream& operator<<(ostream& os, const IEdge& e) {
        return os << e.toString();
    }
};


#endif //GRAPH_COMMONEDGE_H
