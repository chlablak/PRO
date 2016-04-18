#include <QDebug>

#include "graphscene.h"

GraphScene::GraphScene(IGraph *graph)
{
    const int GRID_WIDTH = 4;
    int x = 1;
    int y = 1;

    for (IVertex *vertex : graph->getVertex()) {

        // Création du nouvel élément graphique
        VertexItem *vertexItem = new VertexItem(vertex);

        // Sommets positionnés sur une grille
        if (x == 5) {
            x = 1;
            y++;
        }
        vertexItem->setPos(x * 50, y * 50);
        x++;

        // Ajout de l'élément graphique à la liste
        vertexItems.push_back(vertexItem);
        this->addItem(vertexItem);
    }
}

GraphScene::~GraphScene() {
    for (VertexItem *v : vertexItems) {
        delete v;
    }
}
