#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QBrush>

#include "Constants.h"
#include "VertexItem.h"
#include "EdgeItem.h"

VertexItem::VertexItem(IVertex *vertex)
    : vertex(vertex)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

VertexItem::~VertexItem()
{}

QRectF VertexItem::boundingRect() const
{
    // Prend en compte la largeur du cercle
    // + la largeur de la bordure qui se trouve à cheval
    // sur le cercle et en dehors
    qreal width = VERTEX_RADIUS * 2 + VERTEX_BORDER_WIDTH;
    return QRectF(0, 0, width, width);
}

void VertexItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen = painter->pen();
    pen.setColor(VERTEX_BORDER_COLOR);
    pen.setWidth(VERTEX_BORDER_WIDTH);
    painter->setPen(pen);

    QBrush brush = painter->brush();
    brush.setColor(VERTEX_COLOR);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    painter->drawEllipse(boundingRect().center(), VERTEX_RADIUS, VERTEX_RADIUS);
    painter->drawText(boundingRect(), Qt::AlignCenter, vertex->getName());
}

QPointF VertexItem::getCenter() const
{
    qreal delta = VERTEX_RADIUS + VERTEX_BORDER_WIDTH / 2;
    return QPointF(x() + delta, y() + delta);
}

QVariant VertexItem::itemChange(GraphicsItemChange change,
                    const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        for (EdgeItem *edge : edgeItems) {
            edge->adjust();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

void VertexItem::addEdge(EdgeItem *edge)
{
    edgeItems.append(edge);
}
