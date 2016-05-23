/*!
 * \brief Graph factory class
 *
 * \file GraphItemFactory.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include "../../graph/graphs/IEdge.h"

#include "GraphItemFactory.h"
#include "EdgeItem.h"

EdgeItem *GraphItemFactory::createEdge(const IEdge *edge,
                                       VertexItem *source, VertexItem *dest)
{
    return new EdgeItem(edge, source, dest);
}

GraphItemFactory::~GraphItemFactory()
{}
