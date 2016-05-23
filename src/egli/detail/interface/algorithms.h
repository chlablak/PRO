/*! \brief Algorithms functions to interface
 *
 * \file algorithms.h
 * \author Patrick Champion
 * \date 03.05.2016
 */

#ifndef EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED
#define EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED

#include "../RealType.h"
#include "../../Type.h"

namespace egli
{
namespace detail
{
namespace algorithms
{
RealType<Type::Array>::type
    bfs(RealType<Type::Graph>::cref g, RealType<Type::Integer>::cref from);
} // namespace algorithms
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED
