/*!
 * \brief Visualization scene class
 *
 * \file GraphScene.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_VIEW_GRAPHSCENE_H
#define VISUALIZATION_VIEW_GRAPHSCENE_H

#include <QGraphicsScene>
#include <QList>

#include "../../graph/graphs/IGraph.h"

#include "VertexItem.h"
#include "EdgeItem.h"

class GraphScene : public QGraphicsScene
{
private:

    /*!
     * \brief The graphics items
     */
    QList<VertexItem *> vertexItems;
    QList<EdgeItem *> edgeItems;

public:

    /*!
     * \brief Constructor
     *
     * \param graph - The IGraph to represent
     * \param parent - An optional parent
     */
    GraphScene(const IGraph *graph, QObject *parent = 0);

    /*!
     * \brief Destructor
     */
    ~GraphScene();
};

#endif // VISUALIZATION_VIEW_GRAPHSCENE_H
