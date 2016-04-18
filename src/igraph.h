#ifndef GRAPHY_IGRAPH_H
#define GRAPHY_IGRAPH_H

#include <QLinkedList>

#include "ivertex.h"
#include "iedge.h"

class IGraph
{
    QLinkedList<IVertex*> vertex;
    QLinkedList<IEdge*> edges;

public:
    IGraph()
    {
        vertex.push_back(new IVertex("v1"));
        vertex.push_back(new IVertex("v2"));
        vertex.push_back(new IVertex("v3"));
        vertex.push_back(new IVertex("v4"));
        vertex.push_back(new IVertex("v5"));
        vertex.push_back(new IVertex("v6"));
        vertex.push_back(new IVertex("v7"));
        vertex.push_back(new IVertex("v8"));
        vertex.push_back(new IVertex("v9"));
        vertex.push_back(new IVertex("v10"));
    }

    virtual QLinkedList<IVertex*>& getVertex()
    {
        return vertex;
    }

    virtual QLinkedList<IEdge*>& getEdges()
    {
        return edges;
    }

    virtual ~IGraph()
    {
        for (IVertex *v : vertex) {
            delete v;
        }
        for (IEdge *e : edges) {
            delete e;
        }
    }
};

#endif // GRAPHY_IGRAPH_H
