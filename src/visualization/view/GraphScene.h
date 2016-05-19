#ifndef VISUALIZATION_VIEW_GRAPHSCENE_H
#define VISUALIZATION_VIEW_GRAPHSCENE_H

#include <QGraphicsScene>
#include <QList>

#include "igraph/IGraph.h"
#include "VertexItem.h"
#include "EdgeItem.h"

class GraphScene : public QGraphicsScene
{
private:
    QList<VertexItem *> vertexItems;
    QList<EdgeItem *> edgeItems;

public:
    GraphScene(const IGraph *graph, QObject *parent = 0);
    ~GraphScene();
};

#endif // VISUALIZATION_VIEW_GRAPHSCENE_H
