//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VISITOR_H
#define GRAPH_VISITOR_H

#include <vector>
#include "../graphs/Vertex.h"

class IGraph;
class Vertex;
class Graph;
class DiGraph;
class FlowGraph;

class Visitor {
public:
    Visitor() {}
    virtual ~Visitor() {}
    virtual void visit(Graph *g, Vertex *from, Vertex *to) = 0;
    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) = 0;
    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) = 0;

    virtual IGraph* G() const = 0;

    virtual std::vector<double> table() = 0;
};


#endif //GRAPH_VISITOR_H
