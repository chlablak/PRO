//
// Created by sebri on 19.05.2016.
//

#ifndef GRAPH_COPYTOGRAPH_H
#define GRAPH_COPYTOGRAPH_H


#include "Visitor.h"

class CopyToGraph : public Visitor {
private:
    IGraph *_G;
public:
    CopyToGraph() : _G(nullptr) { }
    ~CopyToGraph() { }
    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_COPYTOGRAPH_H
