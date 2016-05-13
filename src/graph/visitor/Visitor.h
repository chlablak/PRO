//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VISITOR_H
#define GRAPH_VISITOR_H


class Vertex;
class Graph;
class DiGraph;
class FlowGraph;

class Visitor {
public:
    Visitor() {}
    virtual ~Visitor() {}
    virtual Graph* visit(Graph *g, Vertex *from) = 0;
    virtual DiGraph* visit(DiGraph *g, Vertex *from) = 0;
    virtual FlowGraph* visit(FlowGraph *g, Vertex *from) = 0;
};


#endif //GRAPH_VISITOR_H
