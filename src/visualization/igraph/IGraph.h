#ifndef VISUALIZATION_IGRAPH_IGRAPH_H
#define VISUALIZATION_IGRAPH_IGRAPH_H

#include <QList>

#include "ivertex.h"
#include "iedge.h"

class IGraph
{
    QList<IVertex *> vertices;
    QList<IEdge *> edges;
    int test;

public:
    IGraph();
    ~IGraph();
    const QList<IVertex *> &getVertices() const;
    const QList<IEdge *> &getEdges() const;
    void setTest(int t);
};

#endif // VISUALIZATION_IGRAPH_IGRAPH_H
