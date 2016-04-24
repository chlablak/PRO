//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include "GraphCommon.h"

class Graph : public GraphCommon {

public:
    Graph(const vector<Vertex>& vertices, const vector<Edge>& edges)
            : GraphCommon(vertices, edges) { }

    bool isSimple() const;
    bool isConnected() const;
    bool isStronglyConnected() const;
    bool isDirected() const;
};


#endif //GRAPH_GRAPH_H
