/*! \brief Dijkstra's algorithm to find shortest path in a graph
 *
 * \file Dijkstra.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DIJKSTRA_H
#define GRAPH_DIJKSTRA_H


#include "Visitor.h"
#include "../graphs/IGraph.h"
#include <set>

/*! \brief Dijkstra's algorithm finds the shortest path in a graph from a source
 * Vertex to all reachable vertices from this source
 */
class DijkstraSP : public Visitor
{
private:
    IGraph *_G;
    std::vector<IEdge*> _edgeTo;
    std::vector<double> _distanceTo;
    std::vector<bool> _marques;

    typedef std::pair<double, Vertex*> WeightVertex;
    // Priority queue containing the weight of edges and the vertices
    std::set<WeightVertex> _pq;

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
     * \throw runtime_error Exception if g is not weighted or negatively weighted
     */
    template <typename T, typename U>
    void sp(T *g, U *e, Vertex *from);

public:
    /*! \brief Costructor
     */
    DijkstraSP() : _G(nullptr), _edgeTo(0), _distanceTo(0), _marques(0), _pq() {}

    /*! \brief Destructor
     */
    virtual ~DijkstraSP() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_DIJKSTRA_H
