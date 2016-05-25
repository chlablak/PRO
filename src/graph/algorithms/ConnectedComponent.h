//
// Created by sebri on 08.05.2016.
//

#ifndef GRAPH_CONNECTEDCOMPONENT_H
#define GRAPH_CONNECTEDCOMPONENT_H

#include "Visitor.h"
#include "../graphs/IGraph.h"

class ConnectedComponent : public Visitor {
private:
    // Table containing the number of the connected component associated
    // for each vertex of the graph
    std::vector<double> _cc;
public:
    ConnectedComponent() : _cc(0) {}
    ~ConnectedComponent();

    virtual void visit(Graph *g, Vertex *from);
    virtual void visit(DiGraph *g, Vertex *from);
    virtual void visit(FlowGraph *g, Vertex *from);
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_CONNECTEDCOMPONENT_H
