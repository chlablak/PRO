/*! \brief Copy any type of graph into a new non-directed graph
 *
 * \file CopyToGraph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_COPYTOGRAPH_H
#define GRAPH_COPYTOGRAPH_H


#include "Visitor.h"

/*! \brief Copy any type of graph into a new non-directed graph
 */
class CopyToGraph : public Visitor
{
private:
    IGraph *_G;

    /*! \brief Common method for code factoring
     *
     * \param g - The templated graph
     * \param e - The templated edge
     */
    template <typename T, typename U>
    void common(T *g, U *e);
public:
    /*! \brief Constructor
     */
    CopyToGraph() : _G(nullptr) {}

    /*! \brief Destructor
     */
    ~CopyToGraph() {}

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


#endif //GRAPH_COPYTOGRAPH_H