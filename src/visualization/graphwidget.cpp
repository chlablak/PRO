#include <QDebug>
#include <QVBoxLayout>

#include "../graph/graphs/IGraph.h"

#include "GraphWidget.h"
#include "view/GraphView.h"
#include "view/GraphScene.h"

GraphWidget::GraphWidget(const IGraph *graph, QWidget *parent)
    : QWidget(parent)
{
    view = new GraphView();
    scene = new GraphScene(graph);
    view->setScene(scene);
    view->setRenderHints(QPainter::Antialiasing);
    layout = new QVBoxLayout();
    layout->addWidget(view);
    setLayout(layout);
}

GraphWidget::~GraphWidget() {
    delete layout;
    delete view;
    delete scene;
}
