/*! \brief Algorithm to find minimum spanning tree
 *
 * \file Kruskal.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_KURSKAL_H
#define GRAPH_KURSKAL_H


#include <queue>
#include "Visitor.h"
#include "../graphs/Edge.h"

/*! \brief Kruskal of version of MST's algorithm
 */
class Kruskal : public Visitor
{
private:
    typedef priority_queue<IEdge*, vector<IEdge*>, std::greater<IEdge*>> MinPQ;

    IGraph *_G;
public:
    /*! \brief Constructor
     */
    Kruskal() : _G(nullptr) {}

    /*! \brief Destructor
     */
    ~Kruskal() {}

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception if g is not connected, not weighted, or
     * not simple
     */
    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception because this algorithm can't be applied
     * to directed graph
     * TODO vérifier
     */
    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception because this algorithm can't be applied
     * to directed graph
     * TODO vérifier
     */
    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception because there is no returned table possible
     * for this algorithm
     */
    virtual std::vector<double> table() override;
};


#endif //GRAPH_KURSKAL_H
