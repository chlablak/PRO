#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QFileDialog>
#include <QSvgGenerator>

#include "GraphExporter.h"
#include "view/GraphScene.h"

GraphExporter::GraphExporter(const IGraph* graph, QObject *parent)
    : scene(new GraphScene(graph)),
      QObject(parent)
{}

GraphExporter::~GraphExporter()
{
    delete scene;
}

void GraphExporter::exportSVG()
{
    exportSVG(scene);
}

void GraphExporter::exportSVG(const QString &fileName)
{
    exportSVG(scene, fileName);
}

void GraphExporter::exportSVG(GraphScene *scene)
{
    QString fileName = QFileDialog::getSaveFileName();
    exportSVG(scene, fileName);
}

void GraphExporter::exportSVG(GraphScene *scene, const QString &fileName)
{
    QSvgGenerator generator;
    generator.setFileName(fileName);
    generator.setSize(QSize(200, 200));
    generator.setViewBox(QRect(0, 0, 200, 200));

    QPainter painter;
    painter.begin(&generator);
    scene->render(&painter);
    painter.end();
}
