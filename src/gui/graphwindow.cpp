#include "graphwindow.h"
#include "ui_graphwindow.h"



#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"

#include "../graph/Includes.h"

GraphWindow::GraphWindow(QWidget *parent, IGraph *graph) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    QWidget *graphWidget = new GraphWidget(graph);
    ui->horizontalLayout->addWidget(graphWidget);

    ui->setupUi(this);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
