//
// Created by sebri on 22.05.2016.
//

#ifndef GRAPH_STRONGLYCONNECTEDCOMPONENT_H
#define GRAPH_STRONGLYCONNECTEDCOMPONENT_H


#include "Visitor.h"
#include "../graphs/Vertex.h"
#include "../graphs/DiGraph.h"
#include <stack>

class SCCTarjan : public Visitor
{
private:
    std::vector<double> _scc;
    std::vector<int> _dfsnum;
    std::vector<int> _low;
    int _N; // counter for dfsnum numerotation
    int _K; // counter for components numerotation
    stack<Vertex*> _P; // stack containing the visited vertices

    void SCC(Vertex *u, DiGraph *g);

public:
    SCCTarjan() : _scc(0), _dfsnum(0), _low(0), _N(0), _K(0), _P() { }
    ~SCCTarjan();
    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;
    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;
    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;

};


#endif //GRAPH_STRONGLYCONNECTEDCOMPONENT_H
