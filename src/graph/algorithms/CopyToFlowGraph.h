/*! \brief Copy any type of graph into a new flow graph
 *
 * \file CopyToFlowGraph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_COPYTOFLOWGRAPH_H
#define GRAPH_COPYTOFLOWGRAPH_H

#include "Visitor.h"

/*! \brief Copy any type of graph into a new flow graph
 */
class CopyToFlowGraph : public Visitor
{
private:
    IGraph *_G;

public:
    /*! \brief Constructor
     */
    CopyToFlowGraph() : _G(nullptr) {}

    /*! \brief Destructor
     */
    ~CopyToFlowGraph() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception because there is no returned table possible
     * for this algorithm
     */
    virtual std::vector<double> table() override;
};


#endif //GRAPH_COPYTOFLOWGRAPH_H
