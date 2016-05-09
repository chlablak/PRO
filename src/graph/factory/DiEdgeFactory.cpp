////
//// Created by PatrickDesle on 01.05.2016.
////
//
//#include "DiEdgeFactory.h"
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2) const {
//    return new DiEdge(v1, v2);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const double &weight) const {
//    return new DiEdge(v1, v2, weight);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const string &label) const{
//    return new DiEdge(v1, v2,label);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity) const {
//    return new DiEdge(v1, v2, maxCapacity);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity, const int minCapacity) const {
//    return new DiEdge(v1, v2,maxCapacity, minCapacity);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const double &weight, const string &label) const {
//    return new DiEdge(v1, v2,weight,label);
//}
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const double &weight, const int maxCapacity) const {
//    return new DiEdge(v1, v2,weight, maxCapacity);
//}
//
//DiEdge* DiEdgeFactory::createDiEdge(const Vertex &v1, const Vertex &v2, const double &weight, const string &label,
//                              const int maxCapacity, const int minCapacity) const {
//    return new DiEdge(v1, v2,weight, label, maxCapacity, minCapacity);
//}
//
