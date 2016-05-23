#include <QPainter>
#include <QPen>

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

    QPen linePen = QPen(EDGE_COLOR);
    linePen.setWidth(EDGE_WIDTH);
    _line = new QGraphicsLineItem();
    _line->setPen(linePen);
    addToGroup(_line);

    _label = new QGraphicsTextItem();
    _label->setDefaultTextColor(EDGE_LABEL_COLOR);
    addToGroup(_label);

    adjust();
}

EdgeItem::~EdgeItem()
{
    delete _line;
    delete _label;
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

    _sourcePoint.setX(_sourceItem->getCenter().x() + dx);
    _sourcePoint.setY(_sourceItem->getCenter().y() + dy);
    _destPoint.setX(_destItem->getCenter().x() - dx);
    _destPoint.setY(_destItem->getCenter().y() - dy);

    // Ajustement de la position de la ligne
    _line->setLine(QLineF(_sourcePoint, _destPoint));

    // Ajustement de la position du label
    _label->setPlainText(label());
    QPointF labelCenter = QPointF((_sourcePoint + _destPoint) / 2);
    labelCenter -= QPointF(
                _label->boundingRect().width() / 2,
                _label->boundingRect().height() / 2
                );
    _label->setPos(labelCenter);
}

QString EdgeItem::label() const
{
    return QString("%1").arg(_edge->weight());
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

