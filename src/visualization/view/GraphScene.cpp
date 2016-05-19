#include <QDebug>
#include <QGraphicsScene>

#include "GraphScene.h"
#include "view/EdgeItem.h"
#include "view/VertexItem.h"
#include "igraph/IGraph.h"

GraphScene::GraphScene(const IGraph *graph, QObject *parent)
    : QGraphicsScene(parent)
{
    const int GRID_WIDTH = 4;
    int x = 0;
    int y = 0;

    // Création et ajout des sommets à la scéne
    for (IVertex *vertex : graph->getVertices()) {
        VertexItem *vertexItem = new VertexItem(vertex);

        // todo : nombre de colonnes selon largeur du parent
        // Sommets positionnés sur une grille
        if (x >= GRID_WIDTH) {
            x = 0;
            y++;
        }
        vertexItem->setPos(x * 100, y * 100);
        x++;

        vertexItems.append(vertexItem);
        addItem(vertexItem);
        vertexItem->setVisible(true);
    }

    // Création et ajout des arcs et arêtes à la scéne
    for (IEdge *edge : graph->getEdges()) {
        EdgeItem *edgeItem = new EdgeItem(
            edge,
            vertexItems.at(edge->getFrom()->getId()),
            vertexItems.at(edge->getTo()->getId())
        );

        edgeItems.append(edgeItem);
        addItem(edgeItem);
        edgeItem->setVisible(true);
    }

}

GraphScene::~GraphScene()
{
    for (VertexItem *v : vertexItems) {
        delete v;
    }
    for (EdgeItem *e : edgeItems) {
        delete e;
    }
}

