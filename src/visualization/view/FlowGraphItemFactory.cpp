/*!
 * \brief Flow graphs factory class
 *
 * \file FlowGraphItemFactory.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include "../../graph/graphs/IEdge.h"

#include "FlowGraphItemFactory.h"
#include "EdgeItem.h"
#include "FlowEdgeItem.h"

EdgeItem *FlowGraphItemFactory::createEdge(const IEdge *edge,
                                           VertexItem *source, VertexItem *dest)
{
    return new FlowEdgeItem(edge, source, dest);
}
