#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "igraph/IGraph.h"
#include "GraphWidget.h"
#include "GraphExporter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();

    IGraph *graph = new IGraph();

    // VUE
    QWidget *widget = new GraphWidget(graph);
    layout->addWidget(widget);

    // EXPORT SVG
    GraphExporter exporter(graph);
    exporter.exportSVG();

    window.setLayout(layout);
    window.show();
    return app.exec();
}
