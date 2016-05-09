#include <iostream>
#include "factory/VertexFactory.h"
#include "factory/EdgeFactory.h"
#include "graphs/Graph.h"
#include <list>
#include <vector>

using namespace std;

int main() {

    // Create vertices
    Vertex v1("0");
    Vertex v2("1");
    Vertex v3("2");

    // Associate Edges to vertices
    Edge e1(v1, v1, "e0");
    Edge e2(v1, v3, "e1");
    Edge e3(v2, v3, 2.3, "e2");

    cout << v3 << endl;
  //  cout << v4 <<endl;

    cout << e3 << endl;
    //cout << e4 <<endl;

    // Create the graph structure with those vertices and edges
    //Graph g1(vertices, edges);
    Graph g1({v1,v2,v3}, {e1, e2, e3});
    Graph g2({v1,v2,v3});

    cout << "is empty ? " << g2.isEmpty() << endl;
    cout << "is simple ? " << g1.isSimple() << endl;
    cout << "is negative weighted ? " << g1.isNegativeWeighted() << endl;
    cout << "is planar ? " << g1.isPlanar() << endl;
    cout << "number of vertex : " << g1.V() << endl;

    list<Edge*> edges = g1.edgeList();
    list<Vertex*> vertices = g1.vertexList();

    for(Edge* e : edges)
        cout << *e << endl;
    for(Vertex* v : vertices)
        cout << *v << endl;
    cout << "ponderate the edge and vertex with 5.1" << endl;
    g1.ponderateEdges(3.5);
    g1.pondeateVertices(5.1);

    edges = g1.edgeList();
    vertices = g1.vertexList();

    for(Edge* e : edges)
        cout << *e << endl;
    for(Vertex* v : vertices)
        cout << *v << endl;

    Vertex v4("3");
    Vertex v5("4");
    Vertex v6("5");


    cout << "add the edge e4(v4, v5, e3 )) to the graph" << endl;
    Edge e4(v4, v5, "e3");
    g1.addVertex(v4);
    g1.addVertex(v5);
    g1.addVertex(v6);
    g1.addEdge(e4);


    edges = g1.edgeList();
    vertices = g1.vertexList();
    Edge& tmpEdge = *edges.back();
    for(Edge* e : edges)
        cout << *e << endl;
    for(Vertex* v : vertices)
        cout << *v << endl;


    cout << "remove the edge e4 from the graph" << endl;
    g1.removeEdge(tmpEdge);
    //g1.removeVertex(v6);

    edges = g1.edgeList();
    vertices = g1.vertexList();

    for(Edge* e : edges)
        cout << *e << endl;
    for(Vertex* v : vertices)
        cout << *v << endl;



    return 0;
}