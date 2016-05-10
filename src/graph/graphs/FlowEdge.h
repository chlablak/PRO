//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_FLOWEDGE_H
#define GRAPH_FLOWEDGE_H

#include "DiEdge.h"

class FlowEdge : public DiEdge{

private :
    int _minCapacity;
    int _maxCapacity;

public:
    // Constructors

    FlowEdge(Vertex &from, Vertex &to, const int &minCapacity);
    /*FlowEdge(Vertex &from, Vertex &to, const int &minCapacity)
            : DiEdge(from, to), _minCapacity(minCapacity), _maxCapacity(-1) { }

    FlowEdge(Vertex &from, Vertex &to, const int &maxCapacity)
            : DiEdge(from, to), _minCapacity(-1), _maxCapacity(maxCapacity) { }*/

   /* FlowEdge(Vertex &from, Vertex &to, const string &label, const int &minCapacity)
            : DiEdge(from, to, label), _minCapacity(minCapacity), _maxCapacity(-1) { }

    FlowEdge(Vertex &from, Vertex &to, const string &label, const int &maxCapacity)
            : DiEdge(from, to, label), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex &from, Vertex &to, const string &label, const int &minCapacity, const int &maxCapacity)
            : DiEdge(from, to, label), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }*/

    FlowEdge(const FlowEdge& e){
        _id = e._id;
        _a = new Vertex(*e._a);
        _b = new Vertex(*e._b);
        _label = e._label;
        _minCapacity = e._minCapacity;
        _maxCapacity = e._maxCapacity;
    }


    // Getters
    int minCapacity() const;

    int maxCapacity() const;

    // Setters

    void setMinCapacity(const int &m);
    void setMaxCapacity(const int &m);
};


#endif //GRAPH_FLOWEDGE_H
