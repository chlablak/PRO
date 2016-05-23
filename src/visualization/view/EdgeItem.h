/*!
 * \brief Edge graphics item class
 *
 * \file EdgeItem.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_EDGEITEM_H
#define VISUALIZATION_EDGEITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

#include "../../graph/graphs/IEdge.h"

#include "VertexItem.h"

class VertexItem;

class EdgeItem : public QGraphicsItemGroup
{
private:

    /*!
     * \brief The represented IEdge
     */
    const IEdge *_edge;

    /*!
     * \brief The source and the destination vertex graphics item
     */
    VertexItem *_sourceItem;
    VertexItem *_destItem;

    /*!
     * \brief The source and destination points of the line
     */
    QPointF _sourcePoint;
    QPointF _destPoint;

    /*!
     * \brief The graphics items
     */
    QGraphicsLineItem *_line;
    QGraphicsTextItem *_label;

public:

    /*!
     * \brief Constructor
     *
     * \param edge - The represented IEdge
     * \param source - The source vertex graphics item
     * \param dest - The destination vertex graphics item
     */
    EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    /*!
     * \brief Destructor
     */
    virtual ~EdgeItem();

    /*!
     * \brief Methods adjusting the items
     *
     * Called when a vertex has been dragged and dropped.
     */
    virtual void adjust();

protected:

    /*!
     * \brief Accessors
     */
    virtual QString label() const;
    const IEdge *edge() const;
    VertexItem *sourceItem() const;
    VertexItem *destItem() const;
    QPointF sourcePoint() const;
    QPointF destPoint() const;
};

#endif // VISUALIZATION_EDGEEXITEM_H
