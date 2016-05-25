//
// Created by PatrickDesle on 23.05.2016.
//

#ifndef GRAPH_TOPOLOGICALSORT_H
#define GRAPH_TOPOLOGICALSORT_H


#include "Visitor.h"

class TopologicalSort : public Visitor
{
public:


    virtual ~TopologicalSort() override ;

    virtual void visit(Graph *g, Vertex *from) override ;

    virtual void visit(DiGraph *g, Vertex *from) override ;

    virtual void visit(FlowGraph *g, Vertex *from) override;

    virtual IGraph *G() const override ;

    virtual std::vector<double> table() override ;
};


#endif //GRAPH_TOPOLOGICALSORT_H
