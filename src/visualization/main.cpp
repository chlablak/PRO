#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "igraph.h"
#include "graphwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout;

    IGraph *graph = new IGraph();

    GraphWidget *view = new GraphWidget(graph);
    layout->addWidget(view);

    window.setLayout(layout);
    window.show();
    return app.exec();
}
