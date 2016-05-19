#ifndef VISUALIZATION_VERTEXITEM_H
#define VISUALIZATION_VERTEXITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QDebug>

#include "../../graph/graphs/Vertex.h"

#include "EdgeItem.h"

class EdgeItem;

class VertexItem : public QAbstractGraphicsShapeItem
{
public:
    const Vertex *vertex;
    QList<EdgeItem *> edgeItems;

public:
    VertexItem(const Vertex *vertex);

    ~VertexItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;
    
    QPointF getCenter() const;

    void addEdge(EdgeItem *edge);

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_VERTEXITEM_H
