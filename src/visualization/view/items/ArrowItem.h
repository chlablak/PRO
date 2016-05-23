/*!
 * \brief Arrow graphics item class
 *
 * \file ArrowItem.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_ARROWITEM_H
#define VISUALIZATION_ARROWITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QPainter>

class ArrowItem : public QAbstractGraphicsShapeItem
{
private:

    /*!
     * \brief Arrow proprieties
     */
    QPointF _point;
    qreal _width;
    qreal _angle;
    QColor _color;
    QPolygonF _shape;

public:

    /*!
     * \brief Constructor
     *
     * \param point - Base point of the arrow (head)
     * \param width - Width ot the arrow
     * \param angle - Angle of the arrow
     * \param color - Color of the arrow (default light gray)
     *
     * \todo Implement border
     */
    ArrowItem(QPointF point, qreal width, qreal angle,
              QColor color = Qt::lightGray);

    /*!
     * \brief Destructor
     */
    virtual ~ArrowItem();

    /*!
     * \brief Modifiers
     */
    void setWidth(qreal width);
    void setPoint(QPointF point);
    void setAngle(qreal angle);
    void setColor(QColor color);

    /*!
     * \brief Implementation of QGraphicsItem pure virtual methods
     */
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) Q_DECL_OVERRIDE;

private:

    /*!
     * \brief Compute the arrow shape
     *
     * \todo Center the arrow around the point
     */
    void doShape();
};

#endif // VISUALIZATION_ARROWITEM_H
