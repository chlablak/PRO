#ifndef VISUALIZATION_VIEW_GRAPHVIEW_H
#define VISUALIZATION_VIEW_GRAPHVIEW_H

#include <QGraphicsView>

class GraphView : public QGraphicsView
{
public:
    GraphView(QWidget *parent = 0);
    ~GraphView();
};

#endif // VISUALIZATION_VIEW_GRAPHVIEW_H
