#ifndef VISUALIZATION_EDGEITEM_H
#define VISUALIZATION_EDGEITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>

#include "../../graph/graphs/IEdge.h"

#include "VertexItem.h"

class VertexItem;

class EdgeItem : public QGraphicsItemGroup
{
private:
    const IEdge *_edge;
    VertexItem *_sourceItem;
    VertexItem *_destItem;

    QPointF _sourcePoint;
    QPointF _destPoint;

    QGraphicsLineItem *_line;
    QGraphicsTextItem *_label;

public:
    EdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);
    virtual ~EdgeItem();

    virtual void adjust();

protected:
    virtual QString label() const;
    const IEdge *edge() const;
    VertexItem *sourceItem() const;
    VertexItem *destItem() const;
    QPointF sourcePoint() const;
    QPointF destPoint() const;
};

#endif // VISUALIZATION_EDGEEXITEM_H
