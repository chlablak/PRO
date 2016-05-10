//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_WEIGHTEDEDGE_H
#define GRAPH_WEIGHTEDEDGE_H

#include "DiEdge.h"


class WeightedDiEdge : public DiEdge{
private:
    double _weight;
    // Constructors
    WeightedDiEdge(Vertex &from, Vertex &to, const double &weight)
    : DiEdge(from, to), _weight(weight){ }

    WeightedDiEdge(Vertex &from, Vertex &to, const string &label, const double &weight)
    : DiEdge(from, to, label), _weight(weight) { }

    WeightedDiEdge(const WeightedDiEdge& e){
        _id = e._id;
        _a = new Vertex(*e._a);
        _b = new Vertex(*e._b);
        _label = e._label;
        _weight = e._weight;
    }


public:

    double weight() const;
    void setWeight(const double& w);

    virtual ~WeightedDiEdge() {}


};


#endif //GRAPH_WEIGHTEDEDGE_H
