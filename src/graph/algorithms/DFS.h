//
// Created by sebri on 06.05.2016.
//

#ifndef GRAPH_DFS_H
#define GRAPH_DFS_H


#include "../visitors/Visitor.h"
#include "../graphs/IGraph.h"

class DFS : public Visitor {
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<int> _dfsnum;
    int N;
    IGraph *_G;
    void DFSprocedure(Graph *g, Vertex *u);
public:
    DFS() : _dfsnum(0), _G(nullptr) {}
    ~DFS();

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<int> *table() override;
};


#endif //GRAPH_DFS_H
