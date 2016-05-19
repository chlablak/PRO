#include <iostream>

#include "includes.h"

#include <cassert>

using namespace std;

int main() {

    // Create vertices
    Vertex *v1 = new Vertex("v1");
    Vertex *v2 = new Vertex("v2");
    Vertex *v3 = new Vertex("v3");
    Vertex *v4 = new Vertex("v4");

    // Associate Edges to vertices
    IEdge *e1 = new Edge(v1, v4, "e1", 3);
    IEdge *e2 = new Edge(v1, v3, "e2", 2);
    IEdge *e3 = new Edge(v2, v3, "e3", 1);
    IEdge *e4 = new Edge(v3, v4, "e4", 4);
    IEdge *e5 = new Edge(v1, v2, "e5", 3);
    IEdge *e6 = new Edge(v2, v4, "e6", 2);

    vector<Vertex*> vertices = {v1, v2, v3, v4};
    vector<IEdge*> edges = {e1, e2, e3, e4, e5, e6};

    // Create the graph structure with those vertices and edges
    Graph g1(vertices, edges);

    assert(g1.isSimple() == 1);
    assert(g1.isNegativeWeighted() == 0);
    assert(g1.isPlanar() == 1);
    assert(g1.V() == 4);

    cout << "Avant ponderation :" << endl;
    cout << g1 << endl;

    g1.ponderateVertices(3.24);
    cout << "Apres ponderation : " << endl;
    cout << g1 << endl;

    assert(g1.E() == 6);
    assert(e1 <= e2);
    assert(g1.isNegativeWeighted() == 0);

    // Test clone()
    IGraph *g1Clone = g1.clone();
    g1Clone->ponderateVertices(42.36);
    g1Clone->ponderateEdges(-10);
    Vertex *va = new Vertex("va");
    Vertex *vb = new Vertex("vb");
    g1Clone->addVertex(va);
    g1Clone->addVertex(vb);
    g1Clone->addEdge(new Edge(va, vb));
    assert(g1.V() != g1Clone->V());

    g1Clone->print();
    cout << g1 << endl;

    // Test BFS
    cout << "Test BFS" << endl;
    vector<int> distances;
    IGraph *gBFS = GraphAlgorithm::bfs(&g1, v1, distances);
    gBFS->print();

    // Test DFS
    cout << "Test DFS" << endl;
    vector<int> dfsnum;
    IGraph *gDFS = GraphAlgorithm::dfs(&g1, v1, dfsnum);
    gDFS->print();

    // Test Composantes Connexes
    cout << "Test Composante connexe" << endl;
    vector<int> cc = GraphAlgorithm::connectedComponent(&g1);
    for (int i : cc)
        cout << i << " ";
    cout << endl << endl;

    // Test Kruskal
    cout << "Kruskal" << endl;
    IGraph *gKruskal = GraphAlgorithm::kruskal(&g1);
    gKruskal->print();

    // Test Prim
    cout << "Prim" << endl;
    IGraph *gPrim = GraphAlgorithm::kruskal(&g1);
    gPrim->print();


    return 0;
}