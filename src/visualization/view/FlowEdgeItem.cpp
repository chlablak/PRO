#include <QDebug>
#include <QPainter>

#include "../../graph/graphs/IEdge.h"

#include "FlowEdgeItem.h"
#include "EdgeItem.h"
#include "../Constants.h"

FlowEdgeItem::FlowEdgeItem(const IEdge *edge,
                           VertexItem *source, VertexItem *dest)
    : EdgeItem(edge, source, dest)
{}

FlowEdgeItem::~FlowEdgeItem()
{}

QRectF FlowEdgeItem::boundingRect() const
{
    return EdgeItem::boundingRect(); // todo : adjust
}

void FlowEdgeItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    EdgeItem::paint(painter, option, widget);

    // todo
}
