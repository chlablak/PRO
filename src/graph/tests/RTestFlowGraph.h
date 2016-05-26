//
// Created by sebri on 21.05.2016.
//

#ifndef GRAPH_RTESTFLOWGRAPH_H
#define GRAPH_RTESTFLOWGRAPH_H

#include <cassert>
#include "../includes.h"

class RTestFlowGraph
{
private:
    IGraph *_G;
public:
    RTestFlowGraph() : _G(nullptr) {
        // Create vertices
        Vertex *v1 = new Vertex("v1");
        Vertex *v2 = new Vertex("v2");
        Vertex *v3 = new Vertex("v3");
        Vertex *v4 = new Vertex("v4");
        Vertex *v5 = new Vertex("v5");
        Vertex *v6 = new Vertex("v6");
        Vertex *v7 = new Vertex("v7");

        // Associate Edges to vertices
        IEdge *e1 = new FlowEdge(v1, v2, "e1", 3);
        IEdge *e2 = new FlowEdge(v1, v4, "e2", 2);
        IEdge *e3 = new FlowEdge(v1, v6, "e3", 1);
        //IEdge *e4 = new FlowEdge(v2, v1, "e4", 4);
        IEdge *e5 = new FlowEdge(v2, v5, "e5", 2);
        IEdge *e6 = new FlowEdge(v3, v2, "e6", 2);
        IEdge *e7 = new FlowEdge(v3, v5, "e7", 1);
        IEdge *e8 = new FlowEdge(v4, v5, "e8", 3);
        //IEdge *e9 = new FlowEdge(v5, v4, "e9", 2);
        IEdge *e10 = new FlowEdge(v6, v4, "e10", 6);
        IEdge *e11 = new FlowEdge(v6, v7, "e11", 5);
        IEdge *e12 = new FlowEdge(v7, v1, "e12", 4);

        vector<Vertex*> vertices = {v1, v2, v3, v4, v5, v6, v7};
        vector<IEdge*> edges = {e1, e2, e3, e5, e6, e7, e8, e10, e11, e12};

        // Create the graph structure with those vertices and edges
        _G = new FlowGraph(vertices, edges);

        assert(_G->isSimple() == 1);
        assert(_G->isNegativeWeighted() == 0);
        assert(_G->isPlanar() == 0);
        assert(_G->V() == 7);
        assert(_G->E() == 10);

        cout << "Avant ponderation :" << endl;
        cout << *_G << endl;
        _G->ponderateVertices(3.24);
        cout << "Apres ponderation : " << endl;
        cout << *_G << endl;

        // Test createEdge
        cout << "Create edge" << endl;
        IEdge *edge = _G->createEdge(new Vertex, new Vertex);
        cout << *edge << endl << endl;

        // Test clone()
        cout << "Test clone de g1" << endl;
        IGraph *g1Clone = _G->clone();
        g1Clone->ponderateVertices(42.36);
        g1Clone->ponderateEdges(-10);
        Vertex *va = new Vertex("va");
        Vertex *vb = new Vertex("vb");
        g1Clone->addVertex(va);
        g1Clone->addVertex(vb);
        g1Clone->addEdge(new FlowEdge(va, vb));
        assert(_G->V() != g1Clone->V());
        cout << *g1Clone << endl;

        // Test CopyToGraph
        cout << "Test CopyToGraph(&diGraph) and ponderate it" << endl;
        IGraph *gCpyToGraph = GraphAlgorithm::copyToGraph(_G);
        gCpyToGraph->ponderateVertices(6.7);
        gCpyToGraph->print();

        // Test CopyToDiGraph
        cout << "Test CopyToDiGraph(_G) and ponderate vertex" << endl;
        IGraph *gCpyToDiGraph = GraphAlgorithm::copyToDiGraph(_G);
        gCpyToDiGraph->ponderateVertices(5.5);
        gCpyToDiGraph->print();

        // Test CopyToFlowGraph
        cout << "Test CopyToFlowGraph(_G) and ponderate vertex" << endl;
        IGraph *gCpyToFlowGraph = GraphAlgorithm::copyToFlowGraph(_G);
        gCpyToFlowGraph->ponderateVertices(9.99);
        gCpyToFlowGraph->print();

        // Ré-afficher g1
        cout << "_G" << endl;
        cout << *_G << endl;

        // ALGOS NOT WORKING YET WITH FLOWGRAPH
        // Test BFS
        cout << "Test BFS" << endl;
        vector<double> distances;
        IGraph *gBFS = GraphAlgorithm::bfs(_G, v1, distances);
        gBFS->print();

        // Test DFS
        cout << "Test DFS" << endl;
        vector<double> dfsnum;
        IGraph *gDFS = GraphAlgorithm::dfs(_G, v1, dfsnum);
        gDFS->print();

        // Test Composantes fortement Connexes
        cout << "Test Composantes fortement connexes" << endl;
        vector<double> scc = GraphAlgorithm::stronglyConnectedComponent(_G);
        for (double d : scc)
            cout << d << " ";
        cout << endl << endl;
//
//        // Test Kruskal
//        cout << "Kruskal" << endl;
//        IGraph *gKruskal = GraphAlgorithm::kruskal(_G);
//        gKruskal->print();
//
//        // Test Prim
//        cout << "Prim" << endl;
//        IGraph *gPrim = GraphAlgorithm::kruskal(_G);
//        gPrim->print();

        // Test Bellman-Ford
        cout << "Bellman-Ford" << endl;
        vector<double> distancesBF;
        IGraph *gBellmanFord = GraphAlgorithm::bellmanFord(_G, v1, distancesBF);
        cout << *gBellmanFord << endl;
        for (double d : distancesBF) {
            cout << d << " ";
        }
        cout << endl;
    }

    ~RTestFlowGraph() { delete _G; }
};

#endif //GRAPH_TESTFLOWGRAPH_H
