#ifndef VISUALIZATION_VERTEXITEM_H
#define VISUALIZATION_VERTEXITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QList>

#include "../../graph/graphs/Vertex.h"

#include "EdgeItem.h"

class EdgeItem;

class VertexItem : public QGraphicsItemGroup
{
public:
    const Vertex *_vertex;
    QList<EdgeItem *> _edgeItems;

    QGraphicsEllipseItem *_circle;
    QGraphicsTextItem *_text;
    QGraphicsTextItem *_label;

public:
    VertexItem(const Vertex *vertex);

    ~VertexItem();

    QPointF getCenter() const;

    void addEdge(EdgeItem *edge);

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_VERTEXITEM_H
