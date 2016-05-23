/*!
 * \brief Directed graph factory class
 *
 * \file DiGraphItemFactory.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_DIGRAPHITEMFACTORY_H
#define VISUALIZATION_DIGRAPHITEMFACTORY_H

#include "../../graph/graphs/IEdge.h"

#include "DiGraphItemFactory.h"
#include "AbstractGraphItemFactory.h"
#include "EdgeItem.h"

class DiGraphItemFactory : public AbstractGraphItemFactory
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
    virtual ~DiGraphItemFactory();
};

#endif // VISUALIZATION_DIGRAPHITEMFACTORY_H
