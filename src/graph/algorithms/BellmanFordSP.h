//
// Created by sebri on 22.05.2016.
//

#ifndef GRAPH_BELLMANFORD_H
#define GRAPH_BELLMANFORD_H


#include "Visitor.h"
#include "../graphs/IEdge.h"

// TODO : si le temps le permet, implémenté avec une queue pour gagner en complexité moyenne (mais ne change rien dans le pire des cas)
class BellmanFordSP : public Visitor {
private:
    IGraph *_G;
    std::vector<IEdge*> _edgeTo;
    std::vector<double> _distanceTo;

    void relax(IEdge *ie);
public:
    BellmanFordSP() : _G(nullptr), _edgeTo(0), _distanceTo(0) { }
    virtual ~BellmanFordSP() override;
    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_BELLMANFORD_H
