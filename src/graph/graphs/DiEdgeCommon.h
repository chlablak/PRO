/*! \brief Common class for directed edges
 *
 * \file DiEdgeCommon.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_DIEDGECOMMON_H
#define GRAPH_DIEDGECOMMON_H

#include "EdgeCommon.h"

/*! \brief Common directed edge class for code factoring
 */
class DiEdgeCommon : public EdgeCommon
{
protected:
    virtual string edgeStyle() const override;

public:
    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     */
    DiEdgeCommon(Vertex *from, Vertex *to)
            : EdgeCommon(from, to) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     */
    DiEdgeCommon(Vertex *from, Vertex *to, const double weight)
            : EdgeCommon(from, to,  weight) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     */
    DiEdgeCommon(Vertex *from, Vertex *to, const string &label)
            : EdgeCommon(from, to, label) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     */
    DiEdgeCommon(Vertex *from, Vertex *to, const string label, const double weight)
            : EdgeCommon(from, to, label, weight){}

    /*! \brief Copy constructor
     */
    DiEdgeCommon(const DiEdgeCommon &e) : EdgeCommon(e) {}

    /*! \brief Destructor
     */
    virtual ~DiEdgeCommon() {}

    Vertex *from() const override;

    Vertex *to() const override;

    virtual Vertex *either() const override;

    virtual Vertex *other(Vertex *v) const override;
};


#endif //GRAPH_DIEDGECOMMON_H
