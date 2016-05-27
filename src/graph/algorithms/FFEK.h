//
// Created by sebri on 27.05.2016.
//

#ifndef GRAPH_FFEK_H
#define GRAPH_FFEK_H


#include "Visitor.h"
#include "../graphs/FlowEdge.h"
#include "../graphs/IGraph.h"

class FFEK : public Visitor {
private:
    vector<int> _x;
    vector<int> _u;
    vector<Vertex*> _p;
    vector<int> _cap;
    list<Vertex*> _L;
    bool _end;
public:
    FFEK(int V, int E) : _x(E), _u(E), _p(V, nullptr), _cap(V), _end(false) {}
    virtual ~FFEK() {}
    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;
    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;
    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_FFEK_H
