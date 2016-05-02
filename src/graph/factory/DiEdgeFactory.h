////
//// Created by PatrickDesle on 01.05.2016.
////
//
//#ifndef GRAPH_DIEDGEFACTORY_H
//#define GRAPH_DIEDGEFACTORY_H
//
//
//#include "EdgeFactory.h"
//#include "../graphs/DiEdge.h"
//
//class DiEdgeFactory {
//
//private:
//    static EdgeFactory* instance;
//    DiEdgeFactory() { }
//public:
//    ~DiEdgeFactory(){ delete instance;}
//
//    static DiEdgeFactory& getInstance();
//
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const double& weight) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const string& label ) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const double& weight, const string& label) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const double& weight, const int maxCapacity) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity, const int minCapacity) const;
//    DiEdge* createDiEdge(const Vertex &v1, const Vertex &v2, const double& weight, const string& label, const int maxCapacity, const int minCapacity) const;
//
//
//};
//
//
//#endif //GRAPH_DIEDGEFACTORY_H
