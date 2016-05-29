/*! \brief Class DiGraph (manipulate DiEdge)
 *
 * \file DiGraph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DIGRAPH_H
#define GRAPH_DIGRAPH_H

#include "GraphCommon.h"
#include "DiEdge.h"
#include "DiGraphCommon.h"

/*! \brief Class manipulating directed graphs with directed edges
 */
class DiGraph : public DiGraphCommon<DiEdge>
{
public:
    /*! \brief Empty constructor
     */
    DiGraph() : DiGraphCommon() {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     */
    DiGraph(vector<Vertex *> &vertices) : DiGraphCommon(vertices) {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     * \param edges - The edges to assign to the graph
     */
    DiGraph(vector<Vertex*> &vertices, vector<IEdge*> &edges) : DiGraphCommon(vertices, edges) {}

    /*! \brief Copy constructor
     *
     * \param g - The graph to copy
     */
    DiGraph(const DiGraph& dg);

    /*! \brief Destructor
     */
    virtual ~DiGraph() {}

    virtual bool isConnected() const override;

    virtual bool isStronglyConnected() const override;

    virtual DiGraph *clone() const override;

    virtual IGraph *emptyClone() const override;

    virtual void accept(Visitor *v, Vertex *from, Vertex *to) override;

    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;
};

#endif //GRAPH_DIGRAPH_H