#include <iostream>
#include "factory/VertexFactory.h"
#include "factory/EdgeFactory.h"
#include "graphs/Graph.h"

using namespace std;

int main() {

    // Create vertices
    Vertex v1;
    Vertex v2;
    Vertex v3;

    // Associate Edges to vertices
    Edge e1(v1, v2);
    Edge e2(v2, v3);
    Edge e3(v3, v2, -2.3);

    // Create the graph structure with those vertices and edges
    //Graph g1(vertices, edges);
    Graph g1({v1,v2,v3},{e1,e2,e3});

    cout << "is empty ? " << g1.isEmpty() << endl;
    cout << "is negative weighted ? " << g1.isNegativeWeighted() << endl;
    cout << "is planar ? " << g1.isPlanar() << endl;
    cout << "number of vertex : " << g1.V() << endl;

    return 0;
}