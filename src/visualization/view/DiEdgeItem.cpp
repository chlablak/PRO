#include <QDebug>
#include <QPainter>
#include <QtMath>

#include "../../graph/graphs/IEdge.h"

#include "DiEdgeItem.h"
#include "Constants.h"
#include "EdgeItem.h"

DiEdgeItem::DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{}

DiEdgeItem::~DiEdgeItem()
{}

QRectF DiEdgeItem::boundingRect() const
{
    return EdgeItem::boundingRect().adjusted(-EDGE_ARROW_SIZE,
                                             -EDGE_ARROW_SIZE,
                                             EDGE_ARROW_SIZE,
                                             EDGE_ARROW_SIZE);
}

void DiEdgeItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    EdgeItem::paint(painter, option, widget);

    QLineF line(sourceItem()->getCenter(), destItem()->getCenter());

    // Calcul des points de la flèche en direction du sommet de destination
    double angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }
    QPointF arrowP1 = destPoint() + QPointF(
                qSin(angle - M_PI / 3) * EDGE_ARROW_SIZE,
                qCos(angle - M_PI / 3) * EDGE_ARROW_SIZE
    );
    QPointF arrowP2 = destPoint() + QPointF(
                qSin(angle - 2 * M_PI / 3) * EDGE_ARROW_SIZE,
                qCos(angle - 2 * M_PI / 3) * EDGE_ARROW_SIZE
    );
    QPolygonF arrow;
    arrow.push_back(line.p2());
    arrow.push_back(arrowP1);
    arrow.push_back(arrowP2);

    // Dessin de la flèche
    QPen pen = painter->pen();
    pen.setColor(EDGE_COLOR);
    painter->setPen(pen);
    QBrush brush = painter->brush();
    brush.setColor(EDGE_COLOR);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(arrow);
}
