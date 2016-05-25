//
// Created by sebri on 01.05.2016.
//

#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H

#include "../graphs/IGraph.h"
#include "Visitor.h"
#include <vector>

class BFS : public Visitor {
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<double> _distances;
    IGraph *_G;
public:
    BFS() : _distances(0), _G(nullptr) {}
    ~BFS();

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;

    virtual IGraph* G() const override ;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_BFS_H
