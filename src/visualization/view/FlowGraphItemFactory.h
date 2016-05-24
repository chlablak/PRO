/*!
 * \brief Flow graphs factory class
 *
 * \file FlowGraphItemFactory.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_FLOWGRAPHITEMFACTORY_H
#define VISUALIZATION_FLOWGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "FlowGraphItemFactory.h"
#include "AbstractGraphItemFactory.h"
#include "EdgeItem.h"

class FlowGraphItemFactory : public AbstractGraphItemFactory
{
public:

    /*!
     * \brief Implements AbstractGraphItemFactory::createEdge()
     */
    virtual EdgeItem *createEdge(const IEdge *edge,
                                 VertexItem *source, VertexItem *dest);

    /*!
     * \brief Destructor
     */
    virtual ~FlowGraphItemFactory();
};

#endif // VISUALIZATION_FLOWGRAPHITEMFACTORY_H
