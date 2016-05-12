#include <iostream>
#include "graphs/Vertex.h"
#include "graphs/Edge.h"
#include "graphs/Graph.h"
#include "algorithms/BFS.h"
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

    vector<Vertex*> vertices = {v1, v2, v3};
    vector<Edge*> edges = {e1, e2, e3};

    // Create the graph structure with those vertices and edges
    //Graph g3(vertices);
    Graph g1(vertices, edges);

    assert(g1.isSimple() == 0);
    assert(g1.isNegativeWeighted() == 0);
    assert(g1.isPlanar() == 0);
    assert(g1.V() == 3);


    cout << "Avant ponderation :" << endl;
    cout << g1 << endl;

    g1.ponderateEdges(-5.1);
    g1.ponderateVertices(3.24);
    g1.ponderateCapacity(0, 3);
    g1.addVertex(v4);
    g1.addEdge(e4);
    cout << "Apres ponderation : " << endl;
    cout << g1 << endl;

    assert(g1.E() == 4);
    assert(g1.V() == 4);
    assert(e1 <= e2);
    assert(g1.isNegativeWeighted() == 1);

    // Test clone()
    Graph *g1Clone = g1.clone();
    g1Clone->ponderateVertices(42.36);
    g1Clone->ponderateEdges(-10);
    g1Clone->addVertex(new Vertex);
    assert(g1.V() != g1Clone->V());

    cout << *g1Clone << endl;
    cout << g1 << endl;


    // Test BFS
    cout << endl << "Test BFS" << endl;
    Visitor *bfs = new BFS;
    Graph *bfsG1 = g1.accept(bfs, v3);
    cout << *bfsG1 << endl;


    return 0;
}