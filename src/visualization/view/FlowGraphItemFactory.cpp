#include "../../graph/graphs/IEdge.h"

#include "FlowGraphItemFactory.h"
#include "EdgeItem.h"
#include "FlowEdgeItem.h"

EdgeItem *FlowGraphItemFactory::createEdge(const IEdge *edge,
                                           VertexItem *source, VertexItem *dest)
{
    return new FlowEdgeItem(edge, source, dest);
}
