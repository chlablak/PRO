/*!
 * \brief Tests for IGraph visualization
 *
 * \file main.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>

#include "GraphWidget.h"
#include "GraphExporter.h"

#include "../graph/Includes.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();

    // GRAPH

    Vertex *v11 = new Vertex("Vertex 1");
    Vertex *v12 = new Vertex("Vertex 2");
    Vertex *v13 = new Vertex("Vertex 3");
    Vertex *v14 = new Vertex("Vertex 4");

    IEdge *e11 = new Edge(v11, v12, "Edge 1", 3.2);
    IEdge *e12 = new Edge(v11, v14, "Edge 2", 1.0);
    IEdge *e13 = new Edge(v14, v12, "Edge 1", 5.0);

    vector<Vertex *> vectices1 = { v11, v12, v13, v14 };
    vector<IEdge *> edges1 = { e11, e12, e13 };

    IGraph *graph1 = new Graph(vectices1, edges1);

    QWidget *widget1 = new GraphWidget(graph1);
    layout->addWidget(widget1);

    // DIGRAPH

    Vertex *v21 = new Vertex("Vertex 1");
    Vertex *v22 = new Vertex("Vertex 2");
    Vertex *v23 = new Vertex("Vertex 3");
    Vertex *v24 = new Vertex("Vertex 4");

    IEdge *e21 = new DiEdge(v21, v22, "Edge 1", 3.2);
    IEdge *e22 = new DiEdge(v21, v24, "Edge 2", 1.0);
    IEdge *e23 = new DiEdge(v24, v22, "Edge 1", 5.0);

    vector<Vertex *> vectices2 = { v21, v22, v23, v24 };
    vector<IEdge *> edges2 = { e21, e22, e23 };

    IGraph *graph2 = new DiGraph(vectices2, edges2);

    QWidget *widget2 = new GraphWidget(graph2);
    layout->addWidget(widget2);

    // FLOWGRAPH

    Vertex *v31 = new Vertex("Vertex 1");
    Vertex *v32 = new Vertex("Vertex 2");
    Vertex *v33 = new Vertex("Vertex 3");
    Vertex *v34 = new Vertex("Vertex 4");

    IEdge *e31 = new FlowEdge(v31, v32, "Edge 1", 3.2);
    IEdge *e32 = new FlowEdge(v31, v34, "Edge 2", 1.0);
    IEdge *e33 = new FlowEdge(v34, v32, "Edge 1", 5.0);

    vector<Vertex *> vectices3 = { v31, v32, v33, v34 };
    vector<IEdge *> edges3 = { e31, e32, e33 };

    IGraph *graph3 = new FlowGraph(vectices3, edges3);

    QWidget *widget3 = new GraphWidget(graph3);
    layout->addWidget(widget3);

    // EXPORT SVG

    //GraphExporter exporter(graph3);
    //exporter.exportSVG();

    window.setLayout(layout);
    window.show();
    return app.exec();
}
