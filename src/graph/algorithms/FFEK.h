/*! \brief Ford Fulkerson Edmond Karps' algorithm
 *
 * \file FFEK.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_FFEK_H
#define GRAPH_FFEK_H

#include "Visitor.h"
#include "../graphs/FlowEdge.h"
#include "../graphs/IGraph.h"

/*! \brief FFEK algorithm to find the maximum flow in a graph
 */
class FFEK : public Visitor
{
private:
    int _V;
    int _E;
    vector<vector<int>> _x;
    vector<vector<int>> _u;
    vector<int> _p;
    vector<bool> _mark;
    vector<int> _cap;
    queue<Vertex*> _L;
    bool _end;

    vector<list<Vertex*>> _predecessorsList;

//    vector<vector<int>> _capacities;
//    vector<vector<int>> _flowPassed;
//    vector<vector<int>> _graph;
//    vector<int> _parentsList;
//    vector<int> _currentPathCapacity;

    int bfs(int startNode, int endNode);
public:
    /*! \brief Constructor. Initialize private attributes
     */
    FFEK(int V, int E) : _V(V), _E(E), _x(V), _u(V), _p(V), _mark(V), _cap(V), _end(false), _predecessorsList(V) {}

//    FFEK(int V, int E) : _V(V), _E(E), _capacities(V, vector<int>(V, 0)), _flowPassed(V, vector<int>(V, 0)), _graph(V), _parentsList(V, -1), _currentPathCapacity(V, 0) {}

    /*! \brief Destructor
     */
    virtual ~FFEK() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_FFEK_H
