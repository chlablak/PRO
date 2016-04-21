#ifndef VISUALIZATION_EDGEITEM_H
#define VISUALIZATION_EDGEITEM_H

#include <QAbstractGraphicsShapeItem>

#include "iedge.h"
#include "vertexitem.h"

class EdgeItem : public QAbstractGraphicsShapeItem
{
    IEdge *edge;
    VertexItem *from;
    VertexItem *to;
    QPointF pointFrom;
    QPointF pointTo;

public:
    EdgeItem(IEdge *edge, VertexItem *from, VertexItem *to);
    ~EdgeItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;
    void adjustExtremities();
};

#endif // VISUALIZATION_EDGEEXITEM_H
