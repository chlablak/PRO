/*!
 * \brief Flow edge graphics item class
 *
 * \file FlowEdgeItem.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QPainter>
#include <QtMath>

#include "../../graph/graphs/FlowEdge.h"

#include "FlowEdgeItem.h"
#include "EdgeItem.h"
#include "../Constants.h"

FlowEdgeItem::FlowEdgeItem(const IEdge *edge,
                           VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{
    // Set the arrow
    _arrow = new ArrowItem(QPointF(0, 0), FLOWEDGE_ARROW_SIZE, 0,
                           FLOWEDGE_ARROW_COLOR);
    _arrow->setZValue(20);
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

    // Compute the angle to draw the arrow
    QLineF line(sourcePoint(), destPoint());
    qreal angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }

    // Compute the position of the arrow (middle of the line)
    QPointF point = (line.p1() + line.p2()) / 2;

    // Update the point and the angle of the arrow
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
