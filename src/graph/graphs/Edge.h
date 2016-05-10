//
// Created by sebri on 24.04.2016.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>
#include <iostream>
#include "Vertex.h"
#include "CommonEdge.h"

using namespace std;

class Edge : public CommonEdge{

protected:
    Edge() {}

   // void deleteItem();

public:
    // Constructors

    Edge(Vertex &from, Vertex &to)
            : CommonEdge(from, to) { }

    Edge(Vertex &from, Vertex &to,
         const string &label)
            : CommonEdge(from, to, label){ }

    Edge(const Edge& e){
        _id = e._id;
        _a = new Vertex(*e._a);
        _b = new Vertex(*e._b);
        _label = e._label;

    }

    // Getters

    Vertex* either() const;

    Vertex* other(Vertex &v) const;

    virtual ~Edge() {}

    friend ostream& operator<<(ostream& os, const Edge& e);
    /*template <typename T>
    friend class IGraph;*/
};


#endif //GRAPH_EDGE_H
