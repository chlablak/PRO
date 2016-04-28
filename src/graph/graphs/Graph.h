//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include "GraphCommon.h"

class Graph : public GraphCommon
{

public:
    Graph(const vector<Vertex>& vertices, const vector<Edge>& edges)
            : GraphCommon::GraphCommon(vertices, edges)
    { }

    virtual bool isSimple() const;
    virtual bool isConnected() const;
    virtual bool isStronglyConnected() const;
    virtual bool isDirected() const;
    //virtual void accept(const Visitor& v);
};


#endif //GRAPH_GRAPH_H
