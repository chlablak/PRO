//
// Created by sebri on 19.05.2016.
//

#ifndef GRAPH_COPYTOFLOWGRAPH_H
#define GRAPH_COPYTOFLOWGRAPH_H


#include "Visitor.h"

class CopyToFlowGraph : public Visitor {
private:
    IGraph *_G;
public:
    CopyToFlowGraph() : _G(nullptr) { }
    ~CopyToFlowGraph() { }
    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_COPYTOFLOWGRAPH_H
