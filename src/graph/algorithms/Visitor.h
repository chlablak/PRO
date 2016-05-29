/*! \brief interface for visiting graphs
 *
 * \file Visitor.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_VISITOR_H
#define GRAPH_VISITOR_H

#include <vector>
#include "../graphs/Vertex.h"

class IGraph;
class Vertex;
class Graph;
class DiGraph;
class FlowGraph;

/*! \brief This interface will be implemented by algorithms for visit graphs
 */
class Visitor
{
public:
    /*! \brief Constructor
     */
    Visitor() {}

    /* \brief Destructor
     */
    virtual ~Visitor() {}

    /* \brief Visit a non directed graph
     *
     * \param g - The graph to visit
     * \param from - The source vertex from where the visitor can start
     * \param to - The destination vertex to where the visitor can end
     */
    virtual void visit(Graph *g, Vertex *from = nullptr, Vertex *to = nullptr) = 0;

    /* \brief Visit a directed graph
     *
     * \param g - The graph to visit
     * \param from - The source vertex from where the visitor can start
     * \param to - The destination vertex to where the visitor can end
     */
    virtual void visit(DiGraph *g, Vertex *from = nullptr, Vertex *to = nullptr) = 0;

    /* \brief Visit a flow directed graph
     *
     * \param g - The graph to visit
     * \param from - The source vertex from where the visitor can start
     * \param to - The destination vertex to where the visitor can end
     */
    virtual void visit(FlowGraph *g, Vertex *from = nullptr, Vertex *to = nullptr) = 0;

    /*! \return the resulting graph obtained by the specific visitor. If no
     *  graph is returned, throws a runtime_error() exception
     */
    virtual IGraph* G() const = 0;

    /*! \return the resulting table obtained by the specific visitor. If no
     *  table is returned, throws a runtime_error() exception
     */
    virtual std::vector<double> table() = 0;
};


#endif //GRAPH_VISITOR_H
