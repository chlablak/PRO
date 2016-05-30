/*! \brief Apply a topological sort algorithm
 *
 * \file TopologicalSort.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_TOPOLOGICALSORT_H
#define GRAPH_TOPOLOGICALSORT_H


#include "Visitor.h"
#include "../graphs/Vertex.h"
#include "../graphs/IGraph.h"

/*! \brief search the topologique order of an acyclique digraph or flowgraph by using topological sort algorithm
 */
class TopologicalSort : public Visitor
{
private:
    vector<list<Vertex*>> _predessessorsList;
    vector<double > _order;
    IGraph *_G;

    /*! \brief Determine weither a graph is acyclique
     *
     * \param g - The graph on which to check if it contains a cycle
     * return bool true if the graph is acyclique
     */
    bool isDAG(IGraph *g) const;

    /*! \brief fill the _prdessessortList attribute that contain the predessessor of each vertex of the graph
     *
     * \param g - The graph on which make the predessessor list
     */
    void fillPredessessors(IGraph *g);

    /*! \brief apply the topological sort algorithm to search a topological order
     *
     * \param g - The graph on which to search the topological order
     */
    void order(IGraph *g);

public:
    /*! \brief Constructor
     */
    TopologicalSort(): _predessessorsList(0), _order(0), _G(nullptr) {}

    /*! \brief Destructor
     */
    virtual ~TopologicalSort() override {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override ;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override ;

    virtual std::vector<double> table() override ;
};


#endif //GRAPH_TOPOLOGICALSORT_H
