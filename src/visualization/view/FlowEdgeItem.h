#ifndef VISUALIZATION_FLOWEDGEITEM_H
#define VISUALIZATION_FLOWEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"

class FlowEdgeItem : public EdgeItem
{
public:
    FlowEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);

    virtual ~FlowEdgeItem();

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget = 0) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_FLOWEDGEITEM_H
