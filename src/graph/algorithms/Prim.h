//
// Created by sebri on 16.05.2016.
//

#ifndef GRAPH_PRIM_H
#define GRAPH_PRIM_H


#include "../visitors/Visitor.h"

class Prim : public Visitor
{
private:
    IGraph *_G;
public:


    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_PRIM_H
