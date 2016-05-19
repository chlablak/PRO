#ifndef VISUALIZATION_FLOWGRAPHITEMFACTORY_H
#define VISUALIZATION_FLOWGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "FlowGraphItemFactory.h"
#include "AbstractGraphItemFactory.h"
#include "EdgeItem.h"

class FlowGraphItemFactory : public AbstractGraphItemFactory
{
public:
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest);
};

#endif // VISUALIZATION_FLOWGRAPHITEMFACTORY_H
