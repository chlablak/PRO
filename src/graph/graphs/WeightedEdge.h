//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_WEIGHTEDEDGE_H
#define GRAPH_WEIGHTEDEDGE_H

#include "Edge.h"


class WeightedEdge : public Edge{
private:
    double _weight;
    // Constructors
    WeightedEdge(Vertex &from, Vertex &to, const double &weight)
    : Edge(from, to), _weight(weight) { }

    WeightedEdge(Vertex &from, Vertex &to,const string &label, const double &weight)
    : Edge(from, to, label), _weight(weight) { }

    WeightedEdge(const WeightedEdge& e){
        _id = e._id;
        _a = new Vertex(*e._a);
        _b = new Vertex(*e._b);
        _label = e._label;
        _weight = e._weight;
    }


public:

    double weight() const;
    void setWeight(const double& w);

    virtual ~WeightedEdge() {}


};


#endif //GRAPH_WEIGHTEDEDGE_H
