//
// Created by sebri on 01.05.2016.
//

#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H


#include "../visitor/Visitor.h"

class BFS : public Visitor {
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<int> distances;
public:
    BFS() : distances(0) {}
    ~BFS();
    Graph* visitGraph(Graph& g, const Vertex& from);
    DiGraph* visitDiGraph(DiGraph& g, const Vertex& from);
    FlowGraph* visitFlowGraph(FlowGraph& g, const Vertex& from);

};


#endif //GRAPH_BFS_H
