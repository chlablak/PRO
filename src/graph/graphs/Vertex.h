/*! \brief Class Vertex representing vertices
 *
 * \file Vertex.h
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include <list>
#include <limits>
#include <iostream>
#include "../../utility/Global.h"

using namespace std;

/*! \brief Class for vertices manipulation
 */
class Vertex
{
private:
    int _id;
    string _label;
    double _weight;
    int _minCapacity;
    int _maxCapacity;

public:
    /*! \brief Constructor
     */
    Vertex() : _id(-1), _label(""), _weight(numeric_limits<double>::max()),
               _minCapacity(-1), _maxCapacity(-1) {}

    /*! \brief Constructor
     *
     * \param label - The name of the vertex
     */
    Vertex(const string& label)
            : _id(-1), _label(label), _weight(numeric_limits<double>::max()),
              _minCapacity(-1), _maxCapacity(-1) {}

    /*! \brief Constructor
     *
     * \param weight - The weight of the vertex
     */
    Vertex(const double& weight)
            : _id(-1), _label(""), _weight(weight),
              _minCapacity(-1), _maxCapacity(-1) {}

    /*! \brief Constructor
     *
     * \param weight - The weight of the vertex
     * \param label - The name of the vertex
     */
    Vertex(const double& weight, const string& label)
            : _id(-1), _label(label), _weight(weight),
              _minCapacity(-1), _maxCapacity(-1) {}

    /*! \brief Constructor
     *
     * \param maxCapacity - The max capacity of the vertex
     */
    Vertex(const int& maxCapacity)
            : _id(-1), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(0), _maxCapacity(maxCapacity) {}

    /*! \brief Constructor
     *
     * \param minCapacity - The min capacity of the vertex
     * \param maxCapacity - The max capacity of the vertex
     */
    Vertex(const int& minCapacity, const int& maxCapacity)
            : _id(-1), _label(""), _weight(numeric_limits<double>::max()),
              _minCapacity(minCapacity), _maxCapacity(maxCapacity) {}

    /*! \brief Constructor
     *
     * \param weight - The weight of the vertex
     * \param maxCapacity - The max capacity of the vertex
     */
    Vertex(const double& weight, const int& maxCapacity)
            : _id(-1), _label(""), _weight(weight),
              _minCapacity(0), _maxCapacity(maxCapacity) {}

    /*! \brief Constructor
     *
     * \param weight - The weight of the vertex
     * \param label - The name of the vertex
     * \param minCapacity - The min capacity of the vertex
     * \param maxCapacity - The max capacity of the vertex
     */
    Vertex(const double& weight, const string& label,
           const int& minCapacity, const int& maxCapacity)
            : _id(-1), _label(label), _weight(weight),
              _minCapacity(minCapacity), _maxCapacity(maxCapacity) {}

    /*! \brief Copy constructor
     */
    Vertex(const Vertex &v)
            : _id(v.id()), _label(v.label()), _weight(v.weight()),
              _minCapacity(v.minCapacity()), _maxCapacity(v.maxCapacity()) {}

    /*! \brief Destructor
     */
    ~Vertex() {}

    /*! \return a string representation of the vertex
     */
    string toString() const;

    /*! \return the id of the vertex
     */
    int id() const;

    /*! \return the name of the vertex
     */
    string label() const;

    /*! \return the weight of the vertex
     */
    double weight() const;

    /*! \return the min capacity of the vertex
     */
    int minCapacity() const;

    /*! \return the max capacity of the vertex
     */
    int maxCapacity() const;

    /*! \brief set the id of the vertex
     *
     * \param i - The id to give to the vertex
     */
    void setId(const int i);

    /*! \brief set name id of the vertex
     *
     * \param s - The name to give to the vertex
     */
    void setLabel(const string& s);

    /*! \brief set the weight of the vertex
     *
     * \param w - The weight to give to the vertex
     */
    void setWeight(const double w);

    /*! \brief set the min capacity of the vertex
     *
     * \param minCap - The min capacity to give to the vertex
     */
    void setMinCapacity(const int minCap);

    /*! \brief set the max capacity of the vertex
     *
     * \param maxCap - The max capacity to give to the vertex
     */
    void setMaxCapacity(const int maxCap);

    /*! \brief Overload stream operator to display Vertex in the console
     *
     * \param os - The stream
     * \param v - The vertex to display
     */
    friend ostream& operator<<(ostream& os, const Vertex& v);

    // Overloaded operators
    bool operator == (const Vertex &v) const{
        return _id == v._id;
    }
    bool operator == (const Vertex *v) const{
        return _id == v->_id;
    }
    bool operator != (const Vertex &v) const{
        return _id != v._id;
    }
    bool operator != (const Vertex *v) const{
        return _id != v->_id;
    }
};

#endif //GRAPH_VERTEX_H