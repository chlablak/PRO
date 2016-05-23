#include <QGraphicsScene>

#include "../../graph/graphs/IGraph.h"
#include "../../graph/graphs/Graph.h"
#include "../../graph/graphs/DiGraph.h"
#include "../../graph/graphs/FlowGraph.h"
#include "../../graph/graphs/Vertex.h"
#include "../../graph/graphs/IEdge.h"

#include "GraphScene.h"
#include "EdgeItem.h"
#include "VertexItem.h"
#include "AbstractGraphItemFactory.h"
#include "GraphItemFactory.h"
#include "DiGraphItemFactory.h"
#include "FlowGraphItemFactory.h"

GraphScene::GraphScene(const IGraph *graph, QObject *parent)
    : QGraphicsScene(parent)
{
    // Création de la factory correspondante au bon type de graphe
    AbstractGraphItemFactory *factory;
    if (dynamic_cast<const FlowGraph *>(graph)) {
        factory = new FlowGraphItemFactory();
    }
    else if (dynamic_cast<const DiGraph *>(graph)) {
        factory = new DiGraphItemFactory();
    }
    else if (dynamic_cast<const Graph *>(graph)) {
        factory = new GraphItemFactory();
    }
    else {
        throw new runtime_error("Graph type unknown");
    }

    const int GRID_WIDTH = 4;
    int x = 0;
    int y = 0;

    // Création et ajout des sommets à la scène
    for (Vertex *vertex : graph->vertexList()) {
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

    // Création et ajout des arcs et arêtes à la scène
    for (IEdge *edge : graph->edgeList()) {
        EdgeItem *edgeItem = factory->createEdge(
            edge,
            vertexItems.at(edge->from()->id()),
            vertexItems.at(edge->to()->id())
        );
        edgeItems.append(edgeItem);
        addItem(edgeItem);
        edgeItem->setVisible(true);
    }

    delete factory;
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

