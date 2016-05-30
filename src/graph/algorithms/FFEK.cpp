/*! \brief Ford Fulkerson Edmond Karps' algorithm
 *
 * \file FFEK.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <stdexcept>
#include <map>
#include <queue>
#include "FFEK.h"
#include "../graphs/FlowGraph.h"

void FFEK::visit(Graph *, Vertex *, Vertex *)
{
    throw runtime_error("Error. A graph can't be applied to 'FFEK' algorithm."
                                " Use a flow graph instead.");
}

void FFEK::visit(DiGraph *, Vertex *, Vertex *)
{
    throw runtime_error("Error. A directed graph can't be applied to 'FFEK'"
                                " algorithm. Use a flow graph instead.");
}

void FFEK::visit(FlowGraph *g, Vertex *from, Vertex *to)
{
    if (!g->hasPositiveCapacity())
        throw runtime_error("Error in 'FFEK' algorithm. The flow graph must "
                                    "have a positive capacity");

    Vertex *source;
    Vertex *sink;
    FlowGraph *gClone = g->clone();

    for(auto v : gClone->vertexList())
    {
        // for each successor u of vertex v, we add v to the list of predessessor of u
        for(auto iedge : g->adjacentEdges(v)){
            _predecessorsList.at(iedge->to()->id()).push_back(v);
        }
    }

    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            source = v;
        }
        else if (*v == *to) {
            sink = v;
        }
    }

    for (int i = 0; i < _V; ++i) {
        _x.at(i).assign(_V, 0);
        _u.at(i).assign(_V, 0);
    }

    gClone->forEachEdge([this](IEdge *ie){
        FlowEdge *fe = (FlowEdge*)ie;
        _u[fe->from()->id()][fe->to()->id()] = fe->maxCapacity();
    });

    do {

        cout << "_u" << endl;
        for (vector<int> v : _u) {
            for (int i : v) {
                cout << i << " ";
            }
            cout << endl;
        }

        _p.assign(_V, -1);
        _mark.assign(_V, true);
        _cap.assign(_V, 0);

        _p[source->id()] = source->id();
        _cap[source->id()] = numeric_limits<int>::max();
        _L.push(source);

       // bool out = false;
        while (!_L.empty()) {
            bool out = false;
            Vertex *i = _L.front();
            _L.pop();

            list<IEdge*> succ = gClone->adjacentList().at(i->id());
            for (IEdge *ie : succ) {
                Vertex *j = ie->to();
                if (_p[j->id()] == -1 && _x[i->id()][j->id()] < _u[i->id()][j->id()]) {

                    _p[j->id()] = i->id();
                    _mark[j->id()] = true;
                    _cap[j->id()] = min(_cap[i->id()], _u[i->id()][j->id()] - _x[i->id()][j->id()]);

                    if (*j == *sink) {
                        out = true;
                        break;
                    } else {
                        _L.push(j);
                    }
                }
            }

            if (out)
                break;

            for (IEdge *e : gClone->edgeList()) {
                if (*e->to() == *i) {
                    Vertex *j = e->from();
                    if (_p[j->id()] == -1 && _x[j->id()][i->id()] > 0) {

                        _p[j->id()] = i->id();
                        _mark[j->id()] = false;
                        _cap[j->id()] = min(_cap[i->id()],
                                            _x[j->id()][i->id()]);

                        if (*j == *sink) {
                            out = true;
                            break;
                        } else {
                            _L.push(j);
                        }
                    }
                }
            }

            if (out)
                break;
        }

        cout << "_p" << endl;
        for (int i : _p)
            cout << i << " ";
        cout << endl;

        cout << "_cap" << endl;
        for (int c : _cap)
            cout << c << " ";
        cout << endl;

        if (_p[sink->id()] == -1) {
            _end = true; // There is no path from source to sink
        } else {
            int j = sink->id();

            while (j != source->id()) {
                int p = _p[j];
                int i = p;
                if (_mark[p])
                    _x[i][j] += _cap[sink->id()];
                else
                    _x[j][i] -= _cap[sink->id()];

                j = i;
            }
        }

        cout << "_x" << endl;
        for (vector<int> v : _x) {
            for (int i : v)
                cout << i << " ";
            cout << endl;
        }

        for(size_t i = 0; i<_u.size(); ++i){
            for(size_t j = 0; j<_u.at(i).size() ; ++j){
                if(_u[i][j] -_x[i][j] != _u[i][j]){
                    Vertex *s = nullptr, *t = nullptr;
                    s = gClone->getVertex(i);
                    t = gClone->getVertex(j);

                    if(_u[i][j] -_x[i][j]>0){

                        ((FlowEdge*)gClone->getEdges(s,t).front())->setMaxCapacity(_u[i][j] -_x[i][j]);
                        FlowEdge *newEd = new FlowEdge(t, s, _x[i][j]);

                        _u[i][j] = _u[i][j] -_x[i][j];
                        _u[j][i] = _x[i][j];
                        gClone->addEdge(newEd);
                    }
                    else if(_u[i][j] -_x[i][j] == 0){
                        gClone->getEdges(s,t).front()->setA(t);
                        gClone->getEdges(s,t).front()->setB(s);
                        _u[j][i] = _x[i][j];
                        _u[i][j] = 0;
                    }
                }
            }
        }

    } while (!_end);

    cout << "_x final" << endl;
    for (vector<int> v : _x) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
}

IGraph *FFEK::G() const
{
    return nullptr;
}

std::vector<double> FFEK::table()
{
    throw runtime_error("Error. No table in 'FFEK' algorithm");
}

