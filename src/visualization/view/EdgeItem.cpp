/*!
 * \brief Edge graphics item class
 *
 * \file EdgeItem.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QPainter>
#include <QPen>

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "../Constants.h"

EdgeItem::EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest)
    : _edge(edge), _sourceItem(source), _destItem(dest)
{
    setZValue(-1);

    // Set the source and destination vertex
    _sourceItem->addEdge(this);
    _destItem->addEdge(this);

    // Set the line
    QPen linePen = QPen(EDGE_COLOR);
    linePen.setWidth(EDGE_WIDTH);
    _line = new QGraphicsLineItem();
    _line->setPen(linePen);
    _line->setZValue(10);
    addToGroup(_line);

    // Set the label
    _label = new QGraphicsTextItem();
    _label->setDefaultTextColor(EDGE_LABEL_COLOR);
    _label->setZValue(30);
    addToGroup(_label);

    adjust();
}

EdgeItem::~EdgeItem()
{
    delete _line;
    delete _label;
}

void EdgeItem::adjust()
{
    QLineF line(_sourceItem->getCenter(), _destItem->getCenter());

    // Adjust line extremities to leave a blank space between extremities
    // and vertex graphics items (use Thalès)
    if (line.length() > 0) {
        qreal diff = (VERTEX_RADIUS +
                      VERTEX_BORDER_WIDTH / 2 +
                      EDGE_VERTEX_MARGIN) / line.length();
        qreal dx = line.dx() * diff;
        qreal dy = line.dy() * diff;
        _sourcePoint.setX(_sourceItem->getCenter().x() + dx);
        _sourcePoint.setY(_sourceItem->getCenter().y() + dy);
        _destPoint.setX(_destItem->getCenter().x() - dx);
        _destPoint.setY(_destItem->getCenter().y() - dy);
        _line->setLine(QLineF(_sourcePoint, _destPoint));
    }

    // Adjust the label position (over the circle)
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

