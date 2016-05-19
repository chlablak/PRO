#ifndef VISUALIZATION_DIGRAPHITEMFACTORY_H
#define VISUALIZATION_DIGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "DiGraphItemFactory.h"
#include "AbstractGraphItemFactory.h"
#include "EdgeItem.h"

class DiGraphItemFactory : public AbstractGraphItemFactory
{
public:
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest);
};

#endif // VISUALIZATION_DIGRAPHITEMFACTORY_H
