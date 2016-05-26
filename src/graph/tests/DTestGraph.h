//
// Created by sebri on 20.05.2016.
//

#ifndef GRAPH_TESTGRAPH_H
#define GRAPH_TESTGRAPH_H

#include <cassert>
#include "../includes.h"

class DTestGraph
{
private:
    IGraph *_G;
public:
    DTestGraph() : _G(nullptr) {
        // Create vertices
        Vertex *v1 = new Vertex("v1");
        Vertex *v2 = new Vertex("v2");
        Vertex *v3 = new Vertex("v3");
        Vertex *v4 = new Vertex("v4");
        Vertex *v5 = new Vertex("v5");
        //Vertex *v6 = new Vertex("v6");
        //Vertex *v7 = new Vertex("v7");

        // Associate Edges to vertices
        IEdge *e1 = new Edge(v2, v4, "e1", 3);
        IEdge *e2 = new Edge(v1, v3, "e2", 2);
        IEdge *e3 = new Edge(v2, v1, "e3", 1);
        IEdge *e4 = new Edge(v4, v5, "e4", 4);
        IEdge *e5 = new Edge(v3, v4, "e5", 3);
        //IEdge *e6 = new Edge(v3, v2, "e6", 2);
        //IEdge *e7 = new Edge(v3, v5, "e7", 1);
        //IEdge *e8 = new Edge(v4, v5, "e8", 3);
        //IEdge *e9 = new Edge(v5, v4, "e9", 2);
        //IEdge *e10 = new Edge(v6, v4, "e10", 6);
        //IEdge *e11 = new Edge(v6, v7, "e11", 5);
        //IEdge *e12 = new Edge(v7, v1, "e12", 4);

        vector<Vertex*> vertices = {v1, v2, v3, v4, v5};
        vector<IEdge*> edges = {e1, e2, e3, e4, e5};

        // Create the graph structure with those vertices and edges
        _G = new Graph(vertices, edges);
        assert(_G->isSimple() == 1);
        assert(_G->isNegativeWeighted() == 0);
        assert(_G->isPlanar() == 1);
        assert(_G->V() == 5);

//        vector<Vertex *> vv;
//        for (Vertex *v : _G->vertexList()) {
//            vv.push_back(v);
//        }
//        for (size_t i = 0; i < vv.size(); ++i) {
//            for (size_t j = 0; j < vv.size(); ++j) {
//                for (IEdge *ie : _G->getEdges(vv[i], vv[j])) {
//                    cout << *vv[i] << endl;
//                    cout << *vv[j] << endl;
//                    if (ie)
//                        cout << *ie << endl;
//                }
//                cout << endl;
//            }
//        }

        // Test Detect Cycle
        cout << "Test Detect cycle" << endl;
        IGraph *gDetectCycle = GraphAlgorithm::detectCycle(_G);
        if (gDetectCycle != nullptr) {
            cout << "cycle trouvee " << endl;
            cout << *gDetectCycle << endl;
        }

           /* _G->ponderateVertices(7);
            cout << *gDetectCycle << endl;*/

        /*cout << "Avant ponderation :" << endl;
        cout << *_G << endl;
        _G->ponderateVertices(3.24);
        cout << "Apres ponderation : " << endl;
        cout << *_G << endl;

        // Test createEdge
        IEdge *gg = _G->createEdge(new Vertex, new Vertex);
        cout << *gg << endl;

        // Test clone()
        cout << "Test clone de g1" << endl;
        IGraph *g1Clone = _G->clone();
        g1Clone->ponderateVertices(42.36);
        g1Clone->ponderateEdges(-10);
        Vertex *va = new Vertex("va");
        Vertex *vb = new Vertex("vb");
        g1Clone->addVertex(va);
        g1Clone->addVertex(vb);
        g1Clone->addEdge(new Edge(va, vb));
        assert(_G->V() != g1Clone->V());
        g1Clone->print();

        // Test CopyToGraph
        cout << "Test CopyToGraph and ponderate it" << endl;
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

        // Test BFS
        cout << "Test BFS" << endl;
        vector<int> distances;
        IGraph *gBFS = GraphAlgorithm::bfs(_G, v1, distances);
        gBFS->ponderateEdges(50);
        gBFS->print();

        // Test DFS
        cout << "Test DFS" << endl;
        vector<int> dfsnum;
        IGraph *gDFS = GraphAlgorithm::dfs(_G, v1, dfsnum);
        gDFS->print();

        // Test Composantes Connexes
        cout << "Test Composante connexe" << endl;
        vector<int> cc = GraphAlgorithm::connectedComponent(_G);
        for (int i : cc)
            cout << i << " ";
        cout << endl << endl;

        // Test Kruskal
        cout << "Kruskal" << endl;
        IGraph *gKruskal = GraphAlgorithm::kruskal(_G);
        gKruskal->print();

        // Test Prim
        cout << "Prim" << endl;
        IGraph *gPrim = GraphAlgorithm::prim(_G, v1);
        gPrim->print();*/
    }

    ~DTestGraph() { delete _G; }
};

#endif //GRAPH_TESTGRAPH_H
