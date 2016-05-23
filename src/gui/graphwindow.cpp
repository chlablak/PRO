#include "graphwindow.h"
#include "ui_graphwindow.h"



#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"

#include "../graph/Includes.h"

GraphWindow::GraphWindow(QWidget *parent, const IGraph* graph, const QString& name) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    QWidget *graphWidget = new GraphWidget(graph);
    QLayout* l = new QVBoxLayout(this);
    l->addWidget(graphWidget);
    l->setMargin(0);

    ui->setupUi(this);

    setWindowTitle(name);
}

GraphWindow::~GraphWindow()
{
    delete ui;
}
