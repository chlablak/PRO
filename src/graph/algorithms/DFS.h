/*! \brief Depth First Search's algorithm
 *
 * \file DFS.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DFS_H
#define GRAPH_DFS_H


#include "Visitor.h"
#include "../graphs/Graph.h"
#include "../graphs/DiGraph.h"
#include "../graphs/FlowGraph.h"

/*! \brief DFS' algorithm find a tree of all reachable vertices from a source
 * vertex
 */
class DFS : public Visitor
{
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<double> _dfsnum;
    int N;
    IGraph *_G;

    /*! \brief Procedure DFS for non directed graphs
     *
     * \param g - The graph on which to apply the procedure
     * \param u - The vertex from where to apply the procedure
     */
    void DFSprocedure(Graph *g, Vertex *u);

    /*! \brief Procedure DFS for directed graphs
     *
     * \param g - The graph on which to apply the procedure
     * \param u - The vertex from where to apply the procedure
     * \param begin - Table containing date of discovery
     * \param end - Table containing date of recovery
     * \param date - The date stipulates when the vertex was visited
     */
    template <typename T>
    void DFSprocedure(T *g, Vertex *u, vector<int> &begin, vector<int> &end, int date);

    /*! \brief Templated method for code factoring for directed graphs
     *
     * \param g - The templated graph
     * \param from - The vertex
     */
    template <typename T>
    void common(T *g, Vertex *from);

public:
    /*! \brief Constructor
     */
    DFS() : _dfsnum(0), N(0), _G(nullptr) {}

    /*! \brief Destructor
     */
    ~DFS() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph *G() const override;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_DFS_H
