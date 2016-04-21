#ifndef VISUALIZATION_GRAPHSCENE_H
#define VISUALIZATION_GRAPHSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>

#include "igraph.h"
#include "vertexitem.h"
#include "edgeitem.h"

class GraphView : public QGraphicsView
{
    QGraphicsScene *scene;
    QList<VertexItem *> vertexItems;
    QList<EdgeItem *> edgeItems;

public:
    GraphView(IGraph *graph);
    ~GraphView();
};

#endif // VISUALIZATION_GRAPHSCENE_H
