#include <iostream>

#include "includes.h"
#include "algorithms/DFS.h"

#include <cassert>

using namespace std;

int main() {

    // Create vertices
    Vertex *v1 = new Vertex("v1");
    Vertex *v2 = new Vertex("v2");
    Vertex *v3 = new Vertex("v3");
    Vertex *v4 = new Vertex("v4");

    // Associate Edges to vertices
    Edge *e1 = new Edge(v1, v1, "e1");
    Edge *e2 = new Edge(v1, v3, "e2");
    Edge *e3 = new Edge(v2, v3, "e3");
    Edge *e4 = new Edge(v3, v4, "e4");
    Edge *e5 = new Edge(v1, v2, "e5");
    Edge *e6 = new Edge(v2, v4, "e6");

    vector<Vertex*> vertices = {v1, v2, v3, v4};
    vector<Edge*> edges = {e1, e2, e3, e4, e5, e6};

    // Create the graph structure with those vertices and edges
    Graph g1(vertices, edges);

    assert(g1.isSimple() == 0);
    assert(g1.isNegativeWeighted() == 0);
    assert(g1.isPlanar() == 0);
    assert(g1.V() == 4);

    cout << "Avant ponderation :" << endl;
    cout << g1 << endl;

    g1.ponderateEdges(-5.1);
    g1.ponderateVertices(3.24);
    cout << "Apres ponderation : " << endl;
    cout << g1 << endl;

    assert(g1.E() == 6);
    assert(e1 <= e2);
    assert(g1.isNegativeWeighted() == 1);

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
    IGraph *gBFS = GraphAlgorithm::bfs(&g1, v1, &distances);
    gBFS->print();

    // Test DFS
    cout << "Test DFS" << endl;
    Visitor *dfs = new DFS;
    g1.accept(dfs, v1);
    IGraph *gDFS = dfs->G();
    gDFS->print();

    return 0;
}