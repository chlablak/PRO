#ifndef VISUALIZATION_FLOWEDGEITEM_H
#define VISUALIZATION_FLOWEDGEITEM_H

#include "../../graph/graphs/IEdge.h"

#include "EdgeItem.h"
#include "items/ArrowItem.h"

class FlowEdgeItem : public EdgeItem
{
private:
    ArrowItem *_arrow;

public:
    FlowEdgeItem(const IEdge *edge, VertexItem *source, VertexItem *dest);
    virtual ~FlowEdgeItem();

    virtual void adjust();

protected:
    virtual QString label() const;
};

#endif // VISUALIZATION_FLOWEDGEITEM_H
