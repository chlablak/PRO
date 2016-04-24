//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEXFACTORY_H
#define GRAPH_VERTEXFACTORY_H

#include <iostream>
#include "../graphs/Vertex.h"

using namespace std;

class VertexFactory {
private:
    static VertexFactory instance;
    VertexFactory();
public:
    VertexFactory getInstance();
    Vertex createVertex(const string* label = nullptr,
                        const double* weight = nullptr,
                        const size_t* minCapacity = nullptr,
                        const size_t* maxCapacity = nullptr);
};


#endif //GRAPH_VERTEXFACTORY_H
