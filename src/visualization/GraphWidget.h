#ifndef VISUALIZATION_GRAPHWIDGET_H
#define VISUALIZATION_GRAPHWIDGET_H

#include <QWidget>
#include <QLayout>

#include "../graph/graphs/IGraph.h"

#include "view/GraphView.h"
#include "view/GraphScene.h"

class GraphWidget : public QWidget
{
private:
    GraphView *view;
    GraphScene *scene;
    QLayout *layout;

public:
    GraphWidget(const IGraph *graph, QWidget *parent = 0);
    ~GraphWidget();
};

#endif // VISUALIZATION_GRAPHWIDGET_H
