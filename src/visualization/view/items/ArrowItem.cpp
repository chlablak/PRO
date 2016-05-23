/*!
 * \brief Arrow graphics item class
 *
 * \file ArrowItem.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QPen>
#include <QDebug>
#include <QBrush>
#include <QtMath>

#include "ArrowItem.h"

ArrowItem::ArrowItem(QPointF point, qreal width, qreal angle, QColor color)
    : _point(point), _width(width), _angle(angle), _color(color)
{
    doShape();
}

ArrowItem::~ArrowItem()
{}

void ArrowItem::setWidth(qreal width)
{
    _width = width;
    doShape();
}

void ArrowItem::setPoint(QPointF point)
{
    _point = point;
    doShape();
}

void ArrowItem::setAngle(qreal angle)
{
    _angle = angle;
    doShape();
}

void ArrowItem::setColor(QColor color)
{
    _color = color;
    doShape();
}

QRectF ArrowItem::boundingRect() const
{
    return _shape.boundingRect();
}

void ArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(_color);
    painter->setBrush(brush);
    painter->drawPolygon(_shape);
}

void ArrowItem::doShape()
{
    QPointF arrowP1 = _point + QPointF(
                qSin(_angle - M_PI / 3) * _width,
                qCos(_angle - M_PI / 3) * _width
    );
    QPointF arrowP2 = _point + QPointF(
                qSin(_angle - M_PI + M_PI / 3) * _width,
                qCos(_angle - M_PI + M_PI / 3) * _width
    );
    _shape.clear();
    _shape.push_back(_point);
    _shape.push_back(arrowP1);
    _shape.push_back(arrowP2);

    // Indicates that the item shape and
    // the bounding rect has changed
    prepareGeometryChange();
}
