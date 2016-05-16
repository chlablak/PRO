//
// Created by sebri on 16.05.2016.
//

#ifndef GRAPH_KURSKAL_H
#define GRAPH_KURSKAL_H


#include "../visitors/Visitor.h"

class Kurskal : public Visitor
{
private:
    
public:
    virtual void visit(Graph *g, Vertex *from);
    virtual void visit(DiGraph *g, Vertex *from);
    virtual void visit(FlowGraph *g, Vertex *from);
    virtual IGraph *G() const override;
    virtual std::vector<int> &table() override;
};


#endif //GRAPH_KURSKAL_H
