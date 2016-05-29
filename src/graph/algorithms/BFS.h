/*! \brief Breadth First Search's algorithm
 *
 * \file BFS.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_BFS_H
#define GRAPH_BFS_H

#include "../graphs/IGraph.h"
#include "Visitor.h"
#include <vector>

/*! \brief BFS' algorithm searches the tree where all vertices are reached from
 * a source vertex
 */
class BFS : public Visitor
{
private:
    // Vector of distances. The value is the number of Edges from the source
    // vertex. Where the value is 0 means that it's the source vertex.
    vector<double> _distances;
    IGraph *_G;

    /*! \brief Common method for code factoring
     *
     * \param g - The templated graph
     * \param from - The source vertex
     */
    template <typename T>
    void common(T *g, Vertex *from);

public:
    /*! \brief Constructor
     */
    BFS() : _distances(0), _G(nullptr) {}

    /*! \brief Destructor
     */
    ~BFS() {}

    virtual void visit(Graph *g, Vertex *from, Vertex *to) override;

    virtual void visit(DiGraph *g, Vertex *from, Vertex *to) override;

    virtual void visit(FlowGraph *g, Vertex *from, Vertex *to) override;

    virtual IGraph* G() const override ;

    virtual std::vector<double> table() override;
};


#endif //GRAPH_BFS_H
