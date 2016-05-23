#ifndef VISUALIZATION_DIEDGEITEM_H
#define VISUALIZATION_DIEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "items/ArrowItem.h"

class DiEdgeItem : public EdgeItem
{
private:
    ArrowItem *_arrow;

public:
    DiEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);
    virtual ~DiEdgeItem();

    virtual void adjust();
};

#endif // VISUALIZATION_DIEDGEITEM_H
