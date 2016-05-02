//
// Created by sebri on 24.04.2016.
//

#include <exception>
#include "EdgeFactory.h"



EdgeFactory* EdgeFactory::instance = 0;
EdgeFactory::EdgeFactory() {
    if(instance)
        throw "ERROR : instance already exist";
    instance =  this;
}

void EdgeFactory::initInstance() { new EdgeFactory(); }

EdgeFactory& EdgeFactory::getInstance() {
     if(!instance)
         initInstance();
    return *instance;
}


Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2) const {
    return new Edge(graph->edgeId(), _v1, _v2);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex *_v1, const Vertex *_v2, const double &_weight) const {
    return new Edge(graph->edgeId(), _v1, _v2, _weight);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex *_v1, const Vertex *_v2, const string &_label) const{
    return new Edge(graph->edgeId(), _v1, _v2,_label);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const size_t &_maxCapacity) const {
    return new Edge(graph->edgeId(), _v1, _v2, _maxCapacity);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new Edge(graph->edgeId(), _v1, _v2,_maxCapacity, _minCapacity);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const std::string &_label) const {
    return new Edge(graph->edgeId(), _v1, _v2,_weight,_label);
}
Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const size_t &_maxCapacity) const {
    return new Edge(graph->edgeId(), _v1, _v2,_weight, _maxCapacity);
}

Edge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const std::string &_label,
                                    const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new Edge(graph->edgeId(), _v1, _v2,_weight, _label, _maxCapacity, _minCapacity);
}
