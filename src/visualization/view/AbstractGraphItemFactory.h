#ifndef VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H
#define VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"

class AbstractGraphItemFactory
{
public:
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest) = 0;
};

#endif // VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H
