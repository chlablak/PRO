#include <QPainter>
#include <QDebug>

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "../Constants.h"

EdgeItem::EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : _edge(edge), _sourceItem(source), _destItem(dest)
{
    setAcceptedMouseButtons(0);
    setZValue(-1);

    _sourceItem->addEdge(this);
    _destItem->addEdge(this);

    adjust();
}

EdgeItem::~EdgeItem()
{}

QRectF EdgeItem::boundingRect() const
{
    return QRectF(_sourcePoint, _destPoint).normalized();
}

void EdgeItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Dessin de la ligne
    QPen pen = painter->pen();
    pen.setColor(EDGE_COLOR);
    pen.setWidth(EDGE_WIDTH);
    painter->setPen(pen);

    painter->drawLine(QLineF(_sourcePoint, _destPoint));
}

// Ajuste les extrémités de la ligne pour que celle-ci ne soit
// pas dessinée jusqu'au centre des sommets, mais en bordure
// de ceux-ci (rayon du sommet + bordure du sommet / 2 + marge).
// Effectue un décalage au début et à la fin de la ligne par thalès.
void EdgeItem::adjust()
{
    QLineF line(_sourceItem->getCenter(), _destItem->getCenter());

    qreal diff = (VERTEX_RADIUS +
                  VERTEX_BORDER_WIDTH / 2 +
                  EDGE_VERTEX_MARGIN) / line.length();
    qreal dx = line.dx() * diff;
    qreal dy = line.dy() * diff;

    prepareGeometryChange();

    _sourcePoint.setX(_sourceItem->getCenter().x() + dx);
    _sourcePoint.setY(_sourceItem->getCenter().y() + dy);
    _destPoint.setX(_destItem->getCenter().x() - dx);
    _destPoint.setY(_destItem->getCenter().y() - dy);

    update();
}

const IEdge *EdgeItem::edge() const
{
    return _edge;
}

VertexItem *EdgeItem::sourceItem() const
{
    return _sourceItem;
}

VertexItem *EdgeItem::destItem() const
{
    return _destItem;
}

QPointF EdgeItem::sourcePoint() const
{
    return _sourcePoint;
}

QPointF EdgeItem::destPoint() const
{
    return _destPoint;
}

