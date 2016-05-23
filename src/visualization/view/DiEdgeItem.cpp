/*!
 * \brief Directed edge graphics item class
 *
 * \file DiEdgeItem.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QPainter>
#include <QtMath>

#include "../../graph/graphs/IEdge.h"

#include "DiEdgeItem.h"
#include "EdgeItem.h"
#include "../Constants.h"

DiEdgeItem::DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{
    // Set the arrow
    _arrow = new ArrowItem(destPoint(), EDGE_ARROW_SIZE, 0, EDGE_COLOR);
    _arrow->setZValue(30);
    addToGroup(_arrow);

    adjust();
}

DiEdgeItem::~DiEdgeItem()
{
    delete _arrow;
}

void DiEdgeItem::adjust()
{
    EdgeItem::adjust();

    // Compute the angle to draw the arrow
    QLineF line(sourcePoint(), destPoint());
    qreal angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }

    // Update the point and the angle of the arrow
    _arrow->setPoint(destPoint());
    _arrow->setAngle(angle);
}
