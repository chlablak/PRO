//
// Created by sebri on 18.05.2016.
//

#ifndef GRAPH_DIJKSTRA_H
#define GRAPH_DIJKSTRA_H


#include "Visitor.h"
#include "../graphs/IGraph.h"
#include <set>

class DijkstraSP : public Visitor {
private:
    IGraph *_G;
    std::vector<IEdge*> _edgeTo;
    std::vector<double> _distanceTo;
    std::vector<bool> _marques;

    typedef std::pair<double, Vertex*> WeightVertex;
    // Priority queue containing the weight of edges and the vertices
    std::set<WeightVertex> _pq;

    void relax(IEdge *ie);
public:
    DijkstraSP() : _G(nullptr), _edgeTo(0), _distanceTo(0), _marques(0), _pq() { }
    virtual ~DijkstraSP() { }

    virtual void visit(Graph *g, Vertex *from) override;
    virtual void visit(DiGraph *g, Vertex *from) override;
    virtual void visit(FlowGraph *g, Vertex *from) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_DIJKSTRA_H
