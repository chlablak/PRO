#ifndef VISUALIZATION_EDGEITEM_H
#define VISUALIZATION_EDGEITEM_H

#include <QAbstractGraphicsShapeItem>

#include "igraph/IEdge.h"
#include "VertexItem.h"

class VertexItem;

class EdgeItem : public QAbstractGraphicsShapeItem
{
private:
    IEdge *edge;
    VertexItem *sourceItem;
    VertexItem *destItem;

    QPointF sourcePoint;
    QPointF destPoint;

public:
    EdgeItem(IEdge *edge, VertexItem *source, VertexItem *dest);

    ~EdgeItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;

    void adjust();
};

#endif // VISUALIZATION_EDGEEXITEM_H
