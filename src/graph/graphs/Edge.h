//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>
#include <iostream>
#include "Vertex.h"
#include "IEdge.h"

using namespace std;

class Edge : public IEdge
{

public:
    // Constructors
    Edge(Vertex *from, Vertex *to)
            : IEdge(from, to) { }

    Edge(Vertex *from, Vertex *to, const string &label)
            : IEdge(from, to, label) { }

    Edge(const Edge& e);

    virtual ~Edge() {}

    Vertex* either() const;

    Vertex* other(Vertex *v) const;

    friend ostream& operator<<(ostream& os, const Edge& e);
};


#endif //GRAPH_EDGE_H
