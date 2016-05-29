/*! \brief Class FlowEdge
 *
 * \file FlowEdge.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_FLOWEDGE_H
#define GRAPH_FLOWEDGE_H

#include "DiEdgeCommon.h"

/*! \brief Class manipulating directed flowed edges
 */
class FlowEdge : public DiEdgeCommon
{
private :
    int _minCapacity;
    int _maxCapacity;
    int _flow;

    /*! \brief Check capacity and set it
     *
     * \param minCapacity - The min capacity of the edge
     * \param maxCapacity - The max capacity of the edge
     */
    void setCapacity(const int minCapacity, const int maxCapacity);

public:
    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     */
    FlowEdge(Vertex *from, Vertex *to)
            : DiEdgeCommon(from, to), _minCapacity(-1), _maxCapacity(-1), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const double weight)
            : DiEdgeCommon(from, to, weight), _minCapacity(-1), _maxCapacity(-1), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string& label)
            : DiEdgeCommon(from, to, label), _minCapacity(-1), _maxCapacity(-1), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const int maxCapacity)
            : DiEdgeCommon(from, to), _minCapacity(0), _maxCapacity(maxCapacity), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &maxCapacity)
            : DiEdgeCommon(from, to, label), _minCapacity(0), _maxCapacity(maxCapacity), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(-1), _maxCapacity(-1), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const double weight ,const int &maxCapacity)
            : DiEdgeCommon(from, to, weight), _minCapacity(0), _maxCapacity(maxCapacity), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &maxCapacity)
            : DiEdgeCommon(from, to, label, weight), _minCapacity(0), _maxCapacity(maxCapacity), _flow(0) {}

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     * \param minCapacity - The min capacity accepted on the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const int &minCapacity, const int &maxCapacity);

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     * \param minCapacity - The min capacity accepted on the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string &label, const int &minCapacity, const int &maxCapacity);

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param weight - The weight of the edge
     * \param minCapacity - The min capacity accepted on the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const double weight, const int &minCapacity, const int &maxCapacity);

    /*! \brief Constructor
     *
     * \param from - The source vertex
     * \param to - The destination vertex
     * \param label - The name of the edge
     * \param weight - The weight of the edge
     * \param minCapacity - The min capacity accepted on the edge
     * \param maxCapacity - The max capacity accepted on the edge
     */
    FlowEdge(Vertex *from, Vertex *to, const string &label, const double weight, const int &minCapacity, const int &maxCapacity);

    /*! \brief Copy constructor
     */
    FlowEdge(const FlowEdge &e)
            : DiEdgeCommon(e), _minCapacity(e._minCapacity), _maxCapacity(e._maxCapacity) {}

    string toString() const override;

    /*! \return the min capacity of the edge
     */
    int minCapacity() const;

    /*! \return the max capacity of the edge
     */
    int maxCapacity() const;

    /*! \return the current flow of the edge
     */
    int flow() const;

    /*! \brief set the min capacity of the edge
     *
     * \param m - The capacity to assign
     */
    void setMinCapacity(const int m);

    /*! \brief set the max capacity of the edge
     *
     * \param m - The capacity to assign
     */
    void setMaxCapacity(const int m);

    /*! \brief set the current flow of the edge
     *
     * \param f - The flow to assign
     */
    void setFlow(const int f);
};

#endif //GRAPH_FLOWEDGE_H