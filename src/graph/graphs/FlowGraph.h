/*! \brief Class FlowGraph (manipulate FlowEdge)
 *
 * \file FlowGraph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_FLOWGRAPH_H
#define GRAPH_FLOWGRAPH_H

#include "DiGraphCommon.h"
#include "FlowEdge.h"

/*! \brief Class manipulating directed flowed graphs with flow edges
 */
class FlowGraph : public DiGraphCommon<FlowEdge>
{
public:
    /*! \brief Empty constructor
     */
    FlowGraph() : DiGraphCommon() {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     */
    FlowGraph(vector<Vertex *> &vertices) : DiGraphCommon(vertices) {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     * \param edges - The edges to assign to the graph
     */
    FlowGraph(vector<Vertex*> &vertices, vector<IEdge*> &edges)
            : DiGraphCommon(vertices, edges) {}

    /*! \brief Copy constructor
     *
     * \param g - The graph to copy
     */
    FlowGraph(const FlowGraph& dg);

    /*! \brief Destructor
     */
    virtual ~FlowGraph() {}

    virtual bool isConnected() const override;

    virtual bool isStronglyConnected() const override;

    virtual FlowGraph *clone() const override;

    virtual IGraph *emptyClone() const override;

    virtual bool hasPositiveCapacity() const;

    virtual void accept(Visitor *v, Vertex *from, Vertex *to) override;

    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;
};


#endif //GRAPH_FLOWGRAPH_H