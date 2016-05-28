/*! \brief Common class for directed edges
 *
 * \file DiEdgeCommon.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "DiEdgeCommon.h"

Vertex* DiEdgeCommon::from() const
{
    return _a;
}

Vertex* DiEdgeCommon::to() const
{
    return _b;
}

string DiEdgeCommon::edgeStyle() const
{
    return "->";
}

Vertex *DiEdgeCommon::either() const
{
    return from();
}

Vertex *DiEdgeCommon::other(Vertex *) const
{
    return to();
}