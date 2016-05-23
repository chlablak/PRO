/*!
 * \brief IGraph exporter class
 *
 * \file GraphExporter.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_GRAPHEXPORTER_H
#define VISUALIZATION_GRAPHEXPORTER_H

#include <QObject>

#include "../graph/graphs/IGraph.h"

#include "view/GraphScene.h"

class GraphExporter : public QObject
{
private:

    /*!
     * \brief The graph scene to export
     */
    GraphScene *scene;

public:

    /*!
     * \brief Constructor
     *
     * \param graph - Graph to represent
     * \param parent - An optionnal parent object
     */
    GraphExporter(const IGraph* graph, QObject *parent = 0);

    /*!
     * \brief Destructor
     */
    ~GraphExporter();

    /*!
     * \brief Export the representation to SVG
     *
     * No file specified, display a new file path window.
     */
    void exportSVG();

    /*!
     * \brief Export the representation to SVG
     *
     * File specified, save to it if exists.
     */
    void exportSVG(const QString &fileName);

    /*!
     * \brief Export the given scene to SVG
     *
     * \param scene - The scene to export
     *
     * No file specified, display a new file path window.
     */
    static void exportSVG(GraphScene *scene);

    /*!
     * \brief Export the given scene to SVG
     *
     * \param scene - The scene to export
     *
     * File specified, save to it if exists.
     */
    static void exportSVG(GraphScene *scene, const QString &fileName);
};

#endif // VISUALIZATION_GRAPHEXPORTER_H
