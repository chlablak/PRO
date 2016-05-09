////
//// Created by sebri on 24.04.2016.
////
//
//#include "VertexFactory.h"
//
//VertexFactory *VertexFactory::instance = nullptr;
//
//VertexFactory &VertexFactory::getInstance() {
//    if (instance == nullptr)
//        instance = new VertexFactory();
//    return *instance;
//}
//
//Vertex *VertexFactory::createVertex() const {
//    return new Vertex();
//}
//
//Vertex *VertexFactory::createVertex(const double &weight) const {
//    return new Vertex(weight);
//}
//
//Vertex *VertexFactory::createVertex(const string &label) const {
//    return new Vertex(label);
//}
//
//Vertex *VertexFactory::createVertex(const int maxCapacity) const {
//    return new Vertex(maxCapacity);
//}
//
//Vertex *VertexFactory::createVertex(const int maxCapacity,
//                                    const int minCapacity) const {
//    return new Vertex(maxCapacity, minCapacity);
//}
//
//Vertex *VertexFactory::createVertex(const double &weight,
//                                    const string &label) const {
//    return new Vertex(weight, label);
//}
//
//Vertex *VertexFactory::createVertex(const double &weight,
//                                    const int maxCapacity) const {
//    return new Vertex(weight, maxCapacity);
//}
//
//Vertex *VertexFactory::createVertex(const double &weight, const string &label,
//                                    const int maxCapacity,
//                                    const int minCapacity) const {
//    return new Vertex(weight, label, maxCapacity, minCapacity);
//}