#ifndef GRAPHY_VERTEXITEM_H
#define GRAPHY_VERTEXITEM_H

#include <QGraphicsEllipseItem>

#include "ivertex.h"

class VertexItem : public QGraphicsItem
{
    static const unsigned int radius = 50;

    IVertex * vertex;

public:
    VertexItem(IVertex *vertex);
    ~VertexItem();

public:
    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // GRAPHY_VERTEXITEM_H
