#ifndef VISUALIZATION_VERTEXITEM_H
#define VISUALIZATION_VERTEXITEM_H

#include <QAbstractGraphicsShapeItem>

#include "ivertex.h"

class VertexItem : public QAbstractGraphicsShapeItem
{
public:
    IVertex *vertex;

public:
    VertexItem(IVertex *vertex);
    ~VertexItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;
    QPointF getCenter() const;
};

#endif // VISUALIZATION_VERTEXITEM_H
