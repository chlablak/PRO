/*! \brief Copy any type of graph into a new directed graph
 *
 * \file CopyToDiGraph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_COPYTODIGRAPH_H
#define GRAPH_COPYTODIGRAPH_H

#include "Visitor.h"
#include "../graphs/DiGraph.h"

/*! \brief Copy any type of graph into a new directed graph
 */
class CopyToDiGraph : public Visitor
{
private:
    IGraph *_G;

public:
    /*! \brief Constructor
     */
    CopyToDiGraph() : _G(nullptr) {}

    /*! \brief Destructor
     */
    ~CopyToDiGraph() {}

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


#endif //GRAPH_COPYTODIGRAPH_H
