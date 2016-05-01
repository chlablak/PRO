//
// Created by PatrickDesle on 01.05.2016.
//

#include "DiEdgeFactory.h"

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2) const {
    return new DiEdge(graph->edgeId(), _v1, _v2);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex *_v1, const Vertex *_v2, const double &_weight) const {
    return new DiEdge(graph->edgeId(), _v1, _v2, _weight);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex *_v1, const Vertex *_v2, const string &_label) const{
    return new DiEdge(graph->edgeId(), _v1, _v2,_label);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const size_t &_maxCapacity) const {
    return new DiEdge(graph->edgeId(), _v1, _v2, _maxCapacity);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new DiEdge(graph->getEdgeId(), _v1, _v2,_maxCapacity, _minCapacity);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const std::string &_label) const {
    return new DiEdge(graph->edgeId(), _v1, _v2,_weight,_label);
}
DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const size_t &_maxCapacity) const {
    return new DiEdge(graph->edgeId(), _v1, _v2,_weight, _maxCapacity);
}

DiEdge* EdgeFactory::createEdge(IGraph *graph, const Vertex* _v1, const Vertex *_v2, const double &_weight, const std::string &_label,
                              const size_t &_maxCapacity, const size_t &_minCapacity) const {
    return new DiEdge(graph->edgeId(), _v1, _v2,_weight, _label, _maxCapacity, _minCapacity);
}

