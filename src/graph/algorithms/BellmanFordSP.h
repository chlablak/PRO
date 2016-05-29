/*! \brief Bellman-Ford's algorithm to find shortest path in a graph
 *
 * \file BellmanFordSP.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_BELLMANFORD_H
#define GRAPH_BELLMANFORD_H

#include "Visitor.h"
#include "../graphs/IEdge.h"

/*! \brief Bellman-Ford's algorithm finds the shortest path in a graph from a
 * source Vertex to all reachable vertices from this source
 */
class BellmanFordSP : public Visitor
{
private:
    IGraph *_G;
    std::vector<IEdge*> _edgeTo;
    std::vector<double> _distanceTo;

    /*! \brief Relax an edge
     *
     * \param ie - The edge to relax
     */
    void relax(IEdge *ie);

    /*! \brief Common method for code factoring
     *
     * \param g - The graph
     * \param e - The edge
     *
     * \throw runtime_error Exception if g is not weighted
     */
    template <typename T, typename U>
    void sp(T *g, U *e, Vertex *from);

public:
    /*! \brief Constructor
     */
    BellmanFordSP() : _G(nullptr), _edgeTo(0), _distanceTo(0) {}

    /*! \brief Destructor
     */
    virtual ~BellmanFordSP() override {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_BELLMANFORD_H
