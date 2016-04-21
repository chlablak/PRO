#ifndef VISUALIZATION_IGRAPH_H
#define VISUALIZATION_IGRAPH_H

#include <QList>

#include "ivertex.h"
#include "iedge.h"

class IGraph
{
    QList<IVertex *> vertex;
    QList<IEdge *> edges;

public:
    IGraph();
    ~IGraph();
    QList<IVertex *> &getVertex();
    QList<IEdge *> &getEdges();
};

#endif // VISUALIZATION_IGRAPH_H
