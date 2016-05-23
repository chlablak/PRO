/*!
 * \brief Flow edge graphics item class
 *
 * \file FlowEdgeItem.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_FLOWEDGEITEM_H
#define VISUALIZATION_FLOWEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "items/ArrowItem.h"

class FlowEdgeItem : public EdgeItem
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
    FlowEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    /*!
     * \brief Destructor
     */
    virtual ~FlowEdgeItem();

    /*!
     * \brief Overrides EdgeItem::adjust()
     */
    virtual void adjust();

protected:

    /*!
     * \brief Overrides EdgeItem::label()
     */
    virtual QString label() const;
};

#endif // VISUALIZATION_FLOWEDGEITEM_H
