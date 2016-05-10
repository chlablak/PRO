//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "Edge.h"

class DiEdge : public CommonEdge {
protected:
    DiEdge() {}

public:
    // Constructors
    DiEdge(Vertex &from, Vertex &to)
            : CommonEdge(from, to) { }

    DiEdge(Vertex &from, Vertex &to,
           const string &label)
            : CommonEdge(from, to, label) { }

    DiEdge(const DiEdge& e){
        _id = e._id;
        _a = new Vertex(*e._a);
        _b = new Vertex(*e._b);
        _label = e._label;
    }

    virtual ~DiEdge() {}

    // Getters
    Vertex *from();
    Vertex *to();
};


#endif //SRC_DiEdge_H
