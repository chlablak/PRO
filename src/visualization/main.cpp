#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "igraph/IGraph.h"
#include "GraphWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();

    IGraph *graph = new IGraph();

    QWidget *widget = new GraphWidget(graph);
    layout->addWidget(widget);

    window.setLayout(layout);
    window.show();
    return app.exec();
}
