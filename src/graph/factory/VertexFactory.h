////
//// Created by sebri on 24.04.2016.
////
//
//#ifndef GRAPH_VERTEXFACTORY_H
//#define GRAPH_VERTEXFACTORY_H
//
//#include <iostream>
//#include "../graphs/Vertex.h"
//#include "../graphs/IGraph.h"
//#include "../../utility/Optional.h"
//
//using namespace std;
//
//class VertexFactory {
//private:
//    static VertexFactory* instance ;
//    VertexFactory() {}
//public:
//    Vertex& createVertex(const utility::Optional<double> weight,
//                         const utility::Optional<string> label,
//                         const utility::Optional<size_t> maxCapacity,
//                         const utility::Optional<size_t> minCapacity);
//
//    Vertex* createVertex() const ;
//    Vertex* createVertex(const double&  weight) const ;
//    Vertex* createVertex(const string& label) const;
//    Vertex* createVertex(const double&  weight, const string& label) const;
//    Vertex* createVertex(const int maxCapacity) const;
//    Vertex* createVertex(const int maxCapacity, const int  minCapacity) const;
//    Vertex* createVertex(const double& weight, const int  maxCapacity) const;
//    Vertex* createVertex(const double& weight, const string& label, const int maxCapacity, const int minCapacity) const;
//    static VertexFactory& getInstance();
//};
//
//
//#endif //GRAPH_VERTEXFACTORY_H
