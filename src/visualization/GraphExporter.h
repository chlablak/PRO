/*!
 * \brief IGraph exporter class
 *
 * \file GraphExporter.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_GRAPHEXPORTER_H
#define VISUALIZATION_GRAPHEXPORTER_H

#include "../graph/graphs/IGraph.h"

#include "view/GraphScene.h"

class GraphExporter
{
public:

    /*!
     * \brief Export the representation to SVG
     *
     * \param graph - The graph to export
     *
     * No file specified, display a new file path window.
     */
    static void SVG(const IGraph *graph);

    /*!
     * \brief Export the representation to SVG
     *
     * \param graph - The graph to export
     *
     * File specified, save to it if exists.
     */
    static void SVG(const IGraph *graph, const QString &fileName);
};

#endif // VISUALIZATION_GRAPHEXPORTER_H
