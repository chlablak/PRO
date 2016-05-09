////
//// Created by sebri on 24.04.2016.
////
//
//#ifndef GRAPHEDGEFACTORYH
//#define GRAPHEDGEFACTORYH
//
//#include <iostream>
//#include "../graphs/Edge.h"
//#include "../graphs/IGraph.h"
//
//
//using namespace std;
//
//class EdgeFactory {
//    EdgeFactory();
//private:
//    static EdgeFactory* instance;
//public:
//
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const double& weight) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const string& label ) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const double& weight, const string& label) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const double& weight, const int maxCapacity) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const int maxCapacity, const int minCapacity) const;
//    virtual Edge* createEdge(const Vertex &v1, const Vertex &v2, const double& weight, const string& label, const int maxCapacity, const int minCapacity) const;
//
//    static EdgeFactory& getInstance();
//    static void initInstance();
//};
//
//
//#endif //GRAPHEDGEFACTORYH
