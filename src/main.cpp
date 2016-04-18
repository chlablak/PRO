#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "igraph.h"
#include "graphscene.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    IGraph *graph = new IGraph();

    QGraphicsScene *scene = new GraphScene(graph);
    scene->setSceneRect(QRectF(0, 0, 1000, 1000));

    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);
    view->show();

    return app.exec();
}
