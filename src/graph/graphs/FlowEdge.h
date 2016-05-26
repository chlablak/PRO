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

    void checkCapacity(const int minCapacity, const int maxCapacity);
public:
    // Constructors
    FlowEdge(Vertex *from, Vertex *to)
            : DiEdgeCommon(from, to), _minCapacity(-1), _maxCapacity(-1) { }

    FlowEdge(Vertex *from, Vertex *to, const string& label)
            : DiEdgeCommon(from, to, label), _minCapacity(-1), _maxCapacity(-1) { }

    FlowEdge(Vertex *from, Vertex *to, const double weight)
            : DiEdgeCommon(from, to, weight), _minCapacity(-1), _maxCapacity(-1) { }

    FlowEdge(Vertex *from, Vertex *to, const int maxCapacity)
            : DiEdgeCommon(from, to), _minCapacity(0), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &maxCapacity)
            : DiEdgeCommon(from, to, label), _minCapacity(0), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(-1), _maxCapacity(-1) { }

    FlowEdge(Vertex *from, Vertex *to, const double weight ,const int &maxCapacity)
            : DiEdgeCommon(from, to, weight), _minCapacity(0), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &maxCapacity)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(0), _maxCapacity(maxCapacity) { }

    FlowEdge(Vertex *from, Vertex *to, const int &minCapacity, const int &maxCapacity);

    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &minCapacity, const int &maxCapacity);

    FlowEdge(Vertex *from, Vertex *to, const double weight, const int &minCapacity, const int &maxCapacity);

    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &minCapacity, const int &maxCapacity);

    FlowEdge(const FlowEdge &e)
            : DiEdgeCommon(e), _minCapacity(e._minCapacity), _maxCapacity(e._maxCapacity) { }

    string toString() const;

    // Getters
    int minCapacity() const;
    int maxCapacity() const;

    // Setters
    void setMinCapacity(const int m);
    void setMaxCapacity(const int m);
};


#endif //GRAPH_FLOWEDGE_H
