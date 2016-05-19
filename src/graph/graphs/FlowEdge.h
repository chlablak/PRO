//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_FLOWEDGE_H
#define GRAPH_FLOWEDGE_H

#include "DiEdge.h"

// TODO supprimer après avoir implémenté
class FlowEdge : public DiEdge{

private :
    int _minCapacity;
    int _maxCapacity;

public:
    // Constructors
    FlowEdge(Vertex *from, Vertex *to, const int &maxCapacity)
            : DiEdge(from, to), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &maxCapacity)
            : DiEdge(from, to, label), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &minCapacity, const int &maxCapacity)
            : DiEdge(from, to, label), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }

//    FlowEdge(const FlowEdge& e);

    // Getters
    int minCapacity() const;

    int maxCapacity() const;

    // Setters

    void setMinCapacity(const int &m);
    void setMaxCapacity(const int &m);
};


#endif //GRAPH_FLOWEDGE_H
