/*! \brief Class Edge (for non-directed graphs)
 *
 * \file Edge.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "Edge.h"

Vertex* Edge::either() const
{
    return _a;
}

Vertex* Edge::other(Vertex *v) const
{
    return (v == this->_a) ? this->_b : this->_a;
}

string Edge::toString() const
{
    string s = "(EDGE) ";
    s.append(EdgeCommon::toString());
    return s;
}

ostream &operator<<(ostream &os, const Edge &e)
{
    return os << e.toString();
}

string Edge::edgeStyle() const
{
    return "--";
}

Vertex *Edge::from() const
{
    return either();
}

Vertex *Edge::to() const
{
    return other(either());
}





