#ifndef VISUALIZATION_GRAPHSCENE_H
#define VISUALIZATION_GRAPHSCENE_H

#include <QLinkedList>
#include <QGraphicsScene>

#include "igraph.h"
#include "vertexitem.h"

class GraphScene : public QGraphicsScene
{
    QLinkedList<VertexItem*> vertexItems;

public:
    GraphScene(IGraph *graph);
    ~GraphScene();
};

#endif // VISUALIZATION_GRAPHSCENE_H
