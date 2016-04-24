//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGEFACTORY_H
#define GRAPH_EDGEFACTORY_H

#include <iostream>
#include "../graphs/Edge.h"

using namespace std;

class EdgeFactory {
private:
    static EdgeFactory instance;
    EdgeFactory();
public:
    Edge createEdge(const Vertex& v1, const Vertex& v2,
                    const string* label = nullptr,
                    const double* weight = nullptr,
                    const size_t* minCapacity = nullptr,
                    const size_t* maxCapacity = nullptr);
};


#endif //GRAPH_EDGEFACTORY_H
