#ifndef VISUALIZATION_GRAPHWIDGET_H
#define VISUALIZATION_GRAPHWIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>

#include "igraph.h"
#include "vertexitem.h"
#include "edgeitem.h"

class GraphWidget : public QGraphicsView
{
private:
    QGraphicsScene *scene;
    QList<VertexItem *> vertexItems;
    QList<EdgeItem *> edgeItems;

public:
    GraphWidget(IGraph *graph);
    ~GraphWidget();
};

#endif // VISUALIZATION_GRAPHWIDGET_H
