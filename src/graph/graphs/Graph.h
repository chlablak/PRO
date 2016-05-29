/*! \brief Class Graph (manipulate Edge)
 *
 * \file Graph.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <vector>
#include "GraphCommon.h"
#include "Edge.h"
#include "../../utility/Global.h"

/*! \brief Class to manipulate non directed graphs with Edge type
 */
class Graph : public GraphCommon<Edge>
{
public:
    /*! \brief Empty constructor
     */
    Graph() : GraphCommon() {}

    /*! \brief Copy constructor
     *
     * \param g - The graph to copy
     */
    Graph(const Graph &g);

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     */
    Graph(vector<Vertex*> &vertices) : GraphCommon(vertices) {}

    /*! \brief Constructor
     *
     * \param vertices - The vertices to assign to the graph
     * \param edges - The edges to assign to the graph
     */
    Graph(vector<Vertex*> &vertices, vector<IEdge*> &edges);

    /*! \brief Destructor
     */
    ~Graph() {}

    virtual bool isSimple() const override;

    virtual bool isStronglyConnected() const override;

    virtual bool isDirected() const override;

    virtual void removeVertex(Vertex *v) override;

    virtual void removeEdge(IEdge *e) override;

    virtual bool isConnected() const override;

    virtual list<IEdge*> getEdges(Vertex *either, Vertex *other) const override;

    virtual Graph* clone() const override;

    virtual Graph *emptyClone() const override;

    virtual void addEdge(IEdge *e) override;

    virtual void assignEdge(IEdge *ie) override;

    virtual IEdge *createEdge(Vertex *v, Vertex *w) const override;

    virtual void accept(Visitor *v, Vertex *from, Vertex *to) override;
};


#endif //GRAPH_GRAPH_H
