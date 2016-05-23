/*!
 * \brief Factory base class for IGraph items
 *
 * \file AbstractGraphItemFactory.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H
#define VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"

class AbstractGraphItemFactory
{
public:

    /*!
     * \brief Pure virtual method to implements
     *         for the creation of edges
     *
     * \param edge - Pointer to an IEdge
     * \param source - Pointer to the Vertex graphics item of source
     * \param dest - Pointer to the Vertex graphics item of destination
     * \return the created edge graphics item
     */
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest) = 0;
};

#endif // VISUALIZATION_ABSTRACTGRAPHITEMFACTORY_H
