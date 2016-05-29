//
// Created by PatrickDesle on 23.05.2016.
//

#ifndef GRAPH_TOPOLOGICALSORT_H
#define GRAPH_TOPOLOGICALSORT_H


#include "Visitor.h"
#include "../graphs/Vertex.h"
#include "../graphs/IGraph.h"

class TopologicalSort : public Visitor
{
private:
    vector<list<Vertex*>> _predessessorsList;
    vector<double > _order;
    IGraph *_G;

    bool isDAG(IGraph *g) const;
    void fillPredessessors(IGraph *g);
    void order(IGraph *g);
public:


    TopologicalSort(): _predessessorsList(0), _order(0), _G(nullptr) { }

    virtual ~TopologicalSort() override {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override ;

    virtual std::vector<double> table() override ;
};


#endif //GRAPH_TOPOLOGICALSORT_H
