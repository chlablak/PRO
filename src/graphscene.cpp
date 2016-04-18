#include <qdebug>
#include <qtime>

#include "graphscene.h"

GraphScene::GraphScene(IGraph *graph)
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    for (IVertex *vertex : graph->getVertex()) {

        // Création du nouvel élément graphique
        VertexItem *vertexItem = new VertexItem(vertex);

        // Position aléatoire
        int x = qrand() % (int)(graph->getVertex().size() * 100);
        int y = qrand() % (int)(graph->getVertex().size() * 50);
        vertexItem->setPos(x, y);

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
