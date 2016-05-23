#ifndef VISUALIZATION_ARROWITEM_H
#define VISUALIZATION_ARROWITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QPainter>

class ArrowItem : public QAbstractGraphicsShapeItem
{
private:
    QPointF _point;
    qreal _width;
    qreal _angle;
    QColor _color;
    QPolygonF _shape;

public:
    ArrowItem(QPointF point, qreal width, qreal angle,
              QColor color = Qt::lightGray);
    virtual ~ArrowItem();

    void setWidth(qreal width);
    void setPoint(QPointF point);
    void setAngle(qreal angle);
    void setColor(QColor color);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) Q_DECL_OVERRIDE;

private:
    void doShape();
};

#endif // VISUALIZATION_ARROWITEM_H
