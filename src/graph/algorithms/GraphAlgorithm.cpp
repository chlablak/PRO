/*! \brief Provide all algorithms implemented in this project
 *
 * \file GraphAlgorithm.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "GraphAlgorithm.h"

// Visitors
#include "BFS.h"
#include "DFS.h"
#include "ConnectedComponent.h"
#include "Kruskal.h"
#include "CopyToDiGraph.h"
#include "CopyToGraph.h"
#include "CopyToFlowGraph.h"
#include "SCCTarjan.h"
#include "BellmanFordSP.h"
#include "DijkstraSP.h"
#include "DetectedCycle.h"
#include "TopologicalSort.h"
#include "FFEK.h"

IGraph *GraphAlgorithm::bfs(IGraph *g, Vertex *from, vector<double>& distances)
{
    Visitor *v = new BFS;
    g->accept(v, from);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::dfs(IGraph *g, Vertex *from, vector<double> &dfsnum)
{
    Visitor *v = new DFS;
    g->accept(v, from);
    dfsnum = v->table();
    return v->G();
}

vector<double> GraphAlgorithm::connectedComponent(IGraph *g)
{
    Visitor *v = new ConnectedComponent;
    g->accept(v);
    return v->table();
}

vector<double> GraphAlgorithm::stronglyConnectedComponent(IGraph *g)
{
    Visitor *v = new SCCTarjan;
    g->accept(v);
    return v->table();
}

IGraph *GraphAlgorithm::kruskal(IGraph *g)
{
    Visitor *v = new Kruskal;
    g->accept(v);
    return v->G();
}

IGraph *GraphAlgorithm::copyToDiGraph(IGraph *g)
{
    Visitor *v = new CopyToDiGraph;
    g->accept(v);
    return v->G();
}

IGraph *GraphAlgorithm::copyToGraph(IGraph *g)
{
    Visitor *v = new CopyToGraph;
    g->accept(v);
    return v->G();
}

IGraph *GraphAlgorithm::copyToFlowGraph(IGraph *g)
{
    Visitor *v = new CopyToFlowGraph;
    g->accept(v);
    return v->G();
}

IGraph *GraphAlgorithm::bellmanFord(IGraph *g, Vertex *from, vector<double>& distances)
{
    Visitor *v = new BellmanFordSP;
    g->accept(v, from);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::dijkstra(IGraph *g, Vertex *from, vector<double>& distances)
{
    Visitor *v = new DijkstraSP;
    g->accept(v, from);
    distances = v->table();
    return v->G();
}

IGraph *GraphAlgorithm::detectCycle(IGraph *g)
{
    Visitor *v = new DetectedCycle;
    g->accept(v, g->vertexList().front());
    return v->G();
}

vector<double> GraphAlgorithm::topologicalSort(IGraph *g)
{
    Visitor *v = new TopologicalSort;
    g->accept(v, g->vertexList().front());
    return v->table();
}

int GraphAlgorithm::maxFlow(IGraph *g, Vertex *from, Vertex *to)
{
    Visitor *v = new FFEK(g->V(), g->E());
    g->accept(v, from, to);
    return 0;
}










