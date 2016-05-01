//
// Created by sebri on 24.04.2016.
//

#include "VertexFactory.h"

VertexFactory* VertexFactory::instance = nullptr;

VertexFactory& VertexFactory::getInstance() {
    if(instance == nullptr)
        instance = new VertexFactory();
    return *instance;
}

Vertex* VertexFactory::createVertex(IGraph *graph) const {
    return new Vertex(graph->vertexId());
}

Vertex* VertexFactory::createVertex(IGraph *graph, const double &_weight) const {
    return new Vertex(graph->vertexId(), _weight);
}

Vertex* VertexFactory::createVertex(IGraph *graph, const std::string &_label) const {
    graph->vertexId(), _label;
}

Vertex* VertexFactory::createVertex(IGraph *graph, const size_t &_maxCapacity) const {
    return new Vertex(graph->vertexId(), _maxCapacity);
}

Vertex* VertexFactory::createVertex(IGraph *graph, const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new Vertex(graph->vertexId(), _maxCapacity, _minCapacity);
}

Vertex* VertexFactory::createVertex(IGraph *graph, const double &_weight, const std::string &_label) const {
    return new Vertex(graph->vertexId(), _weight,_label);
}
Vertex* VertexFactory::createVertex(IGraph *graph, const double &_weight, const size_t &_maxCapacity) const {
    return new Vertex(graph->vertexId(), _weight, _maxCapacity);
}

Vertex* VertexFactory::createVertex(IGraph *graph, const double &_weight, const std::string &_label,
                                    const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new Vertex(graph->vertexId(), _weight, _label, _maxCapacity, _minCapacity);
}