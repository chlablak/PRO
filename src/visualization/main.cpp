#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "GraphWidget.h"
#include "GraphExporter.h"

#include "../graph/Includes.h"

typedef Edge edge_t;
typedef Graph graph_t;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();

    Vertex *v1 = new Vertex("Vertex 1");
    Vertex *v2 = new Vertex("Vertex 2");
    Vertex *v3 = new Vertex("Vertex 3");
    Vertex *v4 = new Vertex("Vertex 4");

    IEdge *e1 = new edge_t(v1, v2, "Edge 1", 3.2);
    IEdge *e2 = new edge_t(v1, v4, "Edge 2", 1.0);
    IEdge *e3 = new edge_t(v4, v2, "Edge 1", 5.0);

    vector<Vertex *> vectices = { v1, v2, v3, v4 };
    vector<IEdge *> edges = { e1, e2, e3 };

    IGraph *graph = new graph_t(vectices, edges);

    // VUE
    QWidget *widget = new GraphWidget(graph);
    layout->addWidget(widget);

    // EXPORT SVG
    //GraphExporter exporter(graph);
    //exporter.exportSVG();

    //delete graph;

    window.setLayout(layout);
    window.show();
    return app.exec();
}
