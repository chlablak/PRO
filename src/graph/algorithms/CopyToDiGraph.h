//
// Created by sebri on 19.05.2016.
//

#ifndef GRAPH_COPYTODIGRAPH_H
#define GRAPH_COPYTODIGRAPH_H


#include "Visitor.h"
#include "../graphs/DiGraph.h"

class CopyToDiGraph : public Visitor {
private:
    IGraph *_G;
public:
    CopyToDiGraph() : _G(nullptr) {}
    ~CopyToDiGraph() {}

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_COPYTODIGRAPH_H
