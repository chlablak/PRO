//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "DiEdgeCommon.h"

class DiEdge : public DiEdgeCommon {

public:
    // Constructors
    DiEdge(Vertex *from, Vertex *to)
        : DiEdgeCommon(from, to) {}

    DiEdge(Vertex *from, Vertex *to, const string &label)
        : DiEdgeCommon(from, to, label) {}

    DiEdge(Vertex *from, Vertex *to, const double weight)
        : DiEdgeCommon(from, to,  weight) {}

    DiEdge(Vertex *from, Vertex *to, const string label, const double weight)
        : DiEdgeCommon(from, to, label, weight) {}

    DiEdge(const DiEdge& e) : DiEdgeCommon(e) { }

    string toString() const;

    virtual ~DiEdge() {}
};


#endif //SRC_DiEdge_H
