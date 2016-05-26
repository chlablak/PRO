//
// Created by sebri on 24.04.2016.
//

#include <algorithm>
#include <unordered_set>
#include "Graph.h"
#include "../algorithms/ConnectedComponent.h"
#include "../algorithms/CopyToDiGraph.h"

Graph::Graph(const Graph &g) : GraphCommon(g) {
    for (Vertex *v : g.vertexList()) {
        if (v) {
            _vertices.at(v->id()) = new Vertex(*v);
        }
    }
    for (IEdge *ie : g.edgeList()) {
        Edge *e = (Edge*)ie;
        Edge *copy = new Edge(*e);
        copy->setA(_vertices.at(e->from()->id()));
        copy->setB(_vertices.at(e->to()->id()));
        assignEdge(copy);
    }
}

/**
 * First delete edges, then automatically call the base class destructor
 */
Graph::~Graph() {
    for (IEdge *e : edgeList()) {
        delete e;
    }
}

/**
 * check wether the graph is simple or not
 * A graph is simple if it doesn't have multiple edges, or edge loop
 */
bool Graph::isSimple() const {
    if(this->isNull() || this->isEmpty()) {
        return true;
    }

    IGraph::Vertices vertexList = this->vertexList();
    for (IGraph::Vertices::iterator it = vertexList.begin(); it != vertexList.end(); ++it) {
        for (IGraph::Vertices::iterator it2 = it; it2 != vertexList.end(); ++it2) {
            if (this->getEdges(*it, *it2).size() > 1) {
                return false;
            }
        }
    }
    return true;
}

/**
 * add an Edge to the graph
 * NB : the user should not add an edge without add his vertex first
 */
void Graph::addEdge(IEdge *e) {
    e->setId(_edgeId++);
    assignEdge((Edge*)e);
}


/**
 * remove the Edge from the graph
 */
void Graph::removeEdge(IEdge *e) {
    Edge *edge = (Edge*)e;
    _adjacentList.at(edge->either()->id()).remove(e);
    _adjacentList.at(edge->other(edge->either())->id()).remove(e);

    // Reset edge ids
    resetEdgeId();
}


bool Graph::isStronglyConnected() const {
    return isConnected();
}

bool Graph::isDirected() const {
    return false;
}

bool Graph::isConnected() const {
    Visitor *v = new ConnectedComponent;
    v->visit((Graph*)this, nullptr);

    vector<double> cc = v->table();
    size_t ccSize = cc.size();
    if (ccSize > 1) {
        for (size_t i = 1; i < ccSize; ++i) {
            if (cc[i] != cc[0]) {
                return false;
            }
        }
    }

    return true;
}

void Graph::removeVertex(Vertex *v) {
    Vertex *otherVertex;
    // First remove the concerned edges from the adjacent List
    for (IEdge* e : _adjacentList.at(v->id())) {
        if (((Edge*)e)->either() == v) {
            otherVertex = ((Edge*)e)->other(v);
        } else {
            otherVertex = ((Edge*)e)->either();
        }

        // Remove edge in that other vertex
        _adjacentList.at(otherVertex->id()).remove(e);

        // Remove edge in this vertex
        _adjacentList.at(v->id()).remove(e);
    }

    _adjacentList.erase(_adjacentList.begin() + v->id());

    for (vector<Vertex*>::iterator it = _vertices.begin() + v->id() + 1; it != _vertices.end(); it++) {
        (*it)->setId( (*it)->id() - 1 );
    }
    _vertices.erase(_vertices.begin() + v->id());

    resetEdgeId();

    delete v;
}

Graph::Graph(vector<Vertex *> &vertices, vector<IEdge *> &edges)
        : GraphCommon(vertices) {
    for (IEdge* e : edges) {
        addEdge(e);
    }
}

size_t Graph::E() const {
    return edgeList().size();
}

GraphCommon<Edge>::Edges Graph::edgeList() const {
    std::unordered_set<IEdge*> s;

    size_t adjListSize = _adjacentList.size();
    for (size_t i = 0; i < adjListSize; ++i) {
        for (IEdge *ie : _adjacentList.at(i)) {
            s.insert(ie);
        }
    }

    IGraph::Edges l;
    for (IEdge *ie : s) {
        l.push_back(ie);
    }

    return l;

//    Edges list;
//    bool alreadyInside;
//    for(size_t i = 0; i<_adjacentList.size(); ++i){
//        for(IEdge* e1 : _adjacentList.at(i)){
//            alreadyInside = false;
//            for(IEdge* e2 : list){
//                if(e1 == e2) {
//                    alreadyInside = true;
//                    break;
//                }
//            }
//            if(!alreadyInside) {
//                list.push_back(e1);
//            }
//        }
//    }
//    return list;
}

list<IEdge*> Graph::getEdges(Vertex *either, Vertex *other) const {
    std::list<IEdge*> edges;
    for (IEdge *ie : _adjacentList.at(either->id())) {
        Edge *e = (Edge*)ie;
        if (e->other(either) == other) {
            edges.push_back(e);
        }
    }
    return edges;
}

Graph* Graph::clone() const {
    return new Graph(*this);
}

void Graph::assignEdge(IEdge *ie) {
    Edge *e = (Edge*)ie;
    _adjacentList.at(e->either()->id()).push_back(e);
    if (e->either() != e->other(e->either())) {
        _adjacentList.at(e->other(e->either())->id()).push_back(e);
    }
}

void Graph::accept(Visitor *v, Vertex *from) {
    v->visit(this, from);
}

Graph *Graph::emptyClone() const {
    Graph *g = new Graph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

IEdge *Graph::createEdge(Vertex *v, Vertex *w) const {
    return new Edge(v, w);
}

























