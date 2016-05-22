#include <QPen>
#include <QBrush>
#include <QString>

#include "../../graph/graphs/Vertex.h"

#include "../Constants.h"
#include "VertexItem.h"
#include "EdgeItem.h"

VertexItem::VertexItem(const Vertex *vertex)
    : _vertex(vertex)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

    QPen circlePen = QPen(VERTEX_BORDER_COLOR);
    circlePen.setWidth(VERTEX_BORDER_WIDTH);
    QBrush circleBrush = QBrush(VERTEX_COLOR);
    _circle = new QGraphicsEllipseItem();
    _circle->setRect(QRectF(0, 0, VERTEX_RADIUS * 2, VERTEX_RADIUS * 2));
    _circle->setPen(circlePen);
    _circle->setBrush(circleBrush);
    addToGroup(_circle);
    QRectF circleRect = _circle->boundingRect();

    _text = new QGraphicsTextItem(QString("v%1").arg(vertex->id()));
    QRectF textRect = _text->boundingRect();
    _text->setPos(
                (circleRect.width() - textRect.width()) / 2,
                (circleRect.height() - textRect.height()) / 2
    );
    _text->setDefaultTextColor(VERTEX_TEXT_COLOR);
    addToGroup(_text);

    _label = new QGraphicsTextItem(QString::fromStdString(vertex->label()));
    QRectF labelRect = _label->boundingRect();
    _label->setPos(
                (circleRect.width() - labelRect.width()) / 2,
                -textRect.height()
    );
    _label->setDefaultTextColor(VERTEX_LABEL_COLOR);
    addToGroup(_label);
}

VertexItem::~VertexItem()
{
    delete _circle;
    delete _text;
    delete _label;
}

QPointF VertexItem::getCenter() const
{
    qreal delta = VERTEX_RADIUS + VERTEX_BORDER_WIDTH / 2;
    return QPointF(x() + delta, y() + delta);
}

void VertexItem::addEdge(EdgeItem *edge)
{
    _edgeItems.append(edge);
}

QVariant VertexItem::itemChange(GraphicsItemChange change,
                    const QVariant &value)
{    
    if (change == ItemPositionChange && scene()) {
        for (EdgeItem *edge : _edgeItems) {
            edge->adjust();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}
