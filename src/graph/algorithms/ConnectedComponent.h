/*! \brief Connected Component algorithm
 *
 * \file ConnectedComponent.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_CONNECTEDCOMPONENT_H
#define GRAPH_CONNECTEDCOMPONENT_H

#include "Visitor.h"
#include "../graphs/IGraph.h"

/*! \brief Search Connected Components into any type of graph
 */
class ConnectedComponent : public Visitor
{
private:
    // Table containing the number of the connected component associated
    // for each vertex of the graph
    std::vector<double> _cc;

public:
    /*! \brief Constructor
     */
    ConnectedComponent() : _cc(0) {}

    /*! \brief Destructor
     */
    ~ConnectedComponent() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_CONNECTEDCOMPONENT_H
