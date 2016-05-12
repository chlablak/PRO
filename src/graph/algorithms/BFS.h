//
// Created by sebri on 01.05.2016.
//

#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H

#include "../visitor/Visitor.h"
#include "../graphs/IGraph.h"
#include <vector>

class BFS : public Visitor {
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<int> _distances;

public:
    BFS() : _distances(0) {}
    ~BFS();

    virtual Graph* visit(Graph *g, Vertex *from) override;
    virtual DiGraph* visit(DiGraph *g, Vertex *from) override;
    virtual FlowGraph* visit(FlowGraph *g, Vertex *from) override;
};


#endif //GRAPH_BFS_H
