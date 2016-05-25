//
// Created by sebri on 16.05.2016.
//

#ifndef GRAPH_PRIM_H
#define GRAPH_PRIM_H


#include <queue>
#include "Visitor.h"
#include "../graphs/IEdge.h"

class Prim : public Visitor
{
private:
    typedef priority_queue<IEdge*, vector<IEdge*>, std::greater<IEdge*>> MinPQ;

    IGraph *_G;
public:
    Prim() : _G(nullptr) { }
    virtual ~Prim() { }

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_PRIM_H
