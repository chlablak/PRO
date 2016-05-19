#include "../../graph/graphs/IEdge.h"

#include "GraphItemFactory.h"
#include "EdgeItem.h"

EdgeItem *GraphItemFactory::createEdge(const IEdge *edge,
                                       VertexItem *source, VertexItem *dest)
{
    return new EdgeItem(edge, source, dest);
}
