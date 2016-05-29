//
// Created by sebri on 26.05.2016.
//

#include <stdexcept>
#include "PushRelabel.h"
#include "../graphs/FlowGraph.h"

void PushRelabel::addEdge(int from, int to, int cap) {
    _adj[from].push_back(AdapteeFlowEdge(from, to, cap, 0, _adj[to].size()));
    if (from == to) {
        _adj[from].back().index++;
    }
    _adj[to].push_back(AdapteeFlowEdge(to, from, 0, 0, _adj[from].size() -1));
}

void PushRelabel::enqueue(int v) {
    cout << "in enqueue" << endl;
    if (!_active[v] && _excess[v] > 0) {
        _active[v] = true;
        _Q.push(v);
    }
}

void PushRelabel::push(AdapteeFlowEdge afe) {
    cout << "in push" << endl;
    int amt = int(min(_excess[afe.from], LL(afe.cap - afe.flow)));

    if (_dist[afe.from] <= _dist[afe.to] || amt == 0) {
        return;
    }

    afe.flow += amt;
    _adj[afe.to][afe.index].flow -= amt;
    _excess[afe.to] += amt;
    _excess[afe.from] -= amt;
    enqueue(afe.to);
}

void PushRelabel::gap(int k) {
    cout << "in gap" << endl;
    for (int v = 0; v < _N; v++) {
        if (_dist[v] < k) {
            continue;
        }
        _count[_dist[v]]--;
        _dist[v] = max(_dist[v], _N+1);
        _count[_dist[v]]++;
        enqueue(v);
    }
}

void PushRelabel::relabel(int v) {
    cout << "in relabel" << endl;
    _count[_dist[v]]--;
    _dist[v] = 2 * _N;
    for (size_t i = 0; i < _adj[v].size(); ++i) {
        if (_adj[v][i].cap - _adj[v][i].flow > 0) {
            _dist[v] = min(_dist[v], _dist[_adj[v][i].to] + 1);
        }
    }
    _count[_dist[v]]++;
    enqueue(v);
}

void PushRelabel::discharge(int v) {

    cout << "in discharge" << endl;
    for (size_t i = 0; _excess[v] > 0 && i < _adj[v].size(); ++i) {
        push(_adj[v][i]);
    }

    if (_excess[v] > 0) {
        if (_count[_dist[v]] == 1) {
            gap(_dist[v]);
        } else {
            relabel(v);
        }
    }
}

int PushRelabel::getMaxFlow(int s, int t) {
    cout << "in getMaxFlow" << endl;
    _count[0] = _N - 1;
    _count[_N] = 1;
    _dist[s] = _N;
    _active[s] = _active[t] = true;

    for (size_t i = 0; i < _adj[s].size(); ++i) {
        _excess[s] += _adj[s][i].cap;
        push(_adj[s][i]);
    }

    while(!_Q.empty()) {
        int v = _Q.front(); _Q.pop();
        _active[v] = false;
        discharge(v);
    }

    int totalFlow = 0;
    for (size_t i = 0; i < _adj[s].size(); ++i) {
        totalFlow += _adj[s][i].flow;
    }

    return totalFlow;
}

void PushRelabel::visit(Graph *, Vertex *, Vertex *) {

}

void PushRelabel::visit(DiGraph *, Vertex *, Vertex *) {

}

void PushRelabel::visit(FlowGraph *g, Vertex *from, Vertex *to) {
    for (IEdge *ie : g->edgeList()) {
        FlowEdge *fe = (FlowEdge*)ie;
        if (fe->maxCapacity() < 0) {
            throw runtime_error("Error in 'Push-Relabel' algorithm."
                                        "The capacity of edges must be null or "
                                        "positive.");
        }
    }
//
//    FlowGraph *gClone = g->clone();

    g->forEachEdge([this](IEdge *ie){
        FlowEdge *fe = (FlowEdge*)ie;
        this->addEdge(fe->from()->id(), fe->to()->id(), fe->maxCapacity());
    });

    for (vector<AdapteeFlowEdge> vv : _adj) {
        for (AdapteeFlowEdge& a : vv) {
            cout << a.index << "---";
        }
        cout << "/" << endl;
    }

    int maxFlow = getMaxFlow(from->id(), to->id());

    cout << "max flow = " << maxFlow << endl;

//    _G = gClone->emptyClone();
}

IGraph *PushRelabel::G() const {
    return nullptr;
}

std::vector<double> PushRelabel::table() {
    return std::vector<double>();
}
