#include "igraph.h"

IGraph::IGraph()
{
    vertex.append(new IVertex("v0"));
    vertex.append(new IVertex("v1"));
    vertex.append(new IVertex("v2"));
    vertex.append(new IVertex("v3"));
    vertex.append(new IVertex("v4"));
    vertex.append(new IVertex("v5"));
    vertex.append(new IVertex("v6"));
    vertex.append(new IVertex("v7"));
    vertex.append(new IVertex("v8"));
    vertex.append(new IVertex("v9"));
    vertex.append(new IVertex("v10"));
    vertex.append(new IVertex("v11"));
    vertex.append(new IVertex("v12"));
    vertex.append(new IVertex("v13"));
    vertex.append(new IVertex("v14"));
    vertex.append(new IVertex("v15"));

    edges.append(new IEdge(vertex.at(5), vertex.at(0)));
    edges.append(new IEdge(vertex.at(5), vertex.at(1)));
    edges.append(new IEdge(vertex.at(5), vertex.at(2)));
    edges.append(new IEdge(vertex.at(5), vertex.at(3)));
    edges.append(new IEdge(vertex.at(5), vertex.at(4)));
    edges.append(new IEdge(vertex.at(5), vertex.at(6)));
    edges.append(new IEdge(vertex.at(5), vertex.at(8)));
    edges.append(new IEdge(vertex.at(5), vertex.at(9)));
    edges.append(new IEdge(vertex.at(5), vertex.at(10)));
    edges.append(new IEdge(vertex.at(5), vertex.at(11)));
}

IGraph::~IGraph()
{
    for (IVertex *v : vertex) {
        delete v;
    }
    for (IEdge *e : edges) {
        delete e;
    }
}

QList<IVertex *> &IGraph::getVertex()
{
    return vertex;
}

QList<IEdge *> &IGraph::getEdges()
{
    return edges;
}
