/*! \brief Class Graph (manipulate Edge)
 *
 * \file Graph.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include <algorithm>
#include <unordered_set>
#include "Graph.h"
#include "../algorithms/ConnectedComponent.h"
#include "../algorithms/CopyToDiGraph.h"

Graph::Graph(const Graph &g) : GraphCommon(g)
{
    for (Vertex *v : g.vertexList())
        _vertices.at(v->id()) = new Vertex(*v);

    for (IEdge *ie : g.edgeList()) {
        Edge *e = (Edge*)ie;
        Edge *copy = new Edge(*e);
        copy->setA(_vertices.at(e->from()->id()));
        copy->setB(_vertices.at(e->to()->id()));
        assignEdge(copy);
    }
}

bool Graph::isSimple() const
{
    if(this->isNull() || this->isEmpty())
        return true;

    IGraph::Vertices vertexList = this->vertexList();
    for (IGraph::Vertices::iterator it = vertexList.begin(); it != vertexList.end(); ++it)
        for (IGraph::Vertices::iterator it2 = it; it2 != vertexList.end(); ++it2)
            if (this->getEdges(*it, *it2).size() > 1)
                return false;

    return true;
}

void Graph::removeEdge(IEdge *e)
{
    Edge *edge = (Edge*)e;
    _adjacentList.at(edge->either()->id()).remove(e);
    _adjacentList.at(edge->other(edge->either())->id()).remove(e);

    resetEdgeId();
}


bool Graph::isStronglyConnected() const
{
    return isConnected();
}

bool Graph::isDirected() const
{
    return false;
}

bool Graph::isConnected() const
{
    Visitor *v = new ConnectedComponent;
    v->visit((Graph*)this, nullptr, nullptr);

    vector<double> cc = v->table();
    size_t ccSize = cc.size();
    if (ccSize > 1)
        for (size_t i = 1; i < ccSize; ++i)
            if (cc[i] != cc[0])
                return false;

    return true;
}

void Graph::removeVertex(Vertex *v)
{
    Vertex *otherVertex;

    for (IEdge* e : _adjacentList.at(v->id())) {
        if (((Edge*)e)->either() == v)
            otherVertex = ((Edge*)e)->other(v);
        else
            otherVertex = ((Edge*)e)->either();

        _adjacentList.at(otherVertex->id()).remove(e);

        _adjacentList.at(v->id()).remove(e);
    }

    _adjacentList.erase(_adjacentList.begin() + v->id());

    for (vector<Vertex*>::iterator it = _vertices.begin() + v->id() + 1; it != _vertices.end(); it++)
        (*it)->setId( (*it)->id() - 1 );

    _vertices.erase(_vertices.begin() + v->id());
    resetEdgeId();

    delete v;
}

list<IEdge*> Graph::getEdges(Vertex *either, Vertex *other) const
{
    std::list<IEdge*> edges;
    for (IEdge *ie : _adjacentList.at(either->id())) {
        Edge *e = (Edge*)ie;
        if (e->other(either) == other)
            edges.push_back(e);
    }
    return edges;
}

Graph* Graph::clone() const
{
    return new Graph(*this);
}

void Graph::assignEdge(IEdge *ie)
{
    Edge *e = (Edge*)ie;
    _adjacentList.at(e->either()->id()).push_back(e);
    if (e->either() != e->other(e->either()))
        _adjacentList.at(e->other(e->either())->id()).push_back(e);
}

void Graph::accept(Visitor *v, Vertex *from, Vertex *to)
{
    v->visit(this, from, to);
}

Graph *Graph::emptyClone() const
{
    Graph *g = new Graph;
    g->_vertices.resize(this->V());
    g->_adjacentList.resize(this->V());
    g->_edgeId = this->E();
    return g;
}

void Graph::addEdge(IEdge *e) {
    e->setId(_edgeId++);
    assignEdge((Edge*)e);
}

IEdge *Graph::createEdge(Vertex *v, Vertex *w) const
{
    return new Edge(v, w);
}

Graph::Graph(vector<Vertex *> &vertices, vector<IEdge *> &edges) : GraphCommon(vertices) {
    for (IEdge* ie: edges)
        addEdge(ie);
}



























