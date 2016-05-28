//
// Created by sebri on 27.05.2016.
//

#include <stdexcept>
#include <map>
#include "FFEK.h"
#include "../graphs/FlowGraph.h"

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

void FFEK::visit(Graph *, Vertex *, Vertex *) {
    throw runtime_error("Error. A graph can't be applied to 'FFEK' algorithm."
                                " Use a flow graph instead.");
}

void FFEK::visit(DiGraph *, Vertex *, Vertex *) {
    throw runtime_error("Error. A directed graph can't be applied to 'FFEK'"
                                " algorithm. Use a flow graph instead.");
}

void FFEK::visit(FlowGraph *g, Vertex *from, Vertex *to) {
    if (!g->hasPositiveCapacity()) {
        throw runtime_error("Error in 'FFEK' algorithm. The flow graph must "
                                    "have a positive capacity");
    }

    Vertex *fromCpy;
    Vertex *toCpy;
    FlowGraph *gClone = g->clone();
    for (Vertex *v : gClone->vertexList()) {
        if (*v == *from) {
            fromCpy = v;
        }
        if (*v == *to) {
            toCpy = v;
        }
    }

    for(int i = 0; i < _V; ++i) {
        _x.at(i).assign(_V,0);
        _u.at(i).assign(_V,0);
    }

//    map<Key, FlowEdge*> edgeMap;
    gClone->forEachEdge([this](IEdge *ie){
        FlowEdge *fe = (FlowEdge*)ie;
//        Key k = Key(fe->from(), fe->to());
//        edgeMap.insert({k, fe});
        _u[fe->from()->id()][fe->to()->id()] = fe->maxCapacity();
    });

//    // Iterate and print keys and values of unordered_map
//    for( const auto& n : edgeMap ) {
//        std::cout << "Key:[" << endl;
//        cout << "\t" << *n.first.i << endl;
//        cout << "\t" << *n.first.j << "]" << endl;
//        cout << "Value:[" << endl;
//        cout << "\t" << *n.second << "]\n";
//
//        cout << endl;
//    }

    do {

        gClone->forEachVertex([this, &fromCpy](Vertex *v){
            _p[v->id()].first = nullptr;
            _p[v->id()].second = false;
            _cap[v->id()] = 0;
        });

        _p[fromCpy->id()].first = fromCpy;
        _p[fromCpy->id()].second = true;
        _cap[fromCpy->id()] = numeric_limits<int>::max();
        _L.push_back(fromCpy);

        bool out = false;
        while(!_L.empty()) {
            Vertex *i = _L.front(); _L.pop_front();

            gClone->forEachSuccessor(i, [this, &i, &toCpy, &out](Vertex *j){
                if (_p[j->id()].first == nullptr && _x[i->id()][j->id()] < _u[i->id()][j->id()]) {
                    _p[j->id()].first = i;
                    _p[j->id()].second = true;
                    _cap[j->id()] = min(_cap[i->id()], _u[i->id()][j->id()] - _x[i->id()][j->id()]);
                    if (*j == *toCpy) {
                        out = true;
                    } else {
                        _L.push_back(j);
                    }
                }
            });

            if (out) {break;}
            gClone->forEachPredecessor(i, [this, &i, &toCpy, &out](Vertex *j){
                if (_p[j->id()].first == nullptr && _x[j->id()][i->id()] > 0) {
                    _p[j->id()].first = i;
                    _p[j->id()].second = false;
                    _cap[j->id()] = min(_cap[i->id()], _x[j->id()][i->id()]);
                    if (*j == *toCpy) {
                        out = true;
                    } else {
                        _L.push_back(j);
                    }
                }
            });

            if (out) {break;}
        }

        if (_p[toCpy->id()].first == nullptr) {
            _end = true; // There is no path from source to sink
        } else {
            Vertex *j = toCpy;

//            for (auto p : _p) {
//                cout << " [" << p.first << ", " << p.second << "] ";
//            }cout << endl;

            while (*j != *fromCpy && j != nullptr) {
                auto p = _p[j->id()];
                Vertex *i = p.first;
                if (p.second) {
                    _x[i->id()][j->id()] += _cap[toCpy->id()];
                } else {
                    _x[j->id()][i->id()] -= _cap[toCpy->id()];
                }

                for (vector<int> v : _x) {
                    for (int i : v) {
                        cout << i << " ";
                    }
                    cout << endl;
                }

                j = i;
            }
        }

        cout << "end : " << _end << endl;

    } while (!_end);

    cout << "caca" << endl;
    for (vector<int> v : _x) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

IGraph *FFEK::G() const {
    return nullptr;
}

std::vector<double> FFEK::table() {
    throw runtime_error("Error. No table in 'FFEK' algorithm");
}

