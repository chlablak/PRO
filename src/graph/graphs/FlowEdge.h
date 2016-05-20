//
// Created by PatrickDesle on 10.05.2016.
//

#ifndef GRAPH_FLOWEDGE_H
#define GRAPH_FLOWEDGE_H

#include "DiEdgeCommon.h"

class FlowEdge : public DiEdgeCommon{

private :
    int _minCapacity;
    int _maxCapacity;

public:
    // Constructors
    FlowEdge(Vertex *from, Vertex *to) : DiEdgeCommon(from, to) { }

    FlowEdge(Vertex *from, Vertex *to, const string& label)
            : DiEdgeCommon(from, to, label) { }

    FlowEdge(Vertex *from, Vertex *to, const double weight)
            : DiEdgeCommon(from, to, weight) { }

    FlowEdge(Vertex *from, Vertex *to, const int maxCapacity)
            : DiEdgeCommon(from, to), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &maxCapacity)
            : DiEdgeCommon(from, to, label), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(-1), _maxCapacity(-1) { }

    FlowEdge(Vertex *from, Vertex *to, const double weight ,const int &maxCapacity)
            : DiEdgeCommon(from, to, weight), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &maxCapacity)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(-1), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const int &minCapacity, const int &maxCapacity)
            : DiEdgeCommon(from, to), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &minCapacity, const int &maxCapacity)
            : DiEdgeCommon(from, to, label), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const double weight, const int &minCapacity, const int &maxCapacity)
            : DiEdgeCommon(from, to, weight), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &minCapacity, const int &maxCapacity)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(minCapacity), _maxCapacity(maxCapacity) { }

    FlowEdge(const FlowEdge& e);

    // Getters
    int minCapacity() const;
    int maxCapacity() const;

    // Setters
    void setMinCapacity(const int m);
    void setMaxCapacity(const int m);
};


#endif //GRAPH_FLOWEDGE_H
