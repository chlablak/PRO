//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DIEDGE_H
#define SRC_DIEDGE_H

#include "Edge.h"


class DiEdge : public Edge {

public :

    DiEdge(const Vertex* from, const Vertex* to, const int id) : Edge(from, to, id) {}
    DiEdge(const Vertex* from, const Vertex* to, const int id, const string& label) : Edge(from, to, id, label)  { }
    DiEdge(const Vertex* from, const Vertex* to, const int id, const double& weight) : Edge(from, to, id, weight) { }
    DiEdge(const Vertex* from, const Vertex* to, const int id, const double& weight, const string label) : Edge(from, to, id, weight, label){ }
    DiEdge(const Vertex* from, const Vertex* to, const int id, const string& label, const double& weight , const size_t minCap, const size_t maxCap)
           : Edge(from, to, id, label, weight, minCap, maxCap) { }
    ~DiEdge(){
        deleteItem();
    };

    const Vertex *from();
    const Vertex *to();




};


#endif //SRC_DIEDGE_H
