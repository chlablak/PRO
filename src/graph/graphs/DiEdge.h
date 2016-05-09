//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "Edge.h"

class DiEdge : public Edge {

public:
    // Constructors

    DiEdge(Vertex &from, Vertex &to)
            : Edge(from, to) { }

    DiEdge(Vertex &from, Vertex &to,
           const double &weight)
            : Edge(from, to, weight) { }

    DiEdge(Vertex &from, Vertex &to,
           const string &label)
            : Edge(from, to, label) { }

    DiEdge(Vertex &from, Vertex &to,
           const double &weight, const string &label)
            : Edge(from, to, weight, label) { }

    DiEdge(Vertex &from, Vertex &to,
           const int maxCapacity)
            : Edge(from, to, maxCapacity) { }

    DiEdge(Vertex &from, Vertex &to,
           const int minCapacity, const int maxCapacity)
            : Edge(from, to, minCapacity, maxCapacity) { }

    DiEdge(Vertex &from, Vertex &to,
           const double &weight, const int maxCapacity)
            : Edge(from, to, weight, maxCapacity) { }

    DiEdge(Vertex &from, Vertex &to,
           const double &weight, const string &label, const int minCapacity,
           const int maxCapacity)
            : Edge(from, to, weight, label, maxCapacity, minCapacity) { }

    virtual ~DiEdge() {
        deleteItem();
    }

    Vertex *from();

    Vertex *to();
};


#endif //SRC_DiEdge_H
