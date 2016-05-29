/*! \brief Common class for directed graphs
 *
 * \file DiGraphCommon.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DIGRAPHCOMMON_H
#define GRAPH_DIGRAPHCOMMON_H

#include "GraphCommon.h"
#include "DiEdgeCommon.h"

/*! \brief Common directed graph class for code factoring
 */
template <typename T> // can be either DiEdge or FlowEdge
class DiGraphCommon : public GraphCommon<T> {
public:

    /*! \brief Empty Constructor
     */
    DiGraphCommon() : GraphCommon<T>::GraphCommon() {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     */
    DiGraphCommon(vector<Vertex *> &vertices)
            : GraphCommon<T>::GraphCommon(vertices) {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     * \param edges - The edges to assign to the graph
     */
    DiGraphCommon(vector<Vertex*> &vertices, vector<IEdge*> &edges);

    /*! \brief Copy constructor
     *
     * \param g - The graph to copy
     */
    DiGraphCommon(const DiGraphCommon& g);

    /*! \brief Destructor
     */
    virtual ~DiGraphCommon() {}

    virtual bool isSimple() const override;

    virtual bool isDirected() const override;

    virtual void removeVertex(Vertex *v) override;

    virtual void removeEdge(IEdge *e) override;

    virtual void addEdge(IEdge *e) override;

    virtual void assignEdge(IEdge *ie) override;

    virtual IGraph::Edges getEdges(Vertex *v1, Vertex *v2) const override;

    /*! \brief Apply a function to each predecessor vertices of v
     *
     * \param v - The source vertex
     * \param f - Function to apply
     */
    template <typename Func>
    void forEachPredecessor(Vertex *v, Func f)
    {
        for (IEdge *e : this->edgeList())
            if (e->to() == v)
                f(e->from());
    }

    /*! \brief Apply a function to each successor vertices of v
     *
     * \param v - The source vertex
     * \param f - Function to apply
     */
    template <typename Func>
    void forEachSuccessor(Vertex *v, Func f)
    {
        vector<IGraph::Edges> adj = this->adjacentList();
        for (IEdge *ie : adj.at(v->id()))
            f(ie->to());
    }

};

#include "DiGraphCommon.hpp"

#endif //GRAPH_DIGRAPHCOMMON_H
