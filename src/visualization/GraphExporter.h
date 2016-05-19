#ifndef VISUALIZATION_GRAPHEXPORTER_H
#define VISUALIZATION_GRAPHEXPORTER_H

#include <QObject>

#include "../graph/graphs/IGraph.h"

#include "view/GraphScene.h"

class GraphExporter : public QObject
{
private:
    GraphScene *scene;

public:
    GraphExporter(const IGraph* graph, QObject *parent = 0);
    ~GraphExporter();

    void exportSVG();
    void exportSVG(const QString &fileName);
    static void exportSVG(GraphScene *scene);
    static void exportSVG(GraphScene *scene, const QString &fileName);
};

#endif // VISUALIZATION_GRAPHEXPORTER_H
