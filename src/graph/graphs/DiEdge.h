/*! \brief Class DiEdge
 *
 * \file DiEdge.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef SRC_DiEdge_H
#define SRC_DiEdge_H

#include "DiEdgeCommon.h"

/*! \brief Class manipulating directed edges
 */
class DiEdge : public DiEdgeCommon
{
public:
    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     */
    DiEdge(Vertex *from, Vertex *to)
        : DiEdgeCommon(from, to) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     */
    DiEdge(Vertex *from, Vertex *to, const double weight)
        : DiEdgeCommon(from, to,  weight) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     */
    DiEdge(Vertex *from, Vertex *to, const string &label)
            : DiEdgeCommon(from, to, label) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     */
    DiEdge(Vertex *from, Vertex *to, const string label, const double weight)
        : DiEdgeCommon(from, to, label, weight) {}

    /*! \brief Copy constructor
     */
    DiEdge(const DiEdge& e) : DiEdgeCommon(e) {}

    /*! \brief Destructor
     */
    virtual ~DiEdge() {}

    string toString() const;
};

#endif //SRC_DiEdge_H