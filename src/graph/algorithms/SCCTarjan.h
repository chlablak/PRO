/*! \brief Strongly Connected Component algorithm
 *
 * \file SCCTarjan.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_STRONGLYCONNECTEDCOMPONENT_H
#define GRAPH_STRONGLYCONNECTEDCOMPONENT_H


#include "Visitor.h"
#include "../graphs/Vertex.h"
#include "../graphs/DiGraph.h"
#include <stack>

/*! \brief Tarjan's version of algorithm to find strongly connected components
 * in a graph
 */
class SCCTarjan : public Visitor
{
private:
    std::vector<double> _scc;
    std::vector<int> _dfsnum;
    std::vector<int> _low;
    int _N; // counter for dfsnum numbering
    int _K; // counter for components numbering
    stack<Vertex*> _P; // stack containing the visited vertices

    /*! \brief Procedure to find scc
     *
     * \param u - The source vertex
     * \param g - The directed graph on which to work
     */
    void SCC(Vertex *u, DiGraph *g);

public:

    /*! \brief Constructor
     */
    SCCTarjan() : _scc(0), _dfsnum(0), _low(0), _N(0), _K(0), _P() { }

    /*! \brief Destructor
     */
    ~SCCTarjan() {}

    /*! \brief Override method from Visitor interface
     *
     * \throw runtime_error Exception if applied to a non-directed graph
     */
    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_STRONGLYCONNECTEDCOMPONENT_H
