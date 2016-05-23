#include <QPainter>
#include <QtMath>

#include "../../graph/graphs/IEdge.h"

#include "DiEdgeItem.h"
#include "EdgeItem.h"
#include "../Constants.h"

DiEdgeItem::DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{
    // Création de la flèche
    _arrow = new ArrowItem(destPoint(), EDGE_ARROW_SIZE, 0, EDGE_COLOR);
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

    // Calcul de l'angle de la flèche
    QLineF line(sourcePoint(), destPoint());
    qreal angle = qAcos(line.dx() / line.length());
    if (line.dy() >= 0) {
        angle = 2 * M_PI - angle;
    }

    _arrow->setPoint(destPoint());
    _arrow->setAngle(angle);
}
