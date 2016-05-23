#include <QPainter>
#include <QtMath>
#include <QDebug>

#include "../../graph/graphs/IEdge.h"
#include "../../graph/graphs/FlowEdge.h"

#include "FlowEdgeItem.h"
#include "EdgeItem.h"
#include "../Constants.h"

FlowEdgeItem::FlowEdgeItem(const IEdge *edge,
                           VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{
    // Création de la flèche
    _arrow = new ArrowItem(QPointF(0, 0), FLOWEDGE_ARROW_SIZE, 0,
                           FLOWEDGE_ARROW_COLOR);
    addToGroup(_arrow);

    adjust();
}

FlowEdgeItem::~FlowEdgeItem()
{
    delete _arrow;
}

void FlowEdgeItem::adjust()
{
    EdgeItem::adjust();

    // Calcul de l'angle de la flèche
    QLineF line(sourcePoint(), destPoint());
    qreal angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }

    // Calcul de la position de la flèche (centre de la ligne)
    QPointF point = (line.p1() + line.p2()) / 2;

    _arrow->setPoint(point);
    _arrow->setAngle(angle);
}

QString FlowEdgeItem::label() const
{
    const FlowEdge *edge = dynamic_cast<const FlowEdge *>(EdgeItem::edge());
    if (edge != NULL) {
        return QString("%1, [%2,%3]")
                .arg(EdgeItem::label())
                .arg(edge->minCapacity())
                .arg(edge->maxCapacity());
    }
    return EdgeItem::label();
}
