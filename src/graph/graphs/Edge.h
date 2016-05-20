//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>
#include <iostream>
#include "Vertex.h"
#include "IEdge.h"
#include "EdgeCommon.h"

using namespace std;

class Edge : public EdgeCommon
{

public:
    // Constructors
    Edge(Vertex *from, Vertex *to)
            : EdgeCommon(from, to) { }
    Edge(Vertex *from, Vertex *to, const string &label)
            : EdgeCommon(from, to, label) { }
    Edge(Vertex *from, Vertex *to, const double weight)
            : EdgeCommon(from, to, weight) { }
    Edge(Vertex *from, Vertex *to, const string &label, const double weight)
            : EdgeCommon(from, to, label, weight) { }

    Edge(const Edge &e) : EdgeCommon(e) { }

    virtual ~Edge() {}

    Vertex* either() const;
    Vertex* other(Vertex *v) const;
    string toString() const;


    friend ostream& operator<<(ostream& os, const Edge& e);
};


#endif //GRAPH_EDGE_H
