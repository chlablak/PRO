/*! \brief Algorithm to find maximum flow in a flow graph
 *
 * \file PushRelabel.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_PUSHRELABEL_H
#define GRAPH_PUSHRELABEL_H


#include <queue>
#include "Visitor.h"
#include "../graphs/FlowEdge.h"
#include "../graphs/IGraph.h"
#include "../graphs/FlowGraph.h"

typedef long long LL;
// TODO
struct AdapteeFlowEdge {
    int from, to, cap, flow, index;
    AdapteeFlowEdge(int from, int to, int cap, int flow, int index)
            : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

class PushRelabel : public Visitor {
private:
    int _N;
    vector<vector<AdapteeFlowEdge>> _adj;
    vector<LL> _excess;
    vector<int>  _dist, _active, _count;
    queue<int> _Q;

    IGraph *_G;

    void addEdge(int from, int to, int cap);
    void enqueue(int v);
    void push(AdapteeFlowEdge afe);
    void gap(int k);
    void relabel(int v);
    void discharge(int v);
    int getMaxFlow(int s, int t);

public:
    PushRelabel(int N) : _N(N), _adj(N), _excess(N), _dist(N), _active(N), _count(2*N), _G(nullptr) { }
    ~PushRelabel() { }
    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;
    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;
    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;
    virtual IGraph *G() const override;
    virtual std::vector<double> table() override;
};


#endif //GRAPH_PUSHRELABEL_H
