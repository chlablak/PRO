//
// Created by PatrickDesle on 26.04.2016.
//

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "Edge.h"

// TODO patrick
class DiEdge : public IEdge {
private:
    int _minCapacity;
    int _maxCapacity;

protected:
public:
    virtual Vertex *either() const override;

    virtual Vertex *other(Vertex *v) const override;

    DiEdge() {}

public:
    // Constructors
    DiEdge(Vertex *from, Vertex *to)
            : IEdge(from, to) { }

    DiEdge(Vertex *from, Vertex *to,
           const string &label)
            : IEdge(from, to, label) { }

    DiEdge(DiEdge *e);
    // TODO patrick : ajouter plus de constructeurs (aussi pour FlowEdge)

    virtual ~DiEdge() {}

    // Getters
    Vertex *from() const;
    Vertex *to() const;
};


#endif //SRC_DiEdge_H
