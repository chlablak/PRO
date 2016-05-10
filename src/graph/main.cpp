#include <iostream>
#include "factory/VertexFactory.h"
#include "factory/EdgeFactory.h"
#include "graphs/Edge.h"
#include "graphs/Vertex.h"
#include <list>
#include <vector>

using namespace std;

int main() {

    // Create vertices
    Vertex v1("0");
    Vertex v2("1");
    Vertex v3("2");

    // Associate Edges to vertices
    Edge e1(v1, v1);
    Edge e2(v1, v3, "e1");
    Edge e3(v2, v3, "e2");

    cout << v3 << endl;
  //  cout << v4 <<endl;

    cout << e3 << endl;
    //cout << e4 <<endl;



    // Create the graph structure with those vertices and edges
    //Graph g1(vertices, edges);


    //Graph<Edge> g1({v1,v2,v3},{e1,e2,e3});
    //cout << "is empty ? " << g2.isEmpty() << endl;
    //cout << "is simple ? " << g1.isSimple() << endl;
    //cout << "is negative weighted ? " << g1.isNegativeWeighted() << endl;
    //cout << "is planar ? " << g1.isPlanar() << endl;
    //cout << "number of vertex : " << g1.V() << endl;

//
//    // is null
//    Graph<Edge> g2;
//    cout << "g2 is null ? " << g2.isNull() << endl;
//    g2.addVertex(v1);
//    cout << "g2 is null ? " << g2.isNull() << endl;
//
//    // is empty
//    cout << "g2 is empty ? " << g2.isEmpty() << endl;
//    g2.addVertex(v2);
//    g2.addEdge(e1);
//    cout << "g2 is empty ? " << g2.isEmpty() << endl;
//
//    // is simple
//    cout << "g2 is simple ? " << g2.isSimple() << endl;
//    g2.addEdge(e1);
//    cout << "g2 is simple ? " << g2.isSimple() << endl;
//
//    // is negative weighted
//    cout << "g1 is negative weighted ? " << g1.isNegativeWeighted() << endl;
//
//    cout << "is planar ? " << g1.isPlanar() << endl;
//    cout << "number of vertex : " << g1.V() << endl;

    return 0;
}