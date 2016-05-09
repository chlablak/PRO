#ifndef VISUALIZATION_IGRAPH_H
#define VISUALIZATION_IGRAPH_H

#include <QList>

#include "ivertex.h"
#include "iedge.h"

class IGraph
{
    QList<IVertex *> vertices;
    QList<IEdge *> edges;

public:
    IGraph();
    ~IGraph();
    const QList<IVertex *> &getVertices() const;
    const QList<IEdge *> &getEdges() const;
};

#endif // VISUALIZATION_IGRAPH_H
