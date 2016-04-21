#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "igraph.h"
#include "graphview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    IGraph *graph = new IGraph();

    QGraphicsView *view = new GraphView(graph);
    layout->addWidget(view);

    window.setLayout(layout);
    window.show();
    return app.exec();
}
