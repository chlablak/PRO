/*!
 * \brief Visualization view class
 *
 * \file GraphView.h
 * \author Damien Rochat
 * \date 23.05.2016
 */

#ifndef VISUALIZATION_GRAPHVIEW_H
#define VISUALIZATION_GRAPHVIEW_H

#include <QGraphicsView>

class GraphView : public QGraphicsView
{
public:

    /*!
     * \brief Constructor
     *
     * \param parent - Optional parent widget
     */
    GraphView(QWidget *parent = 0);

    /*!
     * \brief Deconstructor
     */
    ~GraphView();
};

#endif // VISUALIZATION_GRAPHVIEW_H
