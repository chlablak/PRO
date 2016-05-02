//
// Created by PatrickDesle on 01.05.2016.
//

#ifndef GRAPH_DIEDGEFACTORY_H
#define GRAPH_DIEDGEFACTORY_H


#include "../graphs/Vertex.h"
#include "../graphs/IGraph.h"
#include "EdgeFactory.h"

class DiEdgeFactory : public EdgeFactory {

    DiEdgeFactory() {};
private:
public:
    static void initInstance() {new DiEdgeFactory;};

    ~DiEdgeFactory(){ delete EdgeFactory::instance;}

    static EdgeFactory& getInstance();
    static void initInstance();

    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const string& _label ) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const string& _label) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const size_t& _maxCapacity) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const size_t& _maxCapacity) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const size_t& _maxCapacity, const size_t& _minCapacity) const;
    DiEdge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const string& _label, const size_t& _maxCapacity, const size_t& _minCapacity) const;


};


#endif //GRAPH_DIEDGEFACTORY_H
