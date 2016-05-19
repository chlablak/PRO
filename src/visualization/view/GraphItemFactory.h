#ifndef VISUALIZATION_GRAPHITEMFACTORY_H
#define VISUALIZATION_GRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "GraphItemFactory.h"
#include "AbstractGraphItemFactory.h"
#include "EdgeItem.h"

class GraphItemFactory : public AbstractGraphItemFactory
{
public:
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest);
};

#endif // VISUALIZATION_GRAPHITEMFACTORY_H
