#ifndef VISUALIZATION_DIEDGEITEM_H
#define VISUALIZATION_DIEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "DiEdgeItem.h"
#include "EdgeItem.h"

class DiEdgeItem : public EdgeItem
{
public:
    DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    virtual ~DiEdgeItem();

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_DIEDGEITEM_H
