/*! \brief Interface for edges manipulation
 *
 * \file IEdge.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_COMMONEDGE_H
#define GRAPH_COMMONEDGE_H

#include <string>
#include "Vertex.h"

/*! \brief Global interface to manipulate all types of edges
 */
class IEdge
{
protected:
    /*! \brief Defines de visual style of an edge
     *
     *  \return a string representation of an edge
     */
    virtual string edgeStyle() const = 0;
public:

    /*! \brief Destructor
     */
    virtual ~IEdge() {}

    /*!
     * \return a stringify representation of an edge
     */
    virtual string toString() const = 0;

    /*!
     * \return one of the two vertices of an edge
     */
    virtual Vertex* either() const = 0;

    /*!
     * \param v - The vertex already found
     *
     * \return the other vertex of the edge from which passed in parameter
     */
    virtual Vertex* other(Vertex *v) const = 0;

    /*!
     * \return the source vertex of the edge
     */
    virtual Vertex* from() const = 0;

    /*!
     * \return the destination vertex of the edge
     */
    virtual Vertex* to() const = 0;

    /*!
     * \return the id of the edge
     */
    virtual int id() const = 0;

    /*!
     * \return the label of the edge
     */
    virtual string label() const = 0;

    /*!
     * \return the weight of the edge
     */
    virtual double weight() const = 0;

    /*! \brief Set the id of the edge
     *
     * \param id - The id to give to the edge
     */

    virtual void setId(int id) = 0;
    /*! \brief Set vertex a of the edge
     *
     * \param v - The vertex to give to the edge
     */

    virtual void setA(Vertex *v) = 0;

    /*! \brief Set vertex b of the edge
     *
     * \param v - The vertex to give to the edge
     */
    virtual void setB(Vertex *v) = 0;

    /*! \brief Change the label of the edge
     *
     * \param label - The new label to give to the edge
     */
    virtual void setLabel(const string &label) = 0;

    /*! \brief Change the weight of the edge
     *
     * \param weight - The new weight to give to the edge
     */
    virtual void setWeight(double weight) = 0;

    // Overloaded operators
    inline bool operator< (const IEdge& e) const { return weight() < e.weight(); }
    inline bool operator> (const IEdge& e) const { return e < *this; }
    inline bool operator<=(const IEdge& e) const { return !(*this > e); }
    inline bool operator>=(const IEdge& e) const { return !(*this < e); }

    inline bool operator< (const IEdge* e) const { return weight() < e->weight(); }
    inline bool operator> (const IEdge* e) const { return e < this; }
    inline bool operator<=(const IEdge* e) const { return !(this > e); }
    inline bool operator>=(const IEdge* e) const { return !(this < e); }

    /*! brief Overload of ostream operator to display an endge in the console
     */
    friend ostream& operator<<(ostream& os, const IEdge& e) {
        return os << e.toString();
    }
};


#endif //GRAPH_COMMONEDGE_H
