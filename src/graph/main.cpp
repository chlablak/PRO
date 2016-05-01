#include <iostream>
#include "factory/VertexFactory.h"
#include "factory/EdgeFactory.h"

using namespace std;

int main() {

    VertexFactory vertexFactory = VertexFactory::getInstance();
    //Vertex * v1 =  vertexFactory.createVertex(new Graph);
    //Vertex * v2 =  vertexFactory.createVertex(new Graph, 45);

    EdgeFactory  edgeFactory =  EdgeFactory::getInstance();

    return 0;
}