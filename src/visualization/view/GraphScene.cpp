/*!
 * \brief Visualization scene class
 *
 * \file GraphScene.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

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
    // Init the corresponding factory
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

    // Create and add each vertex to the scene
    for (Vertex *vertex : graph->vertexList()) {
        VertexItem *vertexItem = new VertexItem(vertex);

        // Vertex on a grid of 4 columns
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

    // Create and add each vertex to the edges
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

