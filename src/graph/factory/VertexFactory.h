//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_VERTEXFACTORY_H
#define GRAPH_VERTEXFACTORY_H

#include <iostream>
#include "../graphs/Vertex.h"
#include "../graphs/IGraph.h"

using namespace std;

class VertexFactory {
private:
    static VertexFactory* instance ;
    VertexFactory() { };
public:
    Vertex* createVertex(IGraph* graph) const ;
    Vertex* createVertex(IGraph* graph, const double&  _weight) const ;
    Vertex* createVertex(IGraph* graph, const std::string& _label) const;
    Vertex* createVertex(IGraph* graph, const double&  _weight, const std::string& _label) const;
    Vertex* createVertex(IGraph* graph, const size_t&  _maxCapacity) const;
    Vertex* createVertex(IGraph* graph, const size_t&  _maxCapacity, const size_t&  _minCapacity) const;
    Vertex* createVertex(IGraph* graph, const double& _weight, const size_t&  _maxCapacity) const;
    Vertex* createVertex(IGraph* graph, const double& _weight, const std::string& _label, const size_t& _maxCapacity, const size_t& _minCapacity) const;
    static VertexFactory& getInstance();
};


#endif //GRAPH_VERTEXFACTORY_H
