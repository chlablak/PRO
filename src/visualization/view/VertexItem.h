/*!
 * \brief Vertex graphics item class
 *
 * \file EdgeItem.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_VERTEXITEM_H
#define VISUALIZATION_VERTEXITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QList>

#include "../../graph/graphs/Vertex.h"

#include "EdgeItem.h"

class EdgeItem;

class VertexItem : public QGraphicsItemGroup
{
public:

    /*!
     * \brief The represented Vertex
     */
    const Vertex *_vertex;

    /*!
     * \brief The linked edge graphics item
     */
    QList<EdgeItem *> _edgeItems;

    /*!
     * \brief The graphics items
     */
    QGraphicsEllipseItem *_circle;
    QGraphicsTextItem *_text;
    QGraphicsTextItem *_label;

public:

    /*!
     * \brief Constructor
     *
     * \param vertex - The represented vertex
     */
    VertexItem(const Vertex *vertex);

    /*!
     * \brief Destructor
     */
    ~VertexItem();

    /*!
     * \brief Center of the vertex
     *
     * \return the center of the circle representing the vertex
     *
     * It doesn't include de label to find the center of the item
     */
    QPointF getCenter() const;

    /*!
     * \brief Add a edge to the list of linked edges
     *
     * \param edge - The edge graphics item to link
     */
    void addEdge(EdgeItem *edge);

protected:

    /*!
     * \brief Override QGraphicsItem::itemChange()
     *
     * Used to handle edges position update in case of
     * vertex drag and drop.
     */
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_VERTEXITEM_H
