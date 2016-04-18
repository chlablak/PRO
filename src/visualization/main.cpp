#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "graphscene.h"
#include "igraph.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    IGraph *graph = new IGraph();

    QGraphicsScene *scene = new GraphScene(graph);
    scene->setSceneRect(QRectF(0, 0, 500, 500));

    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);

    layout->addWidget(view);

    window.setLayout(layout);
    window.show();
    return app.exec();
}
