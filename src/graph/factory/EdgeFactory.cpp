////
//// Created by sebri on 24.04.2016.
////
//
//#include <exception>
//#include "EdgeFactory.h"
//
//
//
//EdgeFactory* EdgeFactory::instance = 0;
//EdgeFactory::EdgeFactory() {
//    if(instance)
//        throw "ERROR : instance already exist";
//    instance =  this;
//}
//
//void EdgeFactory::initInstance() { new EdgeFactory(); }
//
//EdgeFactory& EdgeFactory::getInstance() {
//     if(!instance)
//         initInstance();
//    return *instance;
//}
//
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2) const {
//    return new Edge(v1, v2);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const double &_weight) const {
//    return new Edge(v1, v2, _weight);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const string &label) const{
//    return new Edge(v1, v2, label);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity) const {
//    return new Edge(v1, v2, maxCapacity);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity, const int minCapacity) const {
//    return new Edge(v1, v2, maxCapacity, minCapacity);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const double &_weight, const string &label) const {
//    return new Edge(v1, v2,_weight,label);
//}
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const double &_weight, const int maxCapacity) const {
//    return new Edge(v1, v2,_weight, maxCapacity);
//}
//
//Edge* EdgeFactory::createEdge(const Vertex &v1, const Vertex &v2, const double &_weight, const string &label,
//                                    const int maxCapacity, const int minCapacity) const {
//    return new Edge(v1, v2,_weight, label, maxCapacity, minCapacity);
//}
