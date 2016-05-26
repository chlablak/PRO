//
// Created by PatrickDesle on 23.05.2016.
//

#ifndef GRAPH_DETECTEDCYCLE_H
#define GRAPH_DETECTEDCYCLE_H


#include "Visitor.h"
#include "../graphs/IGraph.h"
#include <vector>
#include <stdexcept>


using namespace std;
class DetectedCycle : public Visitor{

private:

    vector<bool> _marked;
    vector<bool> _stacked;
    vector<Vertex*> _cycle;
    bool cycleFounded;
    IGraph *_G;
    vector<int> _distances;

private:
    void hasCycleDirected(Vertex *v, IGraph* g);
    void hasCycle(Vertex *v, int fromId, IGraph *g);
    void commonFlowDiGraph (IGraph *g);


public:


    DetectedCycle() : _marked(0), _stacked(0), _cycle(0), cycleFounded(false), _G(nullptr), _distances(0) {}


    virtual ~DetectedCycle()override {}

    virtual void visit(Graph *g, Vertex *from) override ;

    virtual void visit(DiGraph *g, Vertex *from) override ;

    virtual void visit(FlowGraph *g, Vertex *from) override;

    virtual IGraph *G() const override ;

    virtual std::vector<double> table() override ;

};


#endif //GRAPH_DETECTEDCYCLE_H
