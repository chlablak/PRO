//
// Created by sebri on 18.05.2016.
//

#ifndef GRAPH_DIJKSTRA_H
#define GRAPH_DIJKSTRA_H


#include "Visitor.h"
#include "../graphs/IGraph.h"

class Dijkstra : public Visitor {
private:
    IGraph *_G;

public:
    Dijkstra() : _G(nullptr) { }
    virtual ~Dijkstra() { }

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_DIJKSTRA_H
