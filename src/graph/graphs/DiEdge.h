//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "Edge.h"

class DiEdge : public Edge {

public:
    // Constructors

    DiEdge(const Vertex &from, const Vertex &to)
            : Edge(from, to) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const double &weight)
            : Edge(from, to, weight) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const string &label)
            : Edge(from, to, label) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const double &weight, const string &label)
            : Edge(from, to, weight, label) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const int maxCapacity)
            : Edge(from, to, maxCapacity) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const int minCapacity, const int maxCapacity)
            : Edge(from, to, minCapacity, maxCapacity) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const double &weight, const int maxCapacity)
            : Edge(from, to, weight, maxCapacity) { }

    DiEdge(const Vertex &from, const Vertex &to,
           const double &weight, const string &label, const int minCapacity,
           const int maxCapacity)
            : Edge(from, to, weight, label, maxCapacity, minCapacity) { }

    virtual ~DiEdge() {
        deleteItem();
    }

    const Vertex *from();

    const Vertex *to();
};


#endif //SRC_DiEdge_H
