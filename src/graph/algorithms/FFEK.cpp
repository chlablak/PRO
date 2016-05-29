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
// TODO
//struct Key
//{
//    Vertex *i;
//    Vertex *j;
//
//    Key(Vertex *i, Vertex *j) : i(i), j(j) {}
//
//    bool operator<(const Key &k) {
//        return true;
//    }
//};
//
//namespace std
//{
//    template <>
//    struct less<Key>
//    {
//        bool operator()(const Key& a, const Key& b) const
//        {
//            return a.i->id() < b.i->id();
//        }
//    };
//}

//namespace std
//{
//    template <>
//    struct less<std::map<Key,FlowEdge*>>
//    {
//        bool operator()(const std::map<Key,FlowEdge*>& a, const std::map<Key,FlowEdge*>& b) const
//        {
//            return true;
//        }
//    };
//}

int FFEK::bfs(int startNode, int endNode)
{
//    queue<int> q;
//    q.push(startNode);
//
//    _parentsList[startNode] = -1;
//    _currentPathCapacity[startNode] = 999;
//
//    while (!q.empty()) {
//        int currentNode = q.front();
//        q.pop();
//
//        for (int i = 0; i < _graph[currentNode].size(); i++) {
//            int to = _graph[currentNode][i];
//            if(_parentsList[to] == -1)
//            {
//                if(_capacities[currentNode][to] - _flowPassed[currentNode][to] > 0)
//                {
//                    _parentsList[to] = currentNode;
//                    _currentPathCapacity[to] = min(_currentPathCapacity[currentNode],
//                                                  _capacities[currentNode][to] - _flowPassed[currentNode][to]);
//                    if(to == endNode)
//                    {
//                        return _currentPathCapacity[endNode];
//                    }
//                    q.push(to);
//                }
//            }
//        }
//    }
    return 0;
}

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
//    if (!g->hasPositiveCapacity())
//        throw runtime_error("Error in 'FFEK' algorithm. The flow graph must "
//                                    "have a positive capacity");
//
//    g->forEachEdge([this, &from, &to](IEdge *ie){
//        FlowEdge *fe = (FlowEdge*)ie;
//        _capacities[fe->from()->id()][fe->to()->id()] = fe->maxCapacity();
//        _graph[from->id()].push_back(to->id());
//        _graph[to->id()].push_back(from->id());
//    });
//
//    for (vector<int> v : _capacities) {
//        for (int i : v) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//
//    int maxFlow = 0;
//    while (true) {
//        int flow = bfs(from->id(), to->id());
//
//        cout << "flow " << flow << endl;
//        if (flow == 0)
//            break;
//
//        maxFlow += flow;
//        int currentNode = to->id();
//        while(currentNode != from->id())
//        {
//            int previousNode = _parentsList[currentNode];
//            _flowPassed[previousNode][currentNode] += flow;
//            _flowPassed[currentNode][previousNode] -= flow;
//            currentNode = previousNode;
//        }
//    }
//
//    cout << "_flowPassed" << endl;
//    for (vector<int> v : _flowPassed) {
//        for (int i : v) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "maxFlow = " <<  maxFlow << endl;


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
        if (*v == *from)
            source = v;
        else if (*v == *to)
            sink = v;
    }

    for (int i = 0; i < _V; ++i) {
        _x.at(i).assign(_V, 0);
        _u.at(i).assign(_V, 0);
    }

    gClone->forEachEdge([this](IEdge *ie){
        FlowEdge *fe = (FlowEdge*)ie;
        _u[fe->from()->id()][fe->to()->id()] = fe->maxCapacity();
    });

    cout << "_u" << endl;
    for (vector<int> v : _u) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    do {

        cout << "_x" << endl;
        for (vector<int> v : _x) {
            for (int i : v)
                cout << i << " ";
            cout << endl;
        }

        gClone->forEachVertex([this, &source](Vertex *i) {
            _p[i->id()] = -1;
            _mark[i->id()] = true;
            _cap[i->id()] = 0;
        });

//        if (!_L.empty())
//            source = _L.front();

        _p[source->id()] = source->id();
        _mark[source->id()] = true;
        _cap[source->id()] = numeric_limits<int>::max();
        _L.push(source);

        bool out = false;
        while (!_L.empty()) {
            Vertex *i = _L.front();
            _L.pop();

            list<IEdge*> succ = gClone->adjacentList().at(i->id());
            for (IEdge *ie : succ) {
                Vertex *j = ie->to();
                if (_p[j->id()] == -1 && _x[i->id()][j->id()] < _u[i->id()][j->id()]) {

                    _p[j->id()] = i->id();
                    _mark[j->id()] = true;
                    _cap[j->id()] = min(_cap[i->id()], _u[i->id()][j->id()] - _x[i->id()][j->id()]);

                    if (j == sink) {
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

                        if (j == sink) {
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

        if (_p[sink->id()] == -1) {
            _end = true; // There is no path from source to sink
        } else {
            int j = sink->id();

            cout << "_cap" << endl;
            for (int c : _cap)
                cout << c << " ";
            cout << endl;

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

