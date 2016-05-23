/*!
 * \brief Directed edge graphics item class
 *
 * \file DiEdgeItem.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_DIEDGEITEM_H
#define VISUALIZATION_DIEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "items/ArrowItem.h"

class DiEdgeItem : public EdgeItem
{
private:

    /*!
     * \brief The graphics items
     */
    ArrowItem *_arrow;

public:

    /*!
     * \brief Constructor
     *
     * \param edge - The represented IEdge
     * \param source - The source vertex graphics item
     * \param dest - The destination vertex graphics item
     */
    DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    /*!
     * \brief Destructor
     */
    virtual ~DiEdgeItem();

    /*!
     * \brief Overrides EdgeItem::adjust()
     */
    virtual void adjust();
};

#endif // VISUALIZATION_DIEDGEITEM_H
