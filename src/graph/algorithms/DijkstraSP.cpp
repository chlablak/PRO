//
// Created by sebri on 18.05.2016.
//

#include <set>
#include "DijkstraSP.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

void DijkstraSP::relax(IEdge *ie) {

    Vertex *w = ie->to();

    if(!_marques[w->id()]){
        Vertex *v = ie->from();
        double distThruE = _distanceTo[v->id()] + ie->weight();

        if(_distanceTo[w->id()] > distThruE){
            _pq.erase(std::make_pair(_distanceTo[w->id()], w));
            _distanceTo[w->id()] = distThruE;
            if (_edgeTo[w->id()] != nullptr) {
                _G->removeEdge(_edgeTo[w->id()]);
            }
            _edgeTo[w->id()] = ie;

            _G->assignVertex(v);
            _G->assignVertex(w);
            _G->assignEdge(ie);

            _pq.insert(std::make_pair(_distanceTo[w->id()], w));
        }
    }
}

void DijkstraSP::visit(Graph *g, Vertex *from) {
    UNUSED(g);
    UNUSED(from);
    throw std::runtime_error("Error with DijkstraSP algorithm. A non directed"
                                     "graph can't be apply to this algorithm."
                                     "The graph should be directed");
}

void DijkstraSP::visit(DiGraph *g, Vertex *from) {
    if (!g->isWeighted() || g->isNegativeWeighted()) {
        throw std::runtime_error("Error in Dijkstra algorithm. The graph must"
                                         "be positively weighted");
    }

    _G = g->emptyClone();

    // Init _distances and _edges
    _distanceTo.assign(g->V(),std::numeric_limits<double>::max());
    _edgeTo.resize(g->V());
    _marques.assign(g->V(), false);

    _distanceTo[from->id()] = 0;
    _edgeTo[from->id()] = new DiEdge(from, from, 0);

    // Initialization. Insert all vertices of the graph in the priority queue
    g->forEachVertex([this](Vertex *v){
        _pq.insert( std::make_pair(_distanceTo[v->id()], v) );
    });

    // Get the min vertex, then treat his adjacent edges to progressively find
    // the shortest path
    while(!_pq.empty()){
        Vertex *u = _pq.begin()->second;
        _pq.erase(_pq.begin());
        _marques[u->id()] = true;

        g->forEachAdjacentEdge(u, [this](IEdge *ie){
            relax(ie);
        });
    }
}

void DijkstraSP::visit(FlowGraph *g, Vertex *from) {
    if (!g->isWeighted() || g->isNegativeWeighted()) {
        throw std::runtime_error("Error in Dijkstra algorithm. The graph must"
                                         "be positively weighted");
    }

    _G = g->emptyClone();

    // Init _distances and _edges
    _distanceTo.assign(g->V(),std::numeric_limits<double>::max());
    _edgeTo.resize(g->V());
    _marques.assign(g->V(), false);

    _distanceTo[from->id()] = 0;
    _edgeTo[from->id()] = new FlowEdge(from, from, 0);

    // Initialization. Insert all vertices of the graph in the priority queue
    g->forEachVertex([this](Vertex *v){
        _pq.insert( std::make_pair(_distanceTo[v->id()], v) );
    });

    // Get the min vertex, then treat his adjacent edges to progressively find
    // the shortest path
    while(!_pq.empty()){
        Vertex *u = _pq.begin()->second;
        _pq.erase(_pq.begin());
        _marques[u->id()] = true;

        g->forEachAdjacentEdge(u, [this](IEdge *ie){
            relax(ie);
        });
    }
}

IGraph *DijkstraSP::G() const {
    return _G;
}

std::vector<int> &DijkstraSP::table() {
    throw std::runtime_error("no table in DijkstraSP");
}

