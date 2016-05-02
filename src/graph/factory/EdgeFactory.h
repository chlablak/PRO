//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGEFACTORY_H
#define GRAPH_EDGEFACTORY_H

#include <iostream>
#include "../graphs/Edge.h"
#include "../graphs/IGraph.h"


using namespace std;

class EdgeFactory {
    EdgeFactory();
private:
    static EdgeFactory* instance;
public:

    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const string& _label ) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const string& _label) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const size_t& _maxCapacity) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const size_t& _maxCapacity) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const size_t& _maxCapacity, const size_t& _minCapacity) const;
    virtual Edge* createEdge(IGraph* graph, const Vertex* _v1, const Vertex* _v2, const double& _weight, const string& _label, const size_t& _maxCapacity, const size_t& _minCapacity) const;

    static EdgeFactory& getInstance();
    static void initInstance();
};


#endif //GRAPH_EDGEFACTORY_H
