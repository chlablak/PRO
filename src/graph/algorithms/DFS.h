//
// Created by sebri on 06.05.2016.
//

#ifndef GRAPH_DFS_H
#define GRAPH_DFS_H


#include "../visitor/Visitor.h"

class DFS : public Visitor {
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<int> dfsnum;
    int N;
public:
    ~DFS();
    void DFSprocedure(Graph* g, const Vertex& u);
    Graph* visitGraph(Graph& g, const Vertex& from);
    DiGraph* visitDiGraph(DiGraph& g, const Vertex& from);
    FlowGraph* visitFlowGraph(FlowGraph& g, const Vertex& from);
};


#endif //GRAPH_DFS_H
