/*! \brief Window used to display graphs
 *
 * \file graphwindow.cpp
 * \author Alain Hardy
 * \date 19.05.2016
 */

#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"
#include "../graph/Includes.h"

GraphWindow::GraphWindow(QWidget *parent, const IGraph* graph, const QString& title) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    QWidget *graphWidget = new GraphWidget(graph);
    QLayout* l = new QVBoxLayout(this);
    l->addWidget(graphWidget);
    l->setMargin(0);

    ui->setupUi(this);

    setWindowTitle(title);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
