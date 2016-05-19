#ifndef VISUALIZATION_EDGEITEM_H
#define VISUALIZATION_EDGEITEM_H

#include <QAbstractGraphicsShapeItem>

#include "../../graph/graphs/IEdge.h"

#include "VertexItem.h"

class VertexItem;

class EdgeItem : public QAbstractGraphicsShapeItem
{
private:
    const IEdge *_edge;
    VertexItem *_sourceItem;
    VertexItem *_destItem;

    QPointF _sourcePoint;
    QPointF _destPoint;

public:
    EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    virtual ~EdgeItem();

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) Q_DECL_OVERRIDE;

    void adjust();

protected:
    const IEdge *edge() const;
    VertexItem *sourceItem() const;
    VertexItem *destItem() const;
    QPointF sourcePoint() const;
    QPointF destPoint() const;
};

#endif // VISUALIZATION_EDGEEXITEM_H
