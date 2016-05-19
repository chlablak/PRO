#include "IGraph.h"

IGraph::IGraph()
{
    vertices.append(new IVertex("v0"));
    vertices.append(new IVertex("v1"));
    vertices.append(new IVertex("v2"));
    vertices.append(new IVertex("v3"));
    vertices.append(new IVertex("v4"));
    vertices.append(new IVertex("v5"));
    vertices.append(new IVertex("v6"));
    vertices.append(new IVertex("v7"));
    vertices.append(new IVertex("v8"));
    vertices.append(new IVertex("v9"));
    vertices.append(new IVertex("v10"));
    vertices.append(new IVertex("v11"));
    vertices.append(new IVertex("v12"));
    vertices.append(new IVertex("v13"));
    vertices.append(new IVertex("v14"));
    vertices.append(new IVertex("v15"));

    edges.append(new IEdge(vertices.at(5), vertices.at(0)));
    edges.append(new IEdge(vertices.at(5), vertices.at(1)));
    edges.append(new IEdge(vertices.at(5), vertices.at(2)));
    edges.append(new IEdge(vertices.at(5), vertices.at(3)));
    edges.append(new IEdge(vertices.at(5), vertices.at(4)));
    edges.append(new IEdge(vertices.at(5), vertices.at(6)));
    edges.append(new IEdge(vertices.at(5), vertices.at(8)));
    edges.append(new IEdge(vertices.at(5), vertices.at(9)));
    edges.append(new IEdge(vertices.at(5), vertices.at(10)));
    edges.append(new IEdge(vertices.at(5), vertices.at(11)));
}

IGraph::~IGraph()
{
    for (IVertex *v : vertices) {
        delete v;
    }
    for (IEdge *e : edges) {
        delete e;
    }
}

const QList<IVertex *> &IGraph::getVertices() const
{
    return vertices;
}

const QList<IEdge *> &IGraph::getEdges() const
{
    return edges;
}

void IGraph::setTest(int t)
{
    this->test = t;
}


