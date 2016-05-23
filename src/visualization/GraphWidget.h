/*!
 * \brief IGraph widget visualizer class
 *
 * \file GraphWidget.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

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

    /*!
     * \brief The graph view
     */
    GraphView *view;

    /*!
     * \brief The graph scene
     */
    GraphScene *scene;

    /*!
     * \brief The layout used by the scene
     */
    QLayout *layout;

public:

    /*!
     * \brief Constructor
     *
     * \param graph - Graph to represent
     * \param parent - An optionnal parent object
     */
    GraphWidget(const IGraph *graph, QWidget *parent = 0);

    /*!
     * \brief Destructor
     */
    ~GraphWidget();
};

#endif // VISUALIZATION_GRAPHWIDGET_H
