/*! \brief Strongly Connected Component algorithm
 *
 * \file SCCTarjan.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stdexcept>
#include "SCCTarjan.h"

void SCCTarjan::visit(Graph *, Vertex *, Vertex *)
{
    throw std::runtime_error("Error. The algorithm of 'Strongly Connected Component'"
                             " can't be applied to a non-directed graph."
                             " Use the 'Connected Component' algorithm"
                             " instead.");
}

void SCCTarjan::visit(DiGraph *g, Vertex *, Vertex *)
{
    _scc.assign(g->V(), 0);
    _dfsnum.assign(g->V(), 0);
    _low.assign(g->V(), 0);

    g->forEachVertex([this, &g](Vertex* v){
        if (_scc[v->id()] == 0)
            SCC(v, g);
    });
}

void SCCTarjan::visit(FlowGraph *g, Vertex *from, Vertex *)
{
    visit((DiGraph*)g, from, nullptr);
}

IGraph *SCCTarjan::G() const
{
    return nullptr;
}

std::vector<double> SCCTarjan::table()
{
    return _scc;
}

void SCCTarjan::SCC(Vertex *u, DiGraph *g)
{
    ++_N;
    _dfsnum[u->id()] = _N;
    _low[u->id()] = _N;
    _P.push(u);


    g->forEachAdjacentVertex(u, [this, &g, &u](Vertex *v){
        if (_dfsnum[v->id()] == 0)
            SCC(v, g); // v has not been visited yet
        if (_scc[v->id()] == 0)
            _low[u->id()] = min(_low[u->id()], _low[v->id()]);
    });

    if (_low[u->id()] == _dfsnum[u->id()]) {
        // Let's unstack until u
        ++_K;
        Vertex *w = nullptr;
        do {
             w = _P.top(); _P.pop();
            _scc[w->id()] = _K;
        } while (w != u);
    }
}
