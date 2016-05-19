#include "../../graph/graphs/IEdge.h"

#include "DiGraphItemFactory.h"
#include "EdgeItem.h"
#include "DiEdgeItem.h"

EdgeItem *DiGraphItemFactory::createEdge(const IEdge *edge,
                                         VertexItem *source, VertexItem *dest)
{
    return new DiEdgeItem(edge, source, dest);
}
