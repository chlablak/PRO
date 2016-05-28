/*! \brief Class Edge (for non-directed graphs)
 *
 * \file Edge.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>
#include <iostream>
#include "Vertex.h"
#include "IEdge.h"
#include "EdgeCommon.h"

using namespace std;

/*! \brief Class to manipulate non directed edges
 */
class Edge : public EdgeCommon
{
protected:
    virtual string edgeStyle() const override;

public:
    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     */
    Edge(Vertex *from, Vertex *to)
            : EdgeCommon(from, to) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     */
    Edge(Vertex *from, Vertex *to, const double weight)
            : EdgeCommon(from, to, weight) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     */
    Edge(Vertex *from, Vertex *to, const string &label)
            : EdgeCommon(from, to, label) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     */
    Edge(Vertex *from, Vertex *to, const string &label, const double weight)
            : EdgeCommon(from, to, label, weight) {}

    /*! \brief Copy constructor
     */
    Edge(const Edge &e) : EdgeCommon(e) {}

    /*! \brief Destructor
     */
    virtual ~Edge() {}

    Vertex* either() const override;

    Vertex* other(Vertex *v) const override;

    virtual Vertex *from() const override;

    virtual Vertex *to() const override;

    string toString() const override;

    /*! \brief Overload stream operator to display an Edge in the console
     */
    friend ostream& operator<<(ostream& os, const Edge& e);
};

#endif //GRAPH_EDGE_H