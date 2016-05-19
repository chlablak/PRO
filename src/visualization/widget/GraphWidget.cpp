#include <QDebug>
//#include <QFileDialog>
//#include <QSvgGenerator>

#include "GraphWidget.h"
#include "view/GraphView.h"

GraphWidget::GraphWidget(IGraph *graph)
    : view(new GraphView(graph)),
      QWidget()
{

    /*
    QSvgGenerator generator;
    generator.setFileName("/Users/damienrochat/Cours/Bachelor/PRO/src/visualization/test.svg");
    generator.setSize(QSize(200, 200));
    generator.setViewBox(QRect(0, 0, 200, 200));
    generator.setTitle(tr("SVG Generator Example Drawing"));
    generator.setDescription(tr("An SVG drawing created by the SVG Generator "
                                "Example provided with Qt."));

    QPainter painter;
    painter.begin(&generator);
    scene->render(&painter);
    painter.end();*/

}

GraphWidget::~GraphWidget()
{
    delete view;
}

void GraphWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);

}
