/*! \brief Window used to display graphs
 *
 * \file graphwindow.h
 * \author Alain Hardy
 * \date 19.05.2016
 */

#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"
#include "../graph/Includes.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief GraphWindow
     * \param parent: Widget designated as the parent of the window
     * \param graph: Graph that will be displayed in the window
     * \param title: title of the window
     */
    explicit GraphWindow(QWidget *parent, const IGraph* graph, const QString& title);
    ~GraphWindow();

private:
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
