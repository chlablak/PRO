//
// Created by PatrickDesle on 16.05.2016.
//

#ifndef GRAPH_DIEDGECOMMON_H
#define GRAPH_DIEDGECOMMON_H

#include "EdgeCommon.h"

class DiEdgeCommon : public EdgeCommon
{
protected:
    virtual string edgeStyle() const override;

public:
    // Constructors
    DiEdgeCommon(Vertex *from, Vertex *to)
            : EdgeCommon(from, to) { }
    DiEdgeCommon(Vertex *from, Vertex *to, const string &label)
            : EdgeCommon(from, to, label) { }
    DiEdgeCommon(Vertex *from, Vertex *to, const double weight)
            : EdgeCommon(from, to,  weight) {}
    DiEdgeCommon(Vertex *from, Vertex *to, const string label, const double weight)
            : EdgeCommon(from, to, label, weight){}

    DiEdgeCommon(const DiEdgeCommon &e) : EdgeCommon(e) {}

    virtual ~DiEdgeCommon() { }

    // Getters
    Vertex *from() const;
    Vertex *to() const;
};


#endif //GRAPH_DIEDGECOMMON_H
