/*! \brief Common class for graphs
 *
 * \file GraphCommon.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "EdgeCommon.h"
#include "../../utility/Global.h"

EdgeCommon::EdgeCommon(const EdgeCommon& e)
{
    _id = e.id();
    _a = e._a; // Superficial copy
    _b = e._b; // Superficial copy
    _label = e.label();
    _weight = e.weight();
}

int EdgeCommon::id() const
{
    return _id;
}

string EdgeCommon::label() const
{
    return _label;
}

double EdgeCommon::weight() const
{
    return _weight;
}

void EdgeCommon::setId(int id)
{
    _id = id;
}

void EdgeCommon::setA(Vertex *v)
{
    _a = v;
}

void EdgeCommon::setB(Vertex *v)
{
    _b = v;
}

void EdgeCommon::setLabel(const string &label)
{
    _label = label;
}

void EdgeCommon::setWeight(double weight)
{
    _weight = weight;
}

string EdgeCommon::toString() const
{
    string s;
    s.append(from()->label());
    s.append("(");
    s.append(utility::toString(from()->id()));
    s.append(") ");
    s.append(edgeStyle());
    s.append(" (");
    s.append(utility::toString(to()->id()));
    s.append(")");
    s.append(to()->label());
    s.append(" id: ");
    s.append(utility::toString(id()));
    s.append(", \"");
    s.append(label());
    s.append("\", weight: ");
    s.append(utility::toString(weight()));

    return s;
}

ostream &operator<<(ostream &os, const EdgeCommon &e)
{
    return os << e.toString();
}