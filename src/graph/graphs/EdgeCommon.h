//
// Created by sebri on 20.05.2016.
//

#ifndef GRAPH_EDGECOMMON_H
#define GRAPH_EDGECOMMON_H


#include "IEdge.h"

class EdgeCommon : public IEdge {

protected:
    int _id;
    Vertex *_a;
    Vertex *_b;
    string _label;
    double _weight;

public:
    EdgeCommon(Vertex *from, Vertex *to)
        : _id(-1), _a(from), _b(to), _label(""), _weight(1) {}
    EdgeCommon(Vertex *from, Vertex *to, const double weight)
        : _id(-1), _a(from), _b(to), _label(""), _weight(weight) {}
    EdgeCommon(Vertex *from, Vertex *to, const string& label)
        : _id(-1), _a(from), _b(to), _label(label), _weight(1) {}
    EdgeCommon(Vertex *from, Vertex *to, const string& label, const double weight)
        : _id(-1), _a(from), _b(to), _label(label), _weight(weight) {}

    ~EdgeCommon() { }

    EdgeCommon(const EdgeCommon& e);

    virtual string toString() const override;
    virtual int id() const override;
    virtual string label() const override;
    virtual double weight() const override;
    virtual void setId(int _id) override;
    virtual void setA(Vertex *v) override;
    virtual void setB(Vertex *v) override;
    virtual void setLabel(const string &label) override;
    virtual void setWeight(double weight) override;

    EdgeCommon& operator=(const EdgeCommon& e);
};


#endif //GRAPH_EDGECOMMON_H
