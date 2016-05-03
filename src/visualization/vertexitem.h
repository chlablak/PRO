#ifndef VISUALIZATION_VERTEXITEM_H
#define VISUALIZATION_VERTEXITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QDebug>

#include "ivertex.h"
#include "iedge.h"

class EdgeItem;

class VertexItem : public QAbstractGraphicsShapeItem
{
public:
    IVertex *vertex;
    QList<EdgeItem *> edgeItems;

public:
    VertexItem(IVertex *vertex);

    ~VertexItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) Q_DECL_OVERRIDE;
    
    QPointF getCenter() const;

    void addEdge(EdgeItem *edge);

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value) Q_DECL_OVERRIDE;
};

#endif // VISUALIZATION_VERTEXITEM_H
