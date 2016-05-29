/*! \brief Class DiEdge
 *
 * \file DiEdge.cpp
 * \author Sébastien Richoz & Patrick Djomo
 * \date spring 2016
 */

#include "DiEdge.h"

string DiEdge::toString() const
{
    string s = "(DI EDGE) ";
    s.append(EdgeCommon::toString());
    return s;
}