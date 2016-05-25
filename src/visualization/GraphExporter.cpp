/*!
 * \brief IGraph exporter class
 *
 * \file GraphExporter.cpp
 * \author Damien Rochat
 * \date 23.05.2016
 */

#include <QPainter>
#include <QFileDialog>
#include <QSvgGenerator>

#include "../graph/graphs/IGraph.h"

#include "GraphExporter.h"
#include "view/GraphSceneManager.h"

void GraphExporter::SVG(const IGraph *graph)
{
    QString fileName = QFileDialog::getSaveFileName();
    SVG(graph, fileName);
}

void GraphExporter::SVG(const IGraph *graph, const QString &fileName)
{
    GraphScene *scene = GraphSceneManager::getInstance()->scene(graph);

    QSvgGenerator generator;
    generator.setFileName(fileName);
    generator.setSize(scene->sceneRect().size().toSize());

    QPainter painter;
    painter.begin(&generator);
    scene->render(&painter);
    painter.end();
}
