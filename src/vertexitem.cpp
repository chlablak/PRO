#include <QPainter>
#include <QPen>
#include <QBrush>

#include "vertexitem.h"

VertexItem::VertexItem(IVertex *vertex)
    : vertex(vertex)
{}

VertexItem::~VertexItem()
{}

QRectF VertexItem::boundingRect() const
{
    return QRectF(pos().x(), pos().y(), radius, radius);
}

void VertexItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    QPen pen = painter->pen();
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    painter->setPen(pen);

    QBrush brush = painter->brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    painter->drawEllipse(boundingRect());

    painter->drawText(boundingRect(), Qt::AlignCenter, vertex->getName());
}
