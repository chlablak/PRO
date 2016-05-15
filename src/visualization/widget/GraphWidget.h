#ifndef VISUALIZATION_WIDGET_GRAPHWIDGET_H
#define VISUALIZATION_WIDGET_GRAPHWIDGET_H

#include <QWidget>

#include "view/GraphView.h"
#include "igraph/IGraph.h"

class GraphWidget : public QWidget
{
private:
    GraphView *view;

public:
    GraphWidget(IGraph *graph);
    ~GraphWidget();

protected:
    virtual void paintEvent(QPaintEvent* event);
};

#endif // VISUALIZATION_WIDGET_GRAPHWIDGET_H
